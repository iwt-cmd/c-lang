#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "julian.h"
/*
    PTO Calculator

    Functions:
    - AccumTime2Date: amount of PTO to desired date
    - AccumDate2Time: date needed to reach desired 
*/
int main(int argc, char *argv[]){
    //constants
    float jlb_perpay = 6.5;
    int h2d = 8;
    int d2w = 5;
    int month, day;
    char date[7];
    char i_m_d[6];
    int count = 0;
    //user variables
    /*
    printf("Input Date (mm-dd): ");
    scanf("%c", i_m_d);

    *token= strtok(i_m_d, "-");
    while (token != NULL) {
        date[i] = token;
        token = strtok(NULL, "-");
        count++;
    }
    
    */
    printf("Julian Date 3-14: %d", juliandate(3, 14));
    //printf("Georgian Date 040, 2-9: %c", georgiandate(40));
    return 0;
}