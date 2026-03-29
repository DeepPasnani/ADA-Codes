#include <stdio.h>
#include <stdlib.h>

#define NUM_COINS 5

int coins[NUM_COINS] = {100, 25, 10, 5, 1};
const char *coinNames[NUM_COINS] = {"Dollar(100¢)", "Quarter(25¢)", "Dime(10¢)", "Nickel(5¢)", "Penny(1¢)"};

void makeChange(int n) 
{
    int count[NUM_COINS] = {0};  
    int sum = 0;

    printf("\n--- Make Change Problem ---\n");
    printf("Amount to change: %d cents\n\n", n);

    while (sum != n) {
        int found = 0;
        for (int i = 0; i < NUM_COINS; i++) 
        {
            if (sum + coins[i] <= n)
         {
                count[i]++;
                sum += coins[i];
                found = 1;
                break;  
            }
        }
        if (!found) 
        {
            printf("No solution found!\n");
            return;
        }
    }

    int totalCoins = 0;
    printf("%-15s | %-10s\n", "Coin", "Count");
    printf("-----------------------------\n");
    for (int i = 0; i < NUM_COINS; i++) 
    {
        if (count[i] > 0) 
        {
            printf("%-15s | %d\n", coinNames[i], count[i]);
            totalCoins += count[i];
        }
    }
    printf("-----------------------------\n");
    printf("Total coins used: %d\n", totalCoins);
}

typedef struct 
{
    char name[10];
    int start;
    int finish;
} Activity;

int compareByFinish(const void *a, const void *b) 
{
    Activity *x = (Activity *)a;
    Activity *y = (Activity *)b;
    return x->finish - y->finish;
}

void activitySelection(Activity acts[], int n) 
{
    printf("\n--- Activity Selection Problem ---\n");

    qsort(acts, n, sizeof(Activity), compareByFinish);

    printf("Activities sorted by finish time:\n");
    printf("%-6s | %-8s | %-8s\n", "Name", "Start", "Finish");
    printf("---------------------------\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%-6s | %-8d | %-8d\n", acts[i].name, acts[i].start, acts[i].finish);
    }
    printf("\n");

    int selected[50];
    int count = 0;

    selected[count++] = 0;  
    int j = 0;              

    for (int i = 1; i < n; i++) 
    {
        if (acts[i].start >= acts[j].finish) 
        {
            selected[count++] = i;
            j = i;
        }
    }

    printf("Selected Activities (Maximum Compatible Set):\n");
    printf("%-6s | %-8s | %-8s\n", "Name", "Start", "Finish");
    printf("---------------------------\n");
    for (int i = 0; i < count; i++) 
    {
        printf("%-6s | %-8d | %-8d\n",
               acts[selected[i]].name,
               acts[selected[i]].start,
               acts[selected[i]].finish);
    }
    printf("---------------------------\n");
    printf("Maximum number of activities: %d\n", count);
}

int main() 
{
    makeChange(289);

    printf("\n");                                         
    Activity acts[] = 
    {
        {"p", 1, 4},
        {"q", 3, 5},
        {"r", 0, 6},
        {"s", 5, 7},
        {"t", 3, 8},
        {"u", 5, 9},
        {"v", 6, 10},
        {"w", 8, 11},
        {"x", 8, 12},
        {"y", 2, 13},
        {"z", 12, 14}
    };
    int n = sizeof(acts) / sizeof(acts[0]);

    activitySelection(acts, n);

    return 0;
}
