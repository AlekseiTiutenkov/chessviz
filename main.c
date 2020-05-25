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

char WhPesh(char board[][9], int n, char hod[10])
{
    int i, k = 0, t, t1, p1, p2;
    for (i = 1; i < n; i++)
        if (hod[0] == board[8][i])
            t = i;

    for (i = 1; i < n; i++)
        if (hod[3] == board[8][i])
            t1 = i;
    p1 = 8 - (hod[1] - 48);
    p2 = 8 - (hod[4] - 48);

    if (board[p2][t1] == '\0') {
        for (p1--; p1 >= p2; p1--)
            if (board[p1][t] != '\0')
                k++;
        if ((hod[4] - hod[1] > 2) || (board[board[0][0] - hod[1]][t] != 'P')
            || (hod[0] != hod[3]) || (k != 0))
            printf("Incorrect hod \n");
        else {
            board[board[0][0] - hod[1]][t] = '\0';
            board[board[0][0] - hod[1] - (hod[4] - hod[1])][t] = 'P';
        }
    }
    return 0;
}

int main()
{
    int n = 9, k = 3, p1 = 0, t = 0, f = 0, i , j;
    char hod[10], board[9][9], boardtemp[9][9];
    startboard(board, n);
    printboard(board, n);
while (1) {
        if (k % 2 == 1) {
            printf("White turn. Enter hod: ");

            scanf("%s", hod);
            if (hod[0] == 'a' || hod[0] == 'b' || hod[0] == 'c' || hod[0] == 'd'
                || hod[0] == 'e' || hod[0] == 'f' || hod[0] == 'g'
                || hod[0] == 'h') {
                for (i = 0; i < 8; i++) {
                    for (j = 1; j < 9; j++) {
                        boardtemp[i][j] = board[i][j];
                    }
                }

                for (i = 1; i < n; i++)
                    if (hod[0] == board[8][i])
                        t = i;
                p1 = 8 - (hod[1] - 48);
		if (board[p1][t] == 'P') {
                    WhPesh(board, n, hod);
                    printboard(board, n);
                }


                for (i = 0; i < 8; i++) {
                    for (j = 1; j < 9; j++) {
                        if (boardtemp[i][j] != board[i][j]) {
                            f++;
                        }
                    }
                }
                if (f > 0)
                    k++;
                for (i = 0; i < n; i++)
                    hod[i] = '\0';
                if (f == 0) {
                    printf("Incorrect hod\n");
                    printboard(board, n);
                }
                f = 0;

            } else {
                printf("Incorrect hod\n");
                printboard(board, n);
            }
        }
    }
    system("PAUSE");
    return 0;
}
