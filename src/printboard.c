#include "printboard.h"
#include <stdio.h>
#include <stdlib.h>

void printboard(char board[][9], int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}
