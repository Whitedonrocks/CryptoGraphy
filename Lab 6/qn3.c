// WAP to implement Elgamal Public Key Cryptosystem
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
    int p, g, x, m, k, c1, c2;

    printf("Enter a prime number (p): ");
    scanf("%d", &p);
    printf("Enter a primitive root of %d (g): ", p);
    scanf("%d", &g);
    printf("Enter private key for Alice (x): ");
    scanf("%d", &x);
    printf("Enter a message to encrypt (integer less than %d): ", p);
    scanf("%d", &m);
    if(m >= p) {
        printf("Message must be less than %d\n", p);
        return 1;
    }
    printf("enter the random integer k (1 < k < %d): ", p);
    scanf("%d", &k);
    if (k <= 1 || k >= p)
    {
        printf("k must be in the range (1, %d)\n", p);
        return 1;
    }
    

    // Generate public key
    int y = power(g, x, p);
    printf("Alice's public key: (%d,%d, %d)\n", p, g, y);

    // Encrypt the message
    c1 = power(g, k, p);
    c2 = (m * power(y, k, p)) % p;
    printf("Encrypted message: (%d, %d)\n", c1, c2);

    // Decrypt the message
    int s = power(c1, x, p);
    int s_inv = power(s, p - 2, p); 
    int decrypted = (c2 * s_inv) % p;
    printf("Decrypted message: %d\n", decrypted);

    if (m == decrypted) {
        printf("Encryption and decryption successful!\n");
    } else {
        printf("Encryption and decryption failed!\n");
    }

    return 0;
}