#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){
    if (argc == 1){
        printf("Must include word or pharse to check\n");
        return 0;
    }
    if (argc > 2){
        printf("Only 1 word or phase can be entered. Phrases in \" \"\n");
        return 0;
    }

    char *array, *chars;
    int counts[sizeof(argv[1])], temp=0, i, j;

    array = (char*)malloc(sizeof(argv[1]));
    strcpy(array, argv[1]);
    if (sizeof(array)==1){
        printf("%c > 1", array[0]);
        return 0;
    }
    else {
        chars = (char*)malloc(sizeof(array));
        //counts = (int*)malloc(sizeof(array)*sizeof(int));
    }
    for(i=0;i<sizeof(array);i++){
        j=0;
        temp=0;
        while(chars[j] != '\0'){

            if(array[i]==chars[j]){
                counts[j]+=i;
                temp=i;
            }
            else{
                j++;
            }
        }
        if(temp==0){
            chars[i]=array[i];
            counts[i]=1;
        }

    }
    for(i=0;i<sizeof(chars);i++){
        printf("%c > %d\n", chars[i], counts[i]);
    }
    return 0;
}