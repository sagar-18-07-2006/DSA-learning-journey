#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


void insertBegin(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}


void insertEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}


void insertByPosition(int pos, int value) {
    struct Node* newNode = createNode(value);
    if (pos == 1) {
        insertBegin(value);
        return;
    }

    struct Node* temp = head;
    int count = 1;

    if (head == NULL) {
        printf("List is empty, inserting at position 1\n");
        head = newNode;
        newNode->next = head;
        return;
    }

    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (count < pos - 1) {
        printf("Position %d is out of range\n", pos);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


void deleteValue(int value) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    if (head->data == value) {
        if (head->next == head) {
            free(head);
            head = NULL;
            return;
        }
        struct Node* last = head;
        while (last->next != head)
            last = last->next;

        struct Node* toDelete = head;
        last->next = head->next;
        head = head->next;
        free(toDelete);
        return;
    }

    do {
        prev = temp;
        temp = temp->next;
    } while (temp != head && temp->data != value);

    if (temp == head) {
        printf("Value not found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}


void deleteByPosition(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (pos == 1) {
        if (head->next == head) {
            free(head);
            head = NULL;
            return;
        }
        struct Node* last = head;
        while (last->next != head)
            last = last->next;

        struct Node* toDelete = head;
        last->next = head->next;
        head = head->next;
        free(toDelete);
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;
    int count = 1;

    while (count < pos && temp->next != head) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (count < pos) {
        printf("Position %d is out of range!\n", pos);
        return;
    }

    prev->next = temp->next;
    free(temp);
}


void search(int value) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == value) {
            printf("Found %d at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("Value %d not found!\n", value);
}


void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}


void freeList() {
    if (head == NULL) return;

    struct Node* temp = head->next;
    while (temp != head) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(head);
    head = NULL;
}

int main() {
    int choice, value, pos;
    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert by position\n");
        printf("4. Delete by value\n");
        printf("5. Delete by position\n");
        printf("6. Search\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBegin(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);
                insertByPosition(pos, value);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteValue(value);
                break;
            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteByPosition(pos);
                break;
            case 6:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 7:
                display();
                break;
            case 8:
                freeList();
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
