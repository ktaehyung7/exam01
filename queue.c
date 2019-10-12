#include <stdio.h>
#include <stdlib.h>

#define MAX	10

int queue[MAX];
int front, rear;

void init_queue() {
	front = rear = 0;
}

void clear_queue() {
	front = rear;
}

int put(int k) {
	if(front == (rear+1)%MAX ) {
		printf("\nQueue overflow..\n");
		return -1;
	}
	queue[rear] = k;
	rear = ++rear % MAX;

	return k;
}

int get() {
	int i;
	if(front == rear) {
		printf("\nQueue underflow..\n");
		return -1;
	}
	i = queue[front];
	front = ++front % MAX;

	return i;
}

void print_queue(void) {
	printf("\n---------------Queue--------------\n");
	for(int i=front; i != rear; i=++i%MAX)
		printf("%-8d", queue[i]);
}

int main(int argc, char** argv) {
	init_queue();

	put(3);
	put(4);
	put(5);

	print_queue();

	printf("\nget()...%d\n", get());
	printf("\nget()...%d\n", get());
	printf("\nget()...%d\n", get());
	printf("\nget()...%d\n", get());

	clear_queue();
	print_queue();

	return 0;
}
