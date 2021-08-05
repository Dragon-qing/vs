#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	node*next;
	node*prev;
}node;
node*getnode(int x, node*p, node*n)
{
	node*newnode = (node*)malloc(sizeof(node));
	newnode->data = x;
	newnode->next = n;
	newnode->prev = p;
	return newnode;
}
typedef struct {
	node*head;
	node*tail;
}list;
void initlist(list*l)
{
	l->head = getnode(0, NULL, NULL);
	l->tail = getnode(0, NULL, NULL);
	l->head->next = l->tail;
	l->tail->prev = l->head;
}
void insert(list*l, int x)
{
	node*p = getnode(x, l->head, l->head->next);
	p->next ->prev  = p;
	l->head->next = p;
	
}
void prt(list*l)
{
	node*p = l->head->next;
	while (p != l->tail)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
int main()
{
	list l;
	initlist(&l);
	insert(&l, 1);
	insert(&l, 2);
	insert(&l, 3);
	insert(&l, 4);
	insert(&l, 5);
	insert(&l, 6);
	insert(&l, 7);
	prt(&l);
	system("pause");
	return 0;
}