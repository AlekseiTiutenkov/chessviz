#include "board.h"
#include "printboard.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, n = 9, k = 3, p1 = 0, t = 0;
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
                k = Queue(k, board, boardtemp, hod, n);
            } else {
                printf("Incorrect hod\n");
                printboard(board, n);
            }
        }
        if (k % 2 == 0) {
            printf("Black turn. Enter hod: ");

            scanf("%s", hod);
            if (hod[0] == 'a' || hod[0] == 'b' || hod[0] == 'c' || hod[0] == 'd'
                || hod[0] == 'e' || hod[0] == 'f' || hod[0] == 'g'
                || hod[0] == 'h') {
                if (hod[5] != '\0')
                    continue;
                for (i = 0; i < 8; i++) {
                    for (j = 1; j < 9; j++) {
                        boardtemp[i][j] = board[i][j];
                    }
                }

                for (i = 1; i < n; i++)
                    if (hod[0] == board[8][i])
                        t = i;

                p1 = 8 - (hod[1] - 48);

                if (board[p1][t] == 'p') {
                    BlPesh(board, n, hod);
                    printboard(board, n);
                }
                k = Queue(k, board, boardtemp, hod, n);
            } else {
                printf("Incorrect hod\n");
                printboard(board, n);
            }
        }
    }
    system("PAUSE");
    return 0;
}
