#include <stdio.h>
#include <stdlib.h>

typedef struct _dnode {
	int key;
	struct _dnode *prev;
	struct _dnode *next;
} dnode;

dnode *head, *tail;

void init_dlist(void) {
	head = (dnode*)malloc(sizeof(dnode));
	tail = (dnode*)malloc(sizeof(dnode));
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
}

dnode* find_dnode(int k) {
	dnode *s;
	s = head->next;
	while(s->key != k && s != tail) {
		s=s->next;
	}
	return s;
}

dnode* insert_dnode_ptr(int k, dnode* t) {
	dnode *i;
	if(t == head) return NULL;
	i = (dnode*)malloc(sizeof(dnode));
	i->key = k;
	t->prev->next = i; t->prev= i; 
 	i->prev = t->prev; i->next = t;

	return i;
}

dnode* insert_dnode(int k, int t) {
	dnode *s, *i;

	s = find_dnode(t);
	i = (dnode*)malloc(sizeof(dnode));
	i->key = k;
	s->prev->next = i; i->prev = s->prev;
	s->prev = i; i->next = s; 

	return i;
}

dnode* ordered_insert(int k) {
	dnode *s, *i;

	s = head->next;
	while(s->key <= k && s != tail) {
		s=s->next;
	}
	i = (dnode*)malloc(sizeof(dnode));
	i->key = k;
	s->prev->next = i; i->prev = s->prev;
	s->prev = i; i->next = s; 

	return i;
}

int delete_dnode_ptr(dnode *p) {
	if(p == head || p == tail)
		return 0;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);

	return 1;
}

int delete_dnode(int k) {
	dnode *s;

	s = find_dnode(k);
	if(s !=tail) {
		s->prev->next = s->next;
		s->next->prev = s->prev;
		free(s);
	}

	return 1;
}

void print_dlist(dnode* t) {
	printf("\n==========print dlist===========\n");
	while(t != tail) {
		printf("%-8d", t->key);
		t=t->next;
	}
	printf("\n");
}

int main(int argc, char** argv) {

	init_dlist();

	ordered_insert(3);
	ordered_insert(4);
	ordered_insert(1);
	ordered_insert(2);

	print_dlist(head->next);

	delete_dnode(2);
	print_dlist(head->next);

	return 0;
}
