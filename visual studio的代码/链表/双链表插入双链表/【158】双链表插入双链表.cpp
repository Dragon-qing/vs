#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	node*prev;
	node*next;
}node;
typedef struct {
	node*head;
	node*tail;
	int size;
}list;
node*getnode(int item,node*p,node*n)
{
	node*l = (node*)malloc(sizeof(node));
	l->data = item;
	l->next = n;
	l->prev = p;
	return l;
}
void initlist(list*l)
{
	l->head = getnode(0, NULL, NULL);
	l->tail = getnode(0, NULL, NULL);
	l->size = 0;
	l->head->next = l->tail;
	l->tail->prev = l->head;
}
void insert(int data, list*l)
{
	node*n = getnode(data, l->head,l->head ->next );
	l->head->next->prev = n;
	l->head->next = n;
	l->size++;
}
void print(list*l)
{
	node*p = l->head->next;
	if (p != l->tail) {
		while (p != l->tail) { printf("%d\t", p->data); p = p->next; }
		printf("\n");
	}
}
void size(list*l) { printf("链表中有%d个节点\n", l->size); }
void insertlist(list*l, list*s)
{
	s->tail->prev->next = l->head->next;
	l->head->next->prev = s->tail->prev;
	s->head->next->prev = l->head;
	l->head->next = s->head->next;
	s->head->next = s->tail;
	s->tail->prev = s->head;
	l->size = l->size + s->size;
	if (s->head->next == s->tail&&s->tail->prev == s->head) { printf("s为空表\n"); }
}
int main()
{
	list l;
	list s;
	initlist(&l);
	initlist(&s);
	insert(1, &l);
	insert(2, &l);
	insert(3, &l); 
	insert(4, &l);
	insert(5, &l);
	print(&l);
	size(&l);
	insert(55, &s);
	insert(84, &s);
	insert(102, &s);
	insert(36, &s);
	insert(595, &s);
	insert(55, &s);
	print(&s);
	size(&s);
	insertlist(&l, &s);
	print(&l);
	size(&l);
	system("pause");
	return 0;
}