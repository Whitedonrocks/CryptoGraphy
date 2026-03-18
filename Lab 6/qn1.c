// wap to implement Diffie-Hellman key exchange algorithm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int power(int base, int exponent, int modulus) {
    int result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int main() {
    int p, g, a, b, A, B, s_A, s_B;

    printf("\nEnter a prime number (p): ");
    scanf("%d", &p);
    printf("Enter a primitive root of %d (g): ", p);
    scanf("%d", &g);
    printf("Enter private key for Alice (a): ");
    scanf("%d", &a);
    printf("Enter private key for Bob (b): ");
    scanf("%d", &b);

    A = power(g, a, p);
    B = power(g, b, p);

    s_A = power(B, a, p);
    s_B = power(A, b, p);

    printf("Alice's public key: %d\n", A);
    printf("Bob's public key: %d\n", B);
    printf("Shared secret key (Alice): %d\n", s_A);
    printf("Shared secret key (Bob): %d\n", s_B);
    if(s_A == s_B)
        printf("Shared secret keys match. Key exchange successful.\n");
    else
        printf("Shared secret keys do not match. Key exchange failed.\n");

    return 0;
}