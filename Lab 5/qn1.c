// write a c program to test whether given numbers is prime or not using Miller-Rabin algorithm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// modular exponentiation
int power(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Miller test
int millerTest(int q, int n ,int a) {
    int x = power(a, q, n);

    if (x == 1 || x == n - 1)
        return 1;

    while (q != n - 1) {
        x = (x * x) % n;
        q *= 2;

        if (x == 1) return 0;
        if (x == n - 1) return 1;
    }
    return 0;
}

// check prime
int isPrime(int n, int iter) {
    if (n <= 1 || n == 4) return 0;
    if (n <= 3) return 1;

    int q = n - 1;
    int k = 0;
    int a = 2 + rand() % (n - 3);
    printf("Randomly chosen base a = %d\n", a);

    // find k and q
    while (q % 2 == 0) {
        q /= 2;
        k++;
    }

    printf("k = %d, q = %d\n", k, q);

    for (int i = 0; i < iter; i++) {
        if (!millerTest(q, n, a))
            return 0;
    }

    return 1;
}

int main() {
    int n;
    int iter = 5;

    printf("Enter number: ");
    scanf("%d", &n);

    if (isPrime(n, iter))
        printf("%d is prime.\n", n);
    else
        printf("%d is composite.\n", n);

    return 0;
}