// #include <stdio.h>

// int mulByConst(int x, int multiplier) {
//     return x * multiplier;
// }

// int main() {
//     int x = 5;
//     int multipliers[] = {2, 3, 4, 5, 8, 12, 15, 16};
//     int n = sizeof(multipliers) / sizeof(multipliers[0]);

//     for (int i = 0; i < n; i++) {
//         int result = mulByConst(x, multipliers[i]);
//         printf("%d * %d = %d\n", x, multipliers[i], result);
//     }

//     return 0;
// }

#include <stdio.h>

// Function prototypes
int multiply_by_12(int x);
int multiply_by_21(int x);

// Multiplication functions
int multiply_by_12(int x) {
    return x * 12;
}

int multiply_by_21(int x) {
    return x * 21;
}

// Main function for testing
int main() {
    int test_val = 5;
    
    printf("Testing multiplication optimizations with value: %d\n", test_val);
    printf("multiply_by_12(%d) = %d\n", test_val, multiply_by_12(test_val));
    printf("multiply_by_21(%d) = %d\n", test_val, multiply_by_21(test_val));
    
    // Additional test with larger value
    test_val = 13;
    printf("\nTesting with larger value: %d\n", test_val);
    printf("multiply_by_12(%d) = %d\n", test_val, multiply_by_12(test_val));
    printf("multiply_by_21(%d) = %d\n", test_val, multiply_by_21(test_val));
    
    return 0;
}