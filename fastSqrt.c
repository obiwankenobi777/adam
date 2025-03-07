#include <stdio.h>

double fast(double num) {
    double result;
    asm volatile (
    "fldl %1\n\t"
    "fsqrt\n\t"
    "fstpl %0"
    : "=m"(result)
    : "m"(num)
    : "st"
    );
    return result;
}

int main(void) {
    double num = 49.0;
    printf("fast sqrt(%f): %f\n", num, fast(num));
    return 0;
}
