#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int key;
	struct _node *next;
} node;

node *head, *tail;

void init_list(void) {
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->next = tail;
	tail->next = tail;
}

node* insert_after(int k, node* t) {
	node *s;
	s = (node*)malloc(sizeof(node));
	s->key = k;
	s->next = t->next;
	t->next = s;

	return s;
}

int delete_next(node *t) {
	node *s;
	if(t->next == tail)
		return 0;
	s = t->next;
	t->next = t->next->next;
	free(s);
	return 1;
}

int delete_node(int k) {
	node *s, *p;
	p = head;
	s = p->next;
	while(s->key != k && s !=tail) {
		p = p->next;
		s = p->next;
	}
	if(s != tail) {
		p->next = s->next;
		free(s);
		return 1;
	} else
		return 0;
}

node* find_node(int k) {
	node *s;
	s = head->next;
	while(s->key != k && s !=tail)
		s = s->next;

	return s;
}

node *insert_node(int t, int k) {
	node *s, *p, *r;
	p = head;
	s = p->next;
	while(s->key != k && s != tail) {
		p = p->next;
		s = p->next;
	}
	if(s != tail) {
		r = (node*)malloc(sizeof(node));		
		r->key = t;
		r->next = p->next;
		p->next = r;	
	} else

	return p->next;
}

void print_list(node *t) {
	printf("\n");
	while(t!=tail) {
		printf("%-8d", t->key);
		t = t->next;
	}
	printf("\n");
}

node *delete_all(void) {
	node *s, *p;
	p = head->next;
	while(p != tail) {
		s = p;
		p = p->next;
		free(s);	
	}
	head->next = tail;

	return head;
}

int main(int argc, char** argv) {

	node *tmp;

	init_list();
	insert_after(2, head);
	insert_after(5, head);
	insert_after(4, head);
	insert_after(7, head);
	insert_after(8, head);
	
	delete_node(4);

	insert_node(9, 5);

	print_list(head->next);

	tmp = find_node(7);
	printf("Find node 7 and delete_next...\n");
	delete_next(tmp);
	print_list(head->next);

	delete_all();

	printf("after delete_all()...\n");
	print_list(head->next);

	return 0;
}
