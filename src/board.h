#ifndef BOARD_H
#define BOARD_H

void startboard(char board[][9], int n);
char WhPesh(char board[][9], int n, char hod[10]);
char BlPesh(char board[][9], int n, char hod[10]);
int Queue(int k, char board[9][9], char boardtemp[9][9], char hod[10], int n);
#endif // BOARD_H
