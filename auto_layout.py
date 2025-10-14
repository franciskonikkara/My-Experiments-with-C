import gdb

print("[+] Starting automated memory analysis...")
gdb.execute("break main")
gdb.execute("run")

print("\n[+] Variable layout:")
for v in ["global_var_1","global_uninit_var_1","local_var_1","ptr_1"]:
    try:
        addr = gdb.parse_and_eval("&"+v)
        print(f"{v:20s} : 0x{int(addr):x}")
    except:
        print(f"{v:20s} : unavailable")

print("\n[+] pwndbg vmmap output:")
gdb.execute("vmmap", to_string=False)
print("\n[+] pwndbg heap info:")
gdb.execute("heap", to_string=False)