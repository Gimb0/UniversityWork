#include <stdio.h>
#include <stdlib.h>

typedef char DATA;
struct node {
	DATA d;
	struct node *next;
	struct node *prev;
};
	
struct node* head; //create head of linked list

struct node* getNewNode(char x) {
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	(*newNode).d = x;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

void insertAtHead(char x) {
	struct node* newNode = getNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	} else {
		struct node *temp = head;
		temp->prev = newNode;
		newNode->next = temp;
		head = newNode;
	}
	return;
}

void insertAtEnd(char x) {
	struct node *newNode = getNewNode(x);
	struct node *temp = head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}

void print() {
	struct node *temp = head;
	printf("Printing: \n");
	do {	
		printf("This element contains: %c and is at address %p\n", (*temp).d, &(*temp));
		temp = (*temp).next;
	} while((*temp).next != NULL);
	printf("This element contains: %c and is at address %p\n", (*temp).d, &(*temp));
	return;
}

void reversePrint() {
	struct node *temp = head;
	printf("Printing reverse: \n");
	while((*temp).next != NULL) {
		temp = temp->next;
	}
	while(temp != NULL) {
		printf("This element contains: %c and is at address %p\n", (*temp).d, &(*temp));
		temp = temp->prev;
	}
	return;
}

int main() {
	head = NULL;
	char list[5] = {'a', 'b', 'c', 'd', 'e'};
	for(int i = 0; i < 5; i++) {
		insertAtHead(list[i]);
	}
	insertAtEnd('x');

	print();

	reversePrint();

	return 0;
}
