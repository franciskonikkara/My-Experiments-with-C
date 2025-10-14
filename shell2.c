
#include <stdio.h>
#include <stdint.h>


unsigned char shellcode[] =
    "\xb8\x01\x00\x00\x00"
    "\xbb\x02\x00\x00\x00"
    "\xcd\x80";

int main(int argc, char **argv)
{
    int (*shell)(void);

    printf("shellcode at: %p\n", (void*)shellcode);

    shell = (int (*)(void))shellcode; 
    return shell(); 

}