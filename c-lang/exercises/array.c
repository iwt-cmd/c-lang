#include <stdio.h>
#include <stdlib.h>

int main () {
    int array1[] = {4, 9, 2, 99, 45, 23, 8, 14};
    int l = sizeof(array1)/sizeof(array1[0]);
    int swap, temp, c;
    while (1) {
        int monitor = 0;
        for (int i = 0; i < l-1; i++) {
            if (array1[i] > array1[i+1]) {
                swap = array1[i];
                temp = array1[i+1];
                array1[i] = temp;
                array1[i+1] = swap;
                monitor = 1;
            }
        }
        if (monitor == 0) {
            break;
        }
    }
    for (int i = 0; i < l; i++) {
        printf("%d ", array1[i]);
    }
    return 0;
}