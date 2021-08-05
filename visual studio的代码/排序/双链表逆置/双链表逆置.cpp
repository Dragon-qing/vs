#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node*next;
	struct node*prev;
};
typedef struct node node;
node*getnode(int item, node*p, node*n)
{
	node*l = (node*)malloc(sizeof(node));
	l->data = item;
	l->next = n;
	l->prev = p;
	return l;
}
typedef struct  {
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
void insert(int item, list*l)
{
	node*n = getnode(item, l->head, l->head->next);
	l->tail->prev = n;
	l->head->next = n;
}
void print(list*l)
{
	node*p = l->head->next;
	while (p!=l->tail )
	{
		printf("%d\t", p->data);
		p = p->next;
	}
}
list* re(list*l)
{
	list*n;
	node*p = l->head->next;
	node*t = l->tail->prev;
	n->head->next = t;
	t->
		return n;
}
int main()
{
	list l;
	initlist(&l);
	insert(1, &l);
	insert(2, &l);
	insert(3, &l);
	insert(4, &l);
	insert(5, &l);
	insert(6, &l);
	print(&l);
	system("pause");
	return 0;
}