#include <stdio.h>
#include <string.h>

#define MAX 20

int  c[MAX][MAX];   
char b[MAX][MAX];  

void lcsLength(char *X, char *Y, int m, int n) 
{
    for (int i = 0; i <= m; i++) c[i][0] = 0;
    for (int j = 0; j <= n; j++) c[0][j] = 0;

    for (int i = 1; i <= m; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            if (X[i-1] == Y[j-1]) 
            {          
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 'D';                
            } 
            else if (c[i-1][j] >= c[i][j-1]) 
            { 
                c[i][j] = c[i-1][j];
                b[i][j] = 'U';             
            } 
            else 
            {                          
                c[i][j] = c[i][j-1];
                b[i][j] = 'L';               
            }
        }
    }
}

void printLCS(char *X, int i, int j) 
{
    if (i == 0 || j == 0) return;
    if (b[i][j] == 'D') {
        printLCS(X, i-1, j-1);
        printf("%c", X[i-1]);
    } else if (b[i][j] == 'U') {
        printLCS(X, i-1, j);
    } else {
        printLCS(X, i, j-1);
    }
}

void printSCS(char *X, char *Y, int i, int j) 
{
    if (i == 0) 
    { 
        printf("%s", Y + (0)); 
        for (int k = 0; k < j; k++) printf("%c", Y[k]);
        return;
    }
}

void buildSCS(char *X, char *Y, int m, int n) 
{
    char scs[MAX * 2];
    int  idx = 0;
    int  i = m, j = n;

    char rev[MAX * 2];
    int  r = 0;

    while (i > 0 && j > 0) 
    {
        if (b[i][j] == 'D') 
        {
            rev[r++] = X[i-1];
            i--; j--;
        } else if (b[i][j] == 'U') 
        {
            rev[r++] = X[i-1];   
            i--;
        } 
        else 
        {
            rev[r++] = Y[j-1];   
            j--;
        }
    }
    while (i > 0) rev[r++] = X[--i];
    while (j > 0) rev[r++] = Y[--j];

    printf("SCS: ");
    for (int k = r - 1; k >= 0; k--)
        printf("%c", rev[k]);
    printf("\nSCS Length: %d  (= %d + %d - %d)\n", r, m, n, c[m][n]);
}

void printTable(char *X, char *Y, int m, int n) 
{
    printf("C[i][j] Table:\n");
    printf("     |  0 ");
    for (int j = 1; j <= n; j++) printf("  %c ", Y[j-1]);
    printf("\n-----|");
    for (int j = 0; j <= n; j++) printf("----");
    printf("\n");
    for (int i = 0; i <= m; i++) 
    {
        if (i == 0) printf("  0  |");
        else        printf("  %c  |", X[i-1]);
        for (int j = 0; j <= n; j++)
            printf("  %d ", c[i][j]);
        printf("\n");
    }
}

int main() 
{
    char X[] = "abbacdcba";
    char Y[] = "bcdbbcaa";
    int  m   = strlen(X);
    int  n   = strlen(Y);

    lcsLength(X, Y, m, n);

    printTable(X, Y, m, n);

    printf("\n--- LCS ---\n");
    printf("LCS: ");
    printLCS(X, m, n);
    printf("\nLCS Length: %d\n", c[m][n]);

    printf("\n--- SCS ---\n");
    buildSCS(X, Y, m, n);

    return 0;
}
