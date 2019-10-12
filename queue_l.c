#include <stdio.h>
#include <stdlib.h>


typedef struct _dnode {
	int key;
	struct _dnode *prev;
	struct _dnode *next;

} dnode;

dnode *head, *tail;

void init_queue(void) {
	head = (dnode*)malloc(sizeof(dnode));
	tail = (dnode*)malloc(sizeof(dnode));
	head->next = tail; head->prev = head;
	tail->next = tail; tail->prev = head;
}

int put(int k) {
	dnode *t;
	t = (dnode*)malloc(sizeof(dnode));
	t->key = k;
	tail->prev->next = t; t->prev = tail->prev;
	tail->prev = t; t->next = tail;	

	return k;
}

int get(void) {
	dnode *t;
	int a;

	t= head->next;
	if(t == tail) {
		printf("\nQueue Underflow..\n");
		return -1;
	}

	a = t->key;
	head->next = t->next;
	t->next->prev = head;
	free(t);

	return a;
}

void print_queue(dnode* t) {
	printf("\n-----------------queue--------------\n");
	while(t!=tail) {
		printf("%-8d", t->key);
		t=t->next;
	}	
}

int main(int argc, char** argv) {
	init_queue();

	put(5);
	put(6);
	put(7);
	put(8);

	print_queue(head->next);

	printf("\nget()....%d\n", get());
	printf("\nget()....%d\n", get());
	printf("\nget()....%d\n", get());
	printf("\nget()....%d\n", get());
	printf("\nget()....%d\n", get());

	return 1;
}
