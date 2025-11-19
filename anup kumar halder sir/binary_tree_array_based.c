#include <stdio.h>
#define MAX 100

int tree[MAX];

void initTree() {
    for (int i = 0; i < MAX; i++)
        tree[i] = -1;
}

void insert(int data) {
    int i = 0;

    while (i < MAX) {
        if (tree[i] == -1) {
            tree[i] = data;
            printf("Inserted %d at index %d\n", data, i);
            return;
        }
        i++;
    }
    printf("Tree is full, cannot insert\n");
}

void display() {
    printf("\nArray Representation:\n");
    for (int i = 0; i < MAX; i++) {
        if (tree[i] != -1)
            printf("Index %d : %d\n", i, tree[i]);
    }
}

void printTree(int index, int space) {
    if (index >= MAX || tree[index] == -1)
        return;

    space += 5;

    printTree(2 * index + 2, space);

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", tree[index]);

    printTree(2 * index + 1, space);
}

int main() {
    initTree();

    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    display();

    printf("\nTree Structure:\n");
    printTree(0, 0);

    return 0;
}
