#include <stdio.h>

#define MAX 10

int M[MAX][MAX];   
int S[MAX][MAX];   

void matrixChain(int p[], int n) 
{
    for (int i = 1; i <= n; i++)
        M[i][i] = 0;

    for (int l = 2; l <= n; l++) 
    {
        for (int i = 1; i <= n - l + 1; i++) 
        {
            int j = i + l - 1;
            M[i][j] = 99999;

            for (int k = i; k < j; k++) 
            {
                int cost = M[i][k] + M[k+1][j] + p[i-1] * p[k] * p[j];
                if (cost < M[i][j]) 
                {
                    M[i][j] = cost;
                    S[i][j] = k;
                }
            }
        }
    }
}

void printOptimal(int i, int j) 
{
    if (i == j) 
    {
        printf("A%d", i);
    } 
    else 
    {
        printf("(");
        printOptimal(i, S[i][j]);
        printf(" x ");
        printOptimal(S[i][j] + 1, j);
        printf(")");
    }
}

void printTable(int T[MAX][MAX], int n, char *name) 
{
    printf("%s:\n", name);
    printf("i\\j |");
    for (int j = 1; j <= n; j++) printf("  %4d", j);
    printf("\n-----|");
    for (int j = 1; j <= n; j++) printf("------");
    printf("\n");
    for (int i = 1; i <= n; i++) 
    {
        printf("  %d  |", i);
        for (int j = 1; j <= n; j++) 
        {
            if (i > j) printf("     -");
            else       printf("  %4d", T[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() 
{
    int p[] = {5, 4, 6, 2, 7};
    int n   = 4;  

    matrixChain(p, n);

    printTable(M, n, "M[i][j] — Minimum Cost Table");
    printTable(S, n, "S[i][j] — Split Point Table");

    printf("Minimum number of scalar multiplications: %d\n", M[1][n]);
    printf("Optimal Parenthesization: ");
    printOptimal(1, n);
    printf("\n");

    return 0;
}
