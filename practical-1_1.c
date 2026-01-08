#include<stdio.h>
#include<stdlib.h>

void bubblesort(int xarr[], int n)
{
    int is_swapped, count = 0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(xarr[j]>xarr[j+1])
            {
                count++;
                is_swapped = 1;
                int temp = xarr[j];
                xarr[j] = xarr[j+1];
                xarr[j+1] = temp;
            }
        }
        printf("%d", count);
        if(is_swapped == 0)
        {
            printf("Elements are sorted.");
            break;
        }
    }
}

void printArray(int arr[], int n) 
{
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}   

int main()
{
    int xarr[50], n, m;
    printf("Enter the number of values in the array: ");
    scanf("%d", &m);
    printf("Enter the values in the array: \n");
    for(int i = 0; i < m; i++)
    {
        printf("Value %d: ", i+1);
        scanf("%d", &xarr[i]);
    }
    bubblesort(xarr, m);
    printArray(xarr, m);
    return 0;
}