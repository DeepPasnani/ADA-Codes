#include <stdio.h>

int linearSearch(int arr[], int n, int target) 
{
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int target) 
{
    int low = 0, high = n - 1;

    while (low <= high) 
    {
        int mid = low + (high - low) / 2;   
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;  
        else
            high = mid - 1;  
    }
    return -1;
}

void printArray(int arr[], int n) 
{
    printf("[ ");
    for (int i = 0; i < n; i++)
        printf("%d%s", arr[i], i < n - 1 ? ", " : " ");
    printf("]\n");
}

void printResult(const char *algo, int target, int index) 
{
    if (index != -1)
        printf("  %-15s => found %d at index %d\n", algo, target, index);
    else
        printf("  %-15s => %d not found\n", algo, target);
}

int main(void) 
{
    int arr[] = {3, 7, 11, 19, 24, 35, 42, 56, 68, 74};
    int n     = sizeof(arr) / sizeof(arr[0]);

    int targets[] = {24, 99};  
    int numTargets = sizeof(targets) / sizeof(targets[0]);

    printf("Array: ");
    printArray(arr, n);
    printf("Size : %d\n\n", n);

    for (int t = 0; t < numTargets; t++) 
    {
        int target = targets[t];
        printf("Searching for %d:\n", target);

        int li = linearSearch(arr, n, target);
        int bi = binarySearch(arr, n, target);

        printResult("Linear Search", target, li);
        printResult("Binary Search", target, bi);
        printf("\n");
    }

    int unsorted[] = {42, 7, 99, 3, 55, 18};
    int un = sizeof(unsorted) / sizeof(unsorted[0]);

    printf("Unsorted array: ");
    printArray(unsorted, un);
    printf("Searching for 55 (linear only, array is unsorted):\n");
    printResult("Linear Search", 55, linearSearch(unsorted, un, 55));

    return 0;
}
