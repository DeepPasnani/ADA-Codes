#include <stdio.h>
#include <time.h>
#define N 10

void merge(int arr[], int l, int m, int r) 
{
    int left[N], right[N];
    int n1 = m - l + 1;
    int n2 = r - m;

    for (int i = 0; i < n1; i++) left[i]  = arr[l + i];
    for (int j = 0; j < n2; j++) right[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];
}

void mergeSort(int arr[], int l, int r) 
{
    if (l < r) 
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) 
    {
        if (arr[j] <= pivot) 
        {
            i++;
            int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
        }
    }
    int tmp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = tmp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void) 
{
    int a[] = {64, 25, 12, 78, 43, 91, 5, 37, 56, 19};
    int b[] = {64, 25, 12, 78, 43, 91, 5, 37, 56, 19};

    clock_t start, end;

    printf("Original  : ");
    printArray(a, N);

    start = clock();
    mergeSort(a, 0, N - 1);
    end = clock();
    printf("Merge Sort: ");
    printArray(a, N);
    printf("  Time: %lf seconds\n\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    quickSort(b, 0, N - 1);
    end = clock();
    printf("Quick Sort: ");
    printArray(b, N);
    printf("  Time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
