#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
        struct Node* next;
};
 
struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue() {
	int value;
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (!newNode) {
		printf("Memory allocation failed!\n");
		return;
	}
	printf("Enter value to enqueue: ");
	scanf("%d", &value);
	newNode->data = value;
	newNode->next = NULL;
	if (rear == NULL) {
		front = rear = newNode;
	} 
	else {
		rear->next = newNode;
		rear = newNode;
	}
	printf("%d enqueued to queue.\n", value);
}

void dequeue() {
	if (front == NULL) {
		printf("Queue Underflow!\n");
		return;
	}
	int value = front->data;
	front = front->next; 
	 if (front == NULL) rear = NULL;
		printf("%d dequeued from queue.\n", value);
}

void display() {
	if (front == NULL) {
		printf("Queue is empty!\n");
		return;
	}

	struct Node* temp = front;
	printf("Queue elements: ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	int choice;
	while (1) {
		printf("\n    Queue using Linked List    \n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				enqueue();
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
				printf("Invalid choice! Try again.\n");
		}
	}
	return 0;
}
