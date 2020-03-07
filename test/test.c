#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*
    Test function for finding the max value in array a[]
*/
int main(){
    int a[10] = {0,0,0,0,0,0,0,0,0,0};
    int max=0;
    char t_val = 'n';
    int count = 0;
    while (t_val != 'd') {
        printf("Enter a value (blank to finish): ");
        scanf(" %s", &t_val);
        if (!(t_val >= 'a' && t_val <='z')||!(t_val >= 'A' && t_val <= 'Z')) {
            a[count] = atoi(&t_val);
            //printf("A value: %d\n", a[count]);
            count++;
            if (count == 10) {
                break;
            }
        } else if (t_val == 'd' || t_val == EOF){
            break;
        }
        else {
            printf("Not a valid entry");
        }
    } 
    for (int i = 0; i <= count-1; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    printf("Number of values: %d\n", count-1);
    printf("The max value is: %d\n", max);
    return 0;
}