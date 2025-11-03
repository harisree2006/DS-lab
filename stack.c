#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX];
int top = -1;

int isFull();
int isEmpty();
void push();
void pop();
void peek();
void display();

void main()
{
    int choice;

    while (1)
    {
        printf("\n STACK OPERATIONS USING ARRAY \n");
        printf("1. PUSH\n2. POP\n3. PEEK\n4. IS FULL\n5. IS EMPTY\n6. DISPLAY\n7. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            if (isFull())
                printf("Stack is Full.\n");
            else
                printf("Stack is not Full.\n");
            break;

        case 5:
            if (isEmpty())
                printf("Stack is Empty.\n");
            else
                printf("Stack is not Empty.\n");
            break;

        case 6:
            display();
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}

int isFull()
{
    return (top == MAX - 1);
}

int isEmpty()
{
    return (top == -1);
}

void push()
{
    int item;
    if (isFull())
    {
        printf("Stack Overflow! Cannot push element.\n");
    }
    else
    {
        printf("Enter the element to push: ");
        scanf("%d", &item);
        top++;
        stack[top] = item;
        printf("%d pushed into stack.\n", item);
    }
}

void pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow! No elements to pop.\n");
    }
    else
    {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void peek()
{
    if (isEmpty())
    {
        printf("Stack is Empty! Nothing to peek.\n");
    }
    else
    {
        printf("Top element is: %d\n", stack[top]);
    }
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("Stack is Empty.\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
