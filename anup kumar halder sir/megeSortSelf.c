#include <stdio.h>

// Function to display array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("The %d element: %d\n", i + 1, arr[i]);
    }
}

// Function to merge two halves
void mergeSort(int arr[], int start, int mid, int end) {
    int temp[end - start + 1];
    int i = start, j = mid + 1, k = 0;

    // Merge the two halves into temp[]
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements of left half
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements of right half
    while (j <= end) {
        temp[k++] = arr[j++];
    }

    // Copy sorted elements back into original array
    for (int h = start; h <= end; h++) {
        arr[h] = temp[h - start];
    }
}
void mergeInPlace(int arr[], int start, int mid, int end) {
    int i = start;
    int j = mid + 1;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            i++;
        } else {
            int value = arr[j];
            int index = j;

            // Shift all elements between i and j-1 one step right
            while (index > i) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[i] = value;

            // Update all pointers
            i++;
            mid++;
            j++;
        }
    }
}
// Recursive merge function
void merge(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        merge(arr, start, mid);
        merge(arr, mid + 1, end);
        mergeSort(arr, start, mid, end);
    }
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements you want to add in the array: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the %d element: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nThe Original Array:\n");
    display(arr, n);

    merge(arr, 0, n - 1);

    printf("\nThe Sorted Array:\n");
    display(arr, n);

    return 0;
}
