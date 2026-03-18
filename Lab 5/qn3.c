// write a c program to find primitive root of any number

#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int isPrimitiveRoot(int g, int p) {
    int seen[p];
    int value = 1;

    for (int i = 0; i < p; i++) {
        seen[i] = 0;
    }

    if (gcd(g, p) != 1)
        return 0;

    printf("\nModulo operations:\n");
    for (int i = 1; i < p; i++) {
        value = (value * g) % p;
        printf("%d^%d mod %d = %d\n", g, i, p, value);

        if (value == 0 || seen[value])
            return 0;

        seen[value] = 1;
    }

    return 1;
}

int main() {
    int p, g;
    printf("Enter a prime number: ");
    scanf("%d", &p);

    printf("Enter a number to check if it is a primitive root modulo %d: ", p);
    scanf("%d", &g);

    if (isPrimitiveRoot(g, p))
        printf("%d is a primitive root modulo %d\n", g, p);
    else
        printf("%d is not a primitive root modulo %d\n", g, p);

    return 0;
}