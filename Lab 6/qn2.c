// wap to implement RSA algorithm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
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
int main() {
    int p, q, n, phi, e, d, message, encrypted, decrypted;
    printf("\nEnter two prime numbers (p and q): ");
    scanf("%d %d", &p, &q);
    n = p * q;
    phi = (p - 1) * (q - 1);
    printf("Enter a public exponent (e) such that 1 < e < %d and gcd(e, %d) = 1: ", phi, phi);
    scanf("%d", &e);
    while (gcd(e, phi) != 1) {
        printf("Invalid e. Enter a public exponent (e) such that 1 < e < %d and gcd(e, %d) = 1: ", phi, phi);
        scanf("%d", &e);
    }
    d = 1;
    while ((d * e) % phi != 1) {
        d++;
    }
    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);
    printf("Enter a message to encrypt (integer less than %d): ", n);
    scanf("%d", &message);
    encrypted = power(message, e, n);
    decrypted = power(encrypted, d, n);
    printf("Encrypted message: %d\n", encrypted);
    printf("Decrypted message: %d\n", decrypted);
    if (message == decrypted) {
        printf("Encryption and decryption successful!\n");
    } else {
        printf("Encryption and decryption failed!\n");
    }
    return 0;
}