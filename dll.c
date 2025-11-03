#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;
struct Node* tail = NULL;

void insertFirst(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL) head->prev = newNode;
    else tail = newNode;
    head = newNode;
}

void insertLast(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;
    if (tail != NULL) tail->next = newNode;
    else head = newNode;
    tail = newNode;
}

void deleteNode(int value) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with data %d not found.\n", value);
        return;
    }
    if (temp == head) {
        head = temp->next;
        if (head != NULL) head->prev = NULL;
        else tail = NULL;
    } else if (temp == tail) {
        tail = temp->prev;
        tail->next = NULL;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Node with data %d deleted.\n", value);
}

void searchNode(int value) {
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
        position++;
    }
    if (temp == NULL) {
        printf("Node with data %d not found.\n", value);
    } else {
        printf("Node with data %d found at position %d.\n", value, position);
    }
}

void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;
    do {
        printf("\nDoubly Linked List Menu\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete Node\n");
        printf("4. Search Node\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertFirst(value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertLast(value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchNode(value);
                break;
            case 5:
                displayList();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 7);
    return 0;
}
