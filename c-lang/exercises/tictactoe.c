#include <stdio.h>
#include <stdlib.h>
/*
    Testing command line parsing
*/
void PrintBoard(int b[][3]){
    for(int r=0; r<3; r++){
        printf("|");
        for(int c=0; c<3; c++){
            
            printf(" %d |", b[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}
int CheckBoard(int b[][3]){
    int endgame = 1;
    //Row Check
    for(int r=0; r<3; r++){
        if (b[r][0] == b[r][1] && b[r][0] == b[r][2]) {
            if (b[r][0] != 0) {
                return 1;
            }
        }
    }
    //Column Check
    for(int c=0; c<3; c++){
        if (b[0][c] == b[1][c] && b[0][c] == b[2][c]) {
            if (b[0][c] != 0) {
                return 1;
            }
        }
    }
    //Diag Checks
    if (b[0][0] == b[1][1] && b[0][0] == b[2][2]) {
        if(b[0][0] != 0){
            return 1;
        }
    }
    if (b[0][2] == b[1][1] && b[0][2] == b[2][0]) {
        if (b[2][0] != 0){
            return 1;
        }
    }
    //Check for 0's
    for (int r=0;r<3;r++){
        if (b[r][0] == 0 || b[r][1] == 0 || b[r][2] == 0) {
            endgame = 0;
        }

    }
    //If no 0' without winner already, Null Board
    if(endgame == 1) {
        return 2;
    }
    return 0;
}
int main(int argc, char *argv[]){
    int board[3][3]= {{0, 0, 0}, {0, 0, 0}, {0,0,0}};
    int winner=0, player=1;
    printf("Tick Tack Toe\n");
    printf("Enter choice as 'row,column'\n");
    //PrintBoard(board);
    while (winner == 0){
        PrintBoard(board);
        int row, col;
        printf("Player %d:", player);
        scanf("%d %d", &row, &col);
        board[row][col] = player;
        int check = CheckBoard(board);
        if (check == 1) {
            winner = player;
            printf("Winner: Player %d\n", winner);
            PrintBoard(board);

        }
        else if (check == 2) {
            printf("Null Game :(\n");
            PrintBoard(board);
            winner = 99;
        }
        else {
            if (player == 1) {
                player = 2;
            }
            else {
                player = 1;
            }
        }
    }
    
    return 0;
}