#include <stdio.h>
#include <stdlib.h>

int *stack;   
int top = -1;
int MAX = 0;


void create(int size) {
    if (stack != NULL) free(stack); 
    MAX = size;
    stack = (int *)malloc(MAX * sizeof(int));
    top = -1;
    printf("Stack of size %d created successfully!\n", MAX);
}

int isFull() {
    return top == MAX - 1;
}


int isEmpty() {
    return top == -1;
}


void enqueue(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot enqueue %d\n", value);
    } else {
        stack[++top] = value;
        printf("%d enqueued to stack\n", value);
    }
}


int dequeue() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot dequeue\n");
        return -1;
    } else {
        return stack[top--];
    }
}


int peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        return stack[top];
    }
}


void display() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}


int main() {
    int choice, val, size;
    stack = NULL; 
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Create Stack\n");
        printf("2. Enqueue (Push)\n");
        printf("3. Dequeue (Pop)\n");
        printf("4. Peek\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter size of stack: ");
                scanf("%d", &size);
                create(size);
                break;
            case 2:
                if (MAX == 0) {
                    printf("Please create a stack first!\n");
                } else {
                    printf("Enter value to enqueue: ");
                    scanf("%d", &val);
                    enqueue(val);
                }
                break;
            case 3:
                if (MAX == 0) {
                    printf("Please create a stack first!\n");
                } else {
                    val = dequeue();
                    if (val != -1)
                        printf("Dequeued: %d\n", val);
                }
                break;
            case 4:
                if (MAX == 0) {
                    printf("Please create a stack first!\n");
                } else {
                    val = peek();
                    if (val != -1)
                        printf("Top element: %d\n", val);
                }
                break;
            case 5:
                if (MAX == 0) {
                    printf("Please create a stack first!\n");
                } else {
                    display();
                }
                break;
            case 6:
                printf("Exiting...\n");
                if (stack != NULL) free(stack);
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
