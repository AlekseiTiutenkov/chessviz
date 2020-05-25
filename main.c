#include <stdio.h>
#include <stdlib.h>

void startboard(char board[][9], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            board[i][j] = '\0';
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            if (j == 0) {
                board[0][j] = '8';
                board[1][j] = '7';
                board[2][j] = '6';
                board[3][j] = '5';
                board[4][j] = '4';
                board[5][j] = '3';
                board[6][j] = '2';
                board[7][j] = '1';
                board[8][j] = ' ';
            }
            if (i == 8) {
                board[i][0] = ' ';
                board[i][1] = 'a';
                board[i][2] = 'b';
                board[i][3] = 'c';
                board[i][4] = 'd';
                board[i][5] = 'e';
                board[i][6] = 'f';
                board[i][7] = 'g';
                board[i][8] = 'h';
            }

            if (i == 8 - 7)
                board[i][j] = 'p';
            if ((i == 8 - 8 && j == 1) || (i == 8 - 8 && j == 8))
                board[i][j] = 'r';
            if ((i == 8 - 8 && j == 2) || (i == 8 - 8 && j == 7))
                board[i][j] = 'n';
            if ((i == 8 - 8 && j == 3) || (i == 8 - 8 && j == 6))
                board[i][j] = 'b';
            if (i == 8 - 8 && j == 4)
                board[i][j] = 'q';
            if (i == 8 - 8 && j == 5)
                board[i][j] = 'k';

            if (i == 8 - 2)
                board[i][j] = 'P';
            if ((i == 8 - 1 && j == 1) || (i == 8 - 1 && j == 8))
                board[i][j] = 'R';
            if ((i == 8 - 1 && j == 2) || (i == 8 - 1 && j == 7))
                board[i][j] = 'N';
            if ((i == 8 - 1 && j == 3) || (i == 8 - 1 && j == 6))
                board[i][j] = 'B';
            if (i == 8 - 1 && j == 4)
                board[i][j] = 'Q';
            if (i == 8 - 1 && j == 5)
                board[i][j] = 'K';
        }
}

void printboard(char board[9][9], int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int n = 9;
    char board[9][9];
    startboard(board, n);
    printboard(board, n);
    system("PAUSE");
    return 0;
}
