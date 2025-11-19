#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode *front, *rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Node* tn) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = tn;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

Node* dequeue(Queue* q) {
    if (q->front == NULL)
        return NULL;
    QueueNode* temp = q->front;
    Node* tn = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return tn;
}

int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

Node* createNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

Node* insertLevelOrder(Node* root, int val) {
    if (root == NULL)
        return createNode(val);

    Queue* q = createQueue();
    enqueue(q, root);

    while (!isQueueEmpty(q)) {
        Node* temp = dequeue(q);

        if (temp->left == NULL) {
            temp->left = createNode(val);
            return root;
        } else {
            enqueue(q, temp->left);
        }

        if (temp->right == NULL) {
            temp->right = createNode(val);
            return root;
        } else {
            enqueue(q, temp->right);
        }
    }

    return root;
}

Node* search(Node* root, int key) {
    if (root == NULL)
        return NULL;

    Queue* q = createQueue();
    enqueue(q, root);

    while (!isQueueEmpty(q)) {
        Node* temp = dequeue(q);

        if (temp->data == key)
            return temp;

        if (temp->left)
            enqueue(q, temp->left);

        if (temp->right)
            enqueue(q, temp->right);
    }

    return NULL;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return NULL;

    Node *keyNode = NULL, *lastNode = NULL, *parentLast = NULL;

    Queue* q = createQueue();
    enqueue(q, root);

    while (!isQueueEmpty(q)) {
        Node* temp = dequeue(q);

        if (temp->data == key)
            keyNode = temp;

        if (temp->left) {
            parentLast = temp;
            enqueue(q, temp->left);
        }
        if (temp->right) {
            parentLast = temp;
            enqueue(q, temp->right);
        }

        lastNode = temp;
    }

    if (keyNode) {
        keyNode->data = lastNode->data;

        if (parentLast->right == lastNode)
            parentLast->right = NULL;
        else
            parentLast->left = NULL;

        free(lastNode);
    }

    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void printTree(Node* root, int space) {
    if (root == NULL)
        return;

    space += 7;
    printTree(root->right, space);

    printf("\n");
    for (int i = 7; i < space; i++)
        printf(" ");
    printf("↳ %d\n", root->data);

    printTree(root->left, space);
}

int main() {
    Node* root = NULL;
    int choice, val;

    while (1) {
        printf("\n1.Insert\n2.Search\n3.Delete\n4.Inorder\n5.Preorder\n6.Postorder\n7.Print Tree\n8.Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            root = insertLevelOrder(root, val);
            break;

        case 2:
            printf("Enter value to search: ");
            scanf("%d", &val);
            if (search(root, val))
                printf("%d found\n", val);
            else
                printf("%d not found\n", val);
            break;

        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            root = deleteNode(root, val);
            break;

        case 4:
            inorder(root);
            printf("\n");
            break;

        case 5:
            preorder(root);
            printf("\n");
            break;

        case 6:
            postorder(root);
            printf("\n");
            break;

        case 7:
            printTree(root, 0);
            printf("\n");
            break;

        case 8:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}
