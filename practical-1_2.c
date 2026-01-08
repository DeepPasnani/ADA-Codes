#include<stdio.h>
#include<stdlib.h>

void selectionsort(int arr[], int n) 
{
    int is_swapped = 0, i, j, min, temp;
    for (i = 0; i < n-1; i++) 
    {
        min = i;
        for (j = i+1; j < n; j++) 
        {
            if (arr[j] < arr[min]) 
            {
                min = j;
                is_swapped = 1;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
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
    selectionsort(xarr, m);
    printArray(xarr, m);
    return 0;
}
