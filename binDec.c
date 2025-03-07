#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    long long int b, dec = 0, i = 1, rem;
    b = atoll(argv[1]);

    while (b != 0) {
        rem = b % 10;
        dec = dec + rem * i;
        i += 2;
        b /= 10;
    }

    printf("Decimal number: %lld\n", dec);
    
    return 0;
}
