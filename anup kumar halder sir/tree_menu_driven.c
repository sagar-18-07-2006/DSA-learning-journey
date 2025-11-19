#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node* insertRandom(Node* root, int data) {
    if (root == NULL) return createNode(data);
    Node* temp = root;
    while (1) {
        int r = rand() % 2;
        if (r == 0) {
            if (temp->left == NULL) {
                temp->left = createNode(data);
                break;
            }
            temp = temp->left;
        } else {
            if (temp->right == NULL) {
                temp->right = createNode(data);
                break;
            }
            temp = temp->right;
        }
    }
    return root;
}

Node* insertLeft(Node* root, int parent, int data) {
    if (root == NULL) return NULL;
    if (root->data == parent && root->left == NULL) {
        root->left = createNode(data);
        return root;
    }
    insertLeft(root->left, parent, data);
    insertLeft(root->right, parent, data);
    return root;
}

Node* insertRight(Node* root, int parent, int data) {
    if (root == NULL) return NULL;
    if (root->data == parent && root->right == NULL) {
        root->right = createNode(data);
        return root;
    }
    insertRight(root->left, parent, data);
    insertRight(root->right, parent, data);
    return root;
}

int search(Node* root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;
    return search(root->left, key) || search(root->right, key);
}

int countNodes(Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int height(Node* root) {
    if (root == NULL) return 0;
    int h1 = height(root->left);
    int h2 = height(root->right);
    return (h1 > h2 ? h1 : h2) + 1;
}

void printTree(Node* root, int space) {
    if (root == NULL) return;
    space += 6;
    printTree(root->right, space);
    printf("\n");
    for (int i = 6; i < space; i++) printf(" ");
    printf("↳ %d\n", root->data);
    printTree(root->left, space);
}

int main() {
    srand(time(0));
    Node* root = NULL;
    int choice, n, x, p;

    while (1) {
        printf("\n1 Random Insert\n2 Insert Left\n3 Insert Right\n4 Search\n5 Count\n6 Height\n7 Print\n8 Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("How many random nodes? ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                int val = rand() % 100;
                root = insertRandom(root, val);
            }
        }
        else if (choice == 2) {
            printf("Parent value: ");
            scanf("%d", &p);
            printf("Insert value: ");
            scanf("%d", &x);
            root = insertLeft(root, p, x);
        }
        else if (choice == 3) {
            printf("Parent value: ");
            scanf("%d", &p);
            printf("Insert value: ");
            scanf("%d", &x);
            root = insertRight(root, p, x);
        }
        else if (choice == 4) {
            printf("Search value: ");
            scanf("%d", &x);
            printf(search(root, x) ? "Found\n" : "Not Found\n");
        }
        else if (choice == 5) {
            printf("Total nodes: %d\n", countNodes(root));
        }
        else if (choice == 6) {
            printf("Height: %d\n", height(root));
        }
        else if (choice == 7) {
            printf("\n");
            printTree(root, 0);
            printf("\n");
        }
        else if (choice == 8) {
            break;
        }
    }

    return 0;
}
