#include <stdio.h>

#define INF 9999

void makeChange(int d[], int n, int N) 
{
    int c[n + 1][N + 1];

    for (int i = 1; i <= n; i++)
        c[i][0] = 0;

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= N; j++) 
        {
            if (i == 1 && j < d[i])
                c[i][j] = INF;
            else if (i == 1)
                c[i][j] = 1 + c[1][j - d[i]];
            else if (j < d[i])
                c[i][j] = c[i-1][j];
            else
                c[i][j] = (c[i-1][j] < 1 + c[i][j - d[i]])
                           ? c[i-1][j] : 1 + c[i][j - d[i]];
        }
    }

    printf("--- Make Change (DP Table) ---\n");
    printf("d\\j |");
    for (int j = 0; j <= N; j++) printf(" %3d", j);
    printf("\n");
    printf("-----|");
    for (int j = 0; j <= N; j++) printf("----");
    printf("\n");
    for (int i = 1; i <= n; i++) 
    {
        printf("d=%d  |  0", d[i]);
        for (int j = 1; j <= N; j++)
            printf(" %3d", c[i][j]);
        printf("\n");
    }
    printf("\nMinimum coins needed for change of %d: %d\n", N, c[n][N]);
}

void knapsack01(int w[], int v[], int n, int W) 
{
    int V[n + 1][W + 1];

    for (int i = 0; i <= n; i++) V[i][0] = 0;
    for (int j = 0; j <= W; j++) V[0][j] = 0;

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= W; j++) 
        {
            if (j < w[i])
                V[i][j] = V[i-1][j];
            else
                V[i][j] = (V[i-1][j] > V[i-1][j - w[i]] + v[i])
                           ? V[i-1][j] : V[i-1][j - w[i]] + v[i];
        }
    }

    printf("--- 0/1 Knapsack (DP Table) ---\n");
    printf("i\\j |");
    for (int j = 0; j <= W; j++) printf(" %3d", j);
    printf("\n");
    printf("-----|");
    for (int j = 0; j <= W; j++) printf("----");
    printf("\n");
    for (int i = 0; i <= n; i++) 
    {
        printf("  %d  |", i);
        for (int j = 0; j <= W; j++) printf(" %3d", V[i][j]);
        printf("\n");
    }

    printf("\nSelected Items:\n");
    int j = W;
    for (int i = n; i >= 1; i--) 
    {
        if (V[i][j] != V[i-1][j]) 
        {
            printf("  Item %d (weight=%d, value=%d) → taken\n", i, w[i], v[i]);
            j -= w[i];
        }
    }
    printf("\nMaximum Value: %d\n", V[n][W]);
}

int main() 
{
    int d[] = {0, 1, 4, 6};  
    makeChange(d, 3, 8);

    printf("\n");

    int w[] = {0, 1, 2, 5, 6, 7};   
    int v[] = {0, 1, 6, 18, 22, 28};
    knapsack01(w, v, 5, 11);

    return 0;
}
