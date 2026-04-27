#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    Job jobs[] = 
    {
        {1, 100, 2},
        {2, 19, 1},
        {3, 27, 2},
        {4, 25, 1},
        {5, 15, 3}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);
    jobScheduling(jobs, n);
    return 0;
}
