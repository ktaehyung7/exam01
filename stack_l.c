#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int key;
	struct _node *next;
} node;

node *head, *tail;

void init_stack(void) {
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->next = tail;  
	tail->next = tail;  
}

int push(int k) {
	node *t;
	t = (node*)malloc(sizeof(node));
	t->key = k;
	t->next = head->next;
	head->next = t;

	return k;
}

int pop(void) {
	node *t;
	int a;

	t = head->next;
	if(t == tail) {
		printf("stack underflow\n");
		return -1;
	}
	a = t->key;
	head->next = t->next;
	
	free(t);

	return a;
}

void print_stack(node *t) {
	printf("----------stack---------\n");
	while(t != tail) {
		printf("%-8d", t->key);
		t=t->next;
	}
}

void clear_stack(void) {
	node *p, *s;
	p = head->next;
	while(p != tail) {
		s=p;
		p=p->next;
		free(s);
	}
	head->next = tail;
}

int main(int argc, char** argv) {
	init_stack();

	push(3);
	push(2);
	push(1);

	print_stack(head->next);

	clear_stack();

	printf("\nafter clear_stack...\n");
	print_stack(head->next);

	push(3);
	push(2);
	push(1);

	print_stack(head->next);

	printf("\npop()... %d\n", pop());
	printf("\npop()... %d\n", pop());
	printf("\npop()... %d\n", pop());
	printf("\npop()... %d\n", pop());

	return 1;
}
