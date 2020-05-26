#define CTEST_MAIN

#include "../src/board.h"
#include <ctest.h>

char hod[10], board[9][9], boardtemp[9][9];
int n = 9;
CTEST(WhitePawn, CorrectMove1)
{
    startboard(board, n);
    hod[0] = 'e';
    hod[1] = '2';
    hod[2] = '-';
    hod[3] = 'e';
    hod[4] = '4';
    int result = WhPesh(board, n, hod);
    ASSERT_EQUAL(2, result);
}
CTEST(WhitePawn, IncorrectMove1)
{
    startboard(board, n);
    hod[0] = 'e';
    hod[1] = '2';
    hod[2] = '-';
    hod[3] = 'd';
    hod[4] = '3';
    int result = WhPesh(board, n, hod);
    ASSERT_EQUAL(1, result);
}
CTEST(WhitePawn, IncorrectMove2)
{
    startboard(board, n);
    hod[0] = 'e';
    hod[1] = '2';
    hod[2] = '-';
    hod[3] = 'e';
    hod[4] = '5';
    int result = WhPesh(board, n, hod);
    ASSERT_EQUAL(1, result);
}
int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
