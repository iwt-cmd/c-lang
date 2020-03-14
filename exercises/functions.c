#include <stdlib.h>
#include <stdio.h>
#include "jlbmath.h"

int gcd_a, gcd_b;
float abs_a, sqrtv;

int main() {
    printf("Enter first digit: ");
    scanf("%d", &gcd_a);
    printf("\nEnter second digit: ");
    scanf("%d", &gcd_b);
    printf("\nGCD is: %d\n", gcd(gcd_a, gcd_b));
    printf("Enter number: ");
    scanf("%f", &abs_a);
    printf("\nAbsolute Value: %f", absl(abs_a));
    printf("\nEnter number to sqrt: ");
    scanf("%f", &sqrtv);
    printf("\nSqrt of %f: %f\n", sqrtv, sqroot(sqrtv));
}