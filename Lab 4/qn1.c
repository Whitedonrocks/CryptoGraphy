// WAP to find the additive inverse of numbers in Zn.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, a, additive_inverse;
    
    printf("\nEnter the value of n: ");
    scanf("%d", &n);
    
    printf("Enter the Number: ");
    scanf("%d", &a);
    
    // Find the additive inverse of a in Zn
    additive_inverse = (-a) % n;
    if (additive_inverse < 0) {
        additive_inverse += n;
    }
    
    printf("The additive inverse of %d in Z%d is %d\n", a, n, additive_inverse);
    
    return 0;
}