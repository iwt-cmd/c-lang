#include "jlbmath.h"
//Greatest Common Divisor
int gcd(int a, int b) {
    int test = 1, num_a, num_b;
    
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    if (a > b) {
        num_a = a;
        num_b = b;
    } else {
        num_a = b;
        num_b = a;
    }
    while (1) {
        test = num_a % num_b;
        if (test == 0) {
            return num_b;
        }
        num_a = num_b;
        num_b = test;
    }
}

//Absolute Number
float absl(float a) {
    if (a < 0) {
        return a * -1;
    }
    else {
        return a;
    }
}

float sqroot (float a) {
    float x = a;
    float y = 1;
    float e = 0.00001;
    while (x - y > e) {
        x = (x+y)/2;
        y = a/x;
    }
    return x;
}