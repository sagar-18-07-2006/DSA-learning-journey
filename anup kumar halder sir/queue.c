#include <stdio.h>
#include <stdlib.h>

int *queue;
int front = -1, rear = -1;
int MAX = 0;


void create(int size) {
    if (queue != NULL) free(queue);
    MAX = size;
    queue = (int*)malloc(MAX * sizeof(int));
    front = rear = -1;
    printf("Queue of size %d created successfully!\n", MAX);
}


int isEmpty() {
    return (front == -1 || front > rear);
}


int isFull() {
    return rear == MAX - 1;
}

void enqueue(int value) {
    if (MAX == 0) {
        printf("Please create a queue first!\n");
        return;
    }
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
    } else {
        if (front == -1) front = 0;
        queue[++rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}


int dequeue() {
    if (MAX == 0) {
        printf("Please create a queue first!\n");
        return -1;
    }
    if (isEmpty()) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    } else {
        int val = queue[front++];
        if (front > rear) front = rear = -1; 
        return val;
    }
}


int peek() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue[front];
}


void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, val, size;
    queue = NULL;

    while (1) {
        printf("\n--- Queue Menu (Array) ---\n");
        printf("1. Create Queue\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
        printf("4. Peek\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter size of queue: ");
                scanf("%d", &size);
                create(size);
                break;
            case 2:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 3:
                val = dequeue();
                if (val != -1) printf("Dequeued: %d\n", val);
                break;
            case 4:
                val = peek();
                if (val != -1) printf("Front element: %d\n", val);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                if (queue != NULL) free(queue);
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
