
#include <stdio.h>
#include <stdint.h>

#include <stdio.h>
#include <stdint.h>
int main(int argc, char *argv[]) {
    int a;
    char b;
    float c;
    double d;
    int8_t e;
    int16_t f;
    int32_t g;
    int64_t h;
    printf("Address of int a: %p, Size: %lu\n", (void*)&a, (unsigned long)(&a+1) - (unsigned long)(&a));
    printf("Address of char b: %p, Size: %lu\n", (void*)&b, (unsigned long)(&b+1) - (unsigned long)(&b));
    printf("Address of float c: %p, Size: %lu\n", (void*)&c, (unsigned long)(&c+1) - (unsigned long)(&c));
    printf("Address of double d: %p, Size: %lu\n", (void*)&d, (unsigned long)(&d+1) - (unsigned long)(&d));
    printf("Address of int8_t e: %p, Size: %lu\n", (void*)&e, (unsigned long)(&e+1) - (unsigned long)(&e));
    printf("Address of int16_t f: %p, Size: %lu\n", (void*)&f, (unsigned long)(&f+1) - (unsigned long)(&f));
    printf("Address of int32_t g: %p, Size: %lu\n", (void*)&g, (unsigned long)(&g+1) - (unsigned long)(&g));
    printf("Address of int64_t h: %p, Size: %lu\n", (void*)&h, (unsigned long)(&h+1) - (unsigned long)(&h));
    return 0;
}
// int main(int argc, char *argv[]) {
//     int a;
//     char b;
//     float c;
//     double d;
//     int8_t e;
//     int16_t f;
//     int32_t g;
//     int64_t h;

//     printf("Size of int: %lu\n", (unsigned long)(&a+1) - (unsigned long)(&a));
//     printf("Size of char: %lu\n", (unsigned long)(&b+1) - (unsigned long)(&b));
//     printf("Size of float: %lu\n", (unsigned long)(&c+1) - (unsigned long)(&c));
//     printf("Size of double: %lu\n", (unsigned long)(&d+1) - (unsigned long)(&d));
//     printf("Size of int8_t: %lu\n", (unsigned long)(&e+1) - (unsigned long)(&e));
//     printf("Size of int16_t: %lu\n", (unsigned long)(&f+1) - (unsigned long)(&f));
//     printf("Size of int32_t: %lu\n", (unsigned long)(&g+1) - (unsigned long)(&g));
//     printf("Size of int64_t: %lu\n", (unsigned long)(&h+1) - (unsigned long)(&h));

//     return 0;
// }
