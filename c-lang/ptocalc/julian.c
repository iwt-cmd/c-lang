#include "julian.h"
int juliandate(int m_in, int d_in) {
    int f_day[] = {1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
    int m_days[] = {30, 27, 30, 29, 30, 29, 30, 30, 29, 30, 29, 30};

    int j_day = f_day[m_in - 1] + d_in-1;
    return j_day;
}
/*
char *georgiandate(int j_in) {
    int month = 20;
    int day;
    char ret[6], m_char[3], d_char[3];
    for (int i = 0; month = 20; i++) {
        if (j_in <= f_day[i]) {
            month = i + 1;
        }
    }
    day = (j_in - f_day[month-1])+1;
    
    sprintf(ret, "%d-%d", month, day);
    return ret;
}
*/