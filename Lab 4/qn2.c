// WAP to find the multiplicative inverse of numbers in Zn using Extended Euclidean algorithm.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Extended Euclidean algorithm with table printing (t = t1 - q * t2)
int extended_gcd_table(int n, int a, int *x, int print_table) {
    int r1 = n, r2 = a;
    int t1 = 0, t2 = 1; // Start t1=0, t2=1
    int q, r, t;
    if (print_table) {
        printf("%3s %8s %8s %8s %8s %8s %8s\n", "q", "r1", "r2", "r", "t1", "t2", "t");
    }
    while (r2 != 0) {
        q = r1 / r2;
        r = r1 - q * r2;
        t = t1 - q * t2;
        if (print_table) {
            printf("%3d %8d %8d %8d %8d %8d %8d\n", q, r1, r2, r, t1, t2, t);
        }
        r1 = r2;
        r2 = r;
        t1 = t2;
        t2 = t;
    }
    *x = t1;
    // Print the final step where r2 = 0, matching the table orientation
    if (print_table) {
        printf("%3s %8d %8d %8s %8s %8s %8s\n","", r1, r2, "", "", "", "");
    }
    return r1;
}

int main() {
    int n, a, x, y, gcd;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the value of a: ");
    scanf("%d", &a);

    printf("\nTable for a = %d:\n", a);
    gcd = extended_gcd_table(n, a, &x, 1);

    if (gcd != 1) {
        printf("The multiplicative inverse of %d in Z%d does not exist\n", a, n);
    } else {
        int multiplicative_inverse = (x % n + n) % n;
        printf("Calculation: ((%d mod %d) + %d) mod %d = %d\n", x, n, n, n, multiplicative_inverse);
        printf("The multiplicative inverse of %d in Z%d is %d\n", a, n, multiplicative_inverse);
    }
    return 0;
}