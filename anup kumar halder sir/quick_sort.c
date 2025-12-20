#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int list[], int low, int high)
{
    int pivot = list[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (i <= high && list[i] <= pivot)
            i++;

        while (j >= low && list[j] > pivot)
            j--;

        if (i < j)
            swap(&list[i], &list[j]);
    }

    // place pivot in correct location
    swap(&list[low], &list[j]);

    return j;
}

void qs(int list[], int low, int high)
{
    if (low < high)
    {
        int pindex = partition(list, low, high);
        qs(list, low, pindex - 1);
        qs(list, pindex + 1, high);
    }
}

int main()
{
    int arr[] = {10, 5, 0, 4, 3, 8, 2, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    qs(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);

    return 0;
}
