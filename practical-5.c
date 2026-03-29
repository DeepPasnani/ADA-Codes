#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int    id;
    double weight, value, ratio;
} Item;

int compareByRatio(const void *a, const void *b) 
{
    double diff = ((Item *)b)->ratio - ((Item *)a)->ratio;
    return (diff > 0) - (diff < 0);
}

void knapsack01Greedy(Item items[], int n, double W) 
{
    for (int i = 0; i < n; i++)
        items[i].ratio = items[i].value / items[i].weight;

    qsort(items, n, sizeof(Item), compareByRatio);

    double totalWeight = 0, totalValue = 0;

    printf("Object | vi/wi | Taken\n");
    printf("---------------------------\n");
    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= W) 
        {
            totalWeight += items[i].weight;
            totalValue  += items[i].value;
            printf("  %d    | %.2f  | YES\n", items[i].id, items[i].ratio);
        } 
        else 
        {
            printf("  %d    | %.2f  | NO\n", items[i].id, items[i].ratio);
        }
    }
    printf("---------------------------\n");
    printf("Total Value: %.2f\n", totalValue);
}

typedef struct 
{
    int id;
    int profit;
    int deadline;
} Job;

int compareByProfit(const void *a, const void *b) 
{
    return ((Job *)b)->profit - ((Job *)a)->profit;
}

void jobScheduling(Job jobs[], int n) 
{
    qsort(jobs, n, sizeof(Job), compareByProfit);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;

    int P = (n < maxDeadline) ? n : maxDeadline;

    int slot[P + 1];
    memset(slot, 0, sizeof(slot));
    int totalProfit = 0;

    for (int i = 0; i < n; i++) 
    {
        int d = (jobs[i].deadline > P) ? P : jobs[i].deadline;
        for (int t = d; t >= 1; t--) 
        {
            if (slot[t] == 0) 
            {
                slot[t] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Time Slot | Job\n");
    printf("-------------------\n");
    for (int t = 1; t <= P; t++)
        if (slot[t] != 0)
            printf("    %d     |  %d\n", t, slot[t]);
    printf("-------------------\n");
    printf("Total Profit: %d\n", totalProfit);
}

int main() 
{
    Item items[] = 
    {
        {1, 10, 20, 0},
        {2, 20, 30, 0},
        {3, 30, 66, 0},
        {4, 40, 40, 0},
        {5, 50, 60, 0}
    };
    printf("--- 0/1 Knapsack (Greedy) ---\n");
    knapsack01Greedy(items, 5, 100);

    printf("\n--- Job Scheduling ---\n");
    Job jobs[] = 
    {
        {1, 20, 3},
        {2, 15, 1},
        {3, 10, 1},
        {4,  7, 3},
        {5,  5, 1},
        {6,  3, 3}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);
    jobScheduling(jobs, n);
    return 0;
}
