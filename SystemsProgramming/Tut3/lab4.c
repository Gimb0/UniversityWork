#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef  char  stackitem;

struct  stack
{
	stackitem   d;
	struct  stack *next;

};

typedef   struct  stack  ELEMENT;
typedef   ELEMENT    *POINTER;

// Push character onto stack
void push(POINTER *Top, stackitem a) {
	POINTER temp; // temp element
	temp = malloc(sizeof(ELEMENT)); // pointer temp now points to a space in the heap
	temp->d = a; //
	temp->next = *Top;
	*Top = temp;
	printf("Inserted %c in stack\n", a);
}

// Pop item off stack
void pop(POINTER *top) {
	POINTER temp = *top;
	if(top != NULL) {
		*top = temp->next;
		free(temp);
	} else {
		printf("Stack is empty.\n");
	}
}

// Push multiple characters
void push_string(POINTER *Top,char *string) {
	for(int i = 0; i < strlen(string); i++) {
		push(Top, string[i]);
	}
	return;
}

void print_stack(POINTER Top) {
	POINTER temp = Top;
	while(temp->next != NULL) {
		printf("Value: %c\n", temp->d);
		temp = temp->next;
	}
	printf("Value: %c\n", temp->d);
}

void delete_stack(POINTER *Top) {
	POINTER temp = *Top;
	printf("Test: %c\n", temp->d);
	while(temp->next != NULL) {
		pop(&temp);
	}
}

int main() {
	POINTER top;
	top = (POINTER) NULL;
	stackitem A = 'A';
	stackitem B = 'B';
	stackitem *C = "CDEF";
	push(&top, A);
	push(&top, B);
	push_string(&top, C);
	pop(&top);
	push(&top, 'S');
	print_stack(top);
	delete_stack(&top);
	printf("Stack deleted\n");
}
