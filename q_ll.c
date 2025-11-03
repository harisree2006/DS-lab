#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("%d enqueued to queue\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow! Queue is empty.\n");
    } else {
        struct node *temp = front;
        printf("%d dequeued from queue\n", front->data);
        front = front->next;
        if (front == NULL)
            rear = NULL;
        free(temp);
    }
}

void display() {
    struct node *temp = front;
    if (temp == NULL)
        printf("Queue is empty.\n");
    else {
        printf("Queue elements are:\n");
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void main() {
    int choice, value;
    while (1) {
        printf("\n QUEUE MENU \n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to be enqueued: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
}
