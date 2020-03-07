#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[] = {12, 5, 3, 71, 109, 900};
    int max;
    int a_len = sizeof(a)/sizeof(int);

    for (int i = 0; i < a_len; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    //test test test
    printf("The max value is: %d\n", max);
    return 0;
}