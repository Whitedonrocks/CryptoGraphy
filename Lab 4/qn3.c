// WAP to test whether two positive integers are relatively prime or not using the Extended Euclidean Algorithm.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Extended Euclidean algorithm with table printing (t = t1 - q * t2)
int extended_gcd_table(int n, int a, int *x,int print_table) {
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
    int n, a, x, gcd;

    printf("Enter the first positive integer: ");
    scanf("%d", &n);

    printf("Enter the second positive integer: ");
    scanf("%d", &a);

    printf("\nExtended Euclidean Table for (%d, %d):\n", n, a);
    gcd = extended_gcd_table(n, a, &x, 1);

    if (gcd == 1) {
        printf("%d and %d are relatively prime (gcd = 1).\n", n, a);
    } else {
        printf("%d and %d are NOT relatively prime (gcd = %d).\n", n, a, gcd);
    }
    return 0;
}