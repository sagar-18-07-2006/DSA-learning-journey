#include <stdio.h>

void insertion_sort(int list[], int size) {
    int i, j, item;

    for (i = 1; i < size; i++) {
        item = list[i];
        j = i - 1;

        // shift elements greater than item
        while (j >= 0 && list[j] > item) {
            list[j + 1] = list[j];
            j--;
        }

        // insert the item at correct position
        list[j + 1] = item;
    }
}

int main() {
    int arr[] = {10, 5, 0, 4, 3, 8, 2, 6};

    insertion_sort(arr, 8);

    for (int i = 0; i < 8; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
