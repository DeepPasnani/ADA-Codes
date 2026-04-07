#include <stdio.h>
#define MAX 20

int board[MAX][MAX];
int N;

int isSafe(int row, int col) 
{
    int i, j;
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
            return 0;
    }
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
    {
        if (board[i][j])
            return 0;
    }   

    for (i=row, j=col; j>=0 && i<N; i++, j--)
    {
        if (board[i][j])
            return 0;
    }
    return 1;
}

int solve(int col) 
{
    if (col >= N)
    return 1;
    for (int i = 0; i < N; i++) 
    {
        if (isSafe(i, col)) 
        {
            board[i][col] = 1;
        }
    if (solve(col + 1))
        return 1;
        board[i][col] = 0;
        }
    return 0;
}
