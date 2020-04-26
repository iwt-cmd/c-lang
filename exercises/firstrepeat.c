#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]){
    if(argc == 1){
        printf("Must include word to check\n");
        return 0;
    }
    if (argc > 2){
        printf("Only single word may be included\n");
        return 0;
    }
    if(strlen(argv[1])>23){
        printf("Enter smaller word to check\n");
        return 0;
    }

    char *array, retchar[2];
    int i, j, slen, retint;
    array = (char*)malloc(sizeof(argv[1])+1);
    strcpy(array, argv[1]);
    slen=strlen(array);
    retint = slen+1;
    for(i=0;i<slen-1;i++){
        for(j=i+1;j<slen;j++){
            if (i>retint){
                printf("%c\n", retchar[0]);
                return 0;
            }
            if (array[i] == array[j]){
                retchar[0] = array[i];
                retint = j;
            }
        }
    }
    if (retint == slen+1){
        printf("No repeating chars found\n");
    }
    else {
        printf("%c\n", retchar[0]);
    }
    return 0;

}