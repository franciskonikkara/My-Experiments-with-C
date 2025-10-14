#include <stdio.h>
#include <malloc.h>
#include <limits.h>

int global_var_1 = 0;
int global_var_2 = INT_MAX;

int global_uninit_var_1;
int global_uninit_var_2;

float global_float = -3.14;

int main() {
    int local_var_1 = 0;
    int local_var_2 = -42;
    float local_float = 1.23;
    int max_int = INT_MAX;

    static int static_var_1 = 0;
    static int static_var_2 = -100;

    int *ptr_1 = malloc(100);
    int *ptr_2 = malloc(100);

    printf("Local var 1 address: %p\n", &local_var_1);
    printf("Local var 2 address: %p\n", &local_var_2);
    printf("Local float address: %p\n", &local_float);
    printf("Max int address: %p\n", &max_int);

    printf("Heap var 1 address: %p\n", ptr_1);
    printf("Heap var 2 address: %p\n", ptr_2);

    printf("Global (uninit) var 1 address: %p\n", &global_uninit_var_1);
    printf("Global (uninit) var 2 address: %p\n", &global_uninit_var_2);

    printf("Static Local var 1 address: %p\n", &static_var_1);
    printf("Static Local var 2 address: %p\n", &static_var_2);

    printf("Global var 1 address: %p\n", &global_var_1);
    printf("Global var 2 (MAX_INT) address: %p\n", &global_var_2);
    printf("Global float address: %p\n", &global_float);

    return 0;
}