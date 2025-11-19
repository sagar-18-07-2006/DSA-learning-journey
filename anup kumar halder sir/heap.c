#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int index) {
    int parent = index / 2;
    while (index > 1 && heap[parent] < heap[index]) {
        swap(&heap[parent], &heap[index]);
        index = parent;
        parent = index / 2;
    }
}

void insert(int val) {
    if (size >= MAX - 1) return;
    heap[++size] = val;
    heapifyUp(size);
}

void heapifyDown(int index) {
    int largest = index;
    int left = index * 2;
    int right = index * 2 + 1;

    if (left <= size && heap[left] > heap[largest])
        largest = left;

    if (right <= size && heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        heapifyDown(largest);
    }
}

int deleteRoot() {
    if (size == 0) return -1;
    int root = heap[1];
    heap[1] = heap[size--];
    heapifyDown(1);
    return root;
}

void buildHeap() {
    for (int i = size / 2; i >= 1; i--)
        heapifyDown(i);
}

void printArray() {
    for (int i = 1; i <= size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

void printTree(int index, int space) {
    if (index > size) return;
    space += 6;
    printTree(index * 2 + 1, space);
    printf("\n");
    for (int i = 6; i < space; i++) printf(" ");
    printf("↳ %d\n", heap[index]);
    printTree(index * 2, space);
}

int main() {
    int choice, x, n;

    while (1) {
        printf("\n1 Insert\n2 Delete Root\n3 Build Heap\n4 Print Array\n5 Print Tree\n6 Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Value: ");
            scanf("%d", &x);
            insert(x);
        }
        else if (choice == 2) {
            int r = deleteRoot();
            if (r == -1) printf("Empty\n");
            else printf("Deleted: %d\n", r);
        }
        else if (choice == 3) {
            printf("How many values? ");
            scanf("%d", &n);
            size = n;
            for (int i = 1; i <= n; i++) scanf("%d", &heap[i]);
            buildHeap();
        }
        else if (choice == 4) {
            printArray();
        }
        else if (choice == 5) {
            printf("\n");
            printTree(1, 0);
        }
        else if (choice == 6) break;
    }

    return 0;
}
