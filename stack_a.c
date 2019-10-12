#include <stdio.h>

#define MAX	10


int stack[MAX] = {0,};
int top;

void init_stack(void) {
	top = -1;
}

int push(int k) {
	if(top >= MAX) {
		printf("stack overflow...\n");
		return 0;
	}
	stack[++top] = k;
	return 1;
}

int pop(void) {
	if(top < 0) {
		printf("\nstack underflow...\n");
		return 0;
	}
	return stack[top--];
}

void print_stack() {
	printf("------------stack-------------\n");
	for(int i=0; i<top+1; i++)
		printf("stack[%d] = %-8d\n", i, stack[i]);
	printf("\n");
}

int main(int argc, char** argv) {

	init_stack();

	push(5);
	push(4);
	push(3);
	push(2);

	print_stack();

	printf("pop() ... %d\n", pop());
	printf("pop() ... %d\n", pop());
	printf("pop() ... %d\n", pop());
	printf("pop() ... %d\n", pop());
	printf("pop() ... %d\n", pop());

	return 1;
}
