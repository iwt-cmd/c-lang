#include <stdio.h>
#include <stdlib.h>

/*
    Testing command line parsing
*/
int main(int argc, char *argv[]){
    int count = 1;
    for (int i = 1; i < argc; i++){
        printf("Arg %d: %s\n", i, argv[i]);
    }
    printf("Length: %d\n", argc);
    return 0;
}