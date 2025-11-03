#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
    printf("%d pushed onto stack\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow! Stack is empty.\n");
    } else {
        struct node *temp = top;
        printf("%d popped from stack\n", top->data);
        top = top->next;
        free(temp);
    }
}

void peek() {
    if (top == NULL)
        printf("Stack is empty.\n");
    else
        printf("Top element is: %d\n", top->data);
}

void display() {
    struct node *temp = top;
    if (temp == NULL)
        printf("Stack is empty.\n");
    else {
        printf("Stack elements are:\n");
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
        printf("\n STACK MENU \n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to be pushed: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
}
