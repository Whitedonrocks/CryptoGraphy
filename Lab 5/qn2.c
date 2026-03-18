// WAP to find the Euler Totient function value of any number.
#include <stdio.h>
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int eulerTotient(int n) {
    int count = 0;
    for (int i = 1; i < n; i++) {
        if (gcd(i, n) == 1)
            count++;
    }
    return count;
}
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int result = eulerTotient(n);
    printf("Euler Totient function value of %d is: %d\n", n, result);
    return 0;
}
