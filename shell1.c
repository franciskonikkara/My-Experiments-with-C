#include <stdio.h>
#include <stdint.h>


unsigned char shellcode[] =
    "\xb8\x01\x00\x00\x00"   
    "\xbb\x02\x00\x00\x00"   
    "\xcd\x80";              

int main(int argc, char **argv)
{

    uintptr_t *ret;

    printf("shellcode at: %p\n", (void*)shellcode);

    ret = (uintptr_t *)&ret + 6;   
    *ret = (uintptr_t)shellcode;   

    return 0;  }
