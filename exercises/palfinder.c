//Finds if a word/sentencen is a palindrome
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char *argv[]){

    //Checking input
    if(argc == 1){
        printf("Single input word required\n");
        return 0;
    }
    if (argc > 2){
        printf("Multi-word input requires \" \"\n");
        return 0;
    }
    if(strlen(argv[1])>23){
        printf("Many much chars, try something smaller\n");
        return 0;
    }

    //Allocte variables
    int cf, cr=0;
    char *array;
    array = (char*)malloc(sizeof(argv[1])+1);
    strcpy(array, argv[1]);
    printf("%ld\n", strlen(array));
    cr = strlen(array)-1;
    
    //Check for single char array
    if (cr == 1){
        printf("Single char passed\n");
        return 0;
    }

    //Loops differ from even and odd
    if (cr%2 == 0){
        for(cf=0;cf!=cr;cf++, cr--){
            printf("%c, %c\n", array[cf], array[cr]);
            if (array[cf] == array[cr]){
                continue;
            }
            else {
                printf("Not palindrome\n");
                return 0;
            }
        }
    }
    else {
        for(cf=0;cf!=cr-1;cf++, cr--){
            if (array[cf] == array[cr]){
                continue;
            }
            else {
                printf("Not palindrome\n");
                return 0;
            }
        }
    }
    
    printf("palindrome\n");
    free(array);
    return 0;
}