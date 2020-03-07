#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*
    Test function for finding the max value in array a[]

    Issues:
    - Does not handle return without data (i.e. empty \n)
    - Cannot expand beyond 10 elements in a[]

    Future:
    - Dynamically expand a[] as count gets closer to current limit
      - Not natively supported in C
      - Possibly use malloc/realloc to generate new array
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
            count++;
            if (count == 10) {
                break;
            }
        } else if (t_val == 'd'){
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