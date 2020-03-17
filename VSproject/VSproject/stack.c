#include<stdio.h>
#include<stdlib.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

void push(int item) {
	if (top >= STACK_SIZE - 1) {
		printf("Stack is Full.\n");
		return;
	}
	
	stack[++top] = item;
}

int pop() {
	if (top == -1) {
		printf("Stack is Empty.\n");
		return 0;
	}
	
	return stack[top--];
}

int peek() {
	if (top == -1) {
		printf("Stack is Empty.\n");
		return 0;
	}

	return stack[top];
}

void printStack() {
	int i;

	for (i = 0; i <= top; i++)
		printf("%d ", stack[i]);
	puts("");
}

int main() {
	push(1);
	push(2);
	push(3);
	push(4);

	printStack(); // 1 2 3 4

	pop();
	pop();

	printStack(); // 1 2

	push(5);
	push(6);

	printStack(); // 1 2 5 6
	
	printf("stack top = %d", peek());

	return 0;
}