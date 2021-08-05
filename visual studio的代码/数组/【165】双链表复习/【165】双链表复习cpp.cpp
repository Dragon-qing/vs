#include<stdio.h>
#include<stdlib.h>
typedef struct node  {
	int data;
	node*prew;
	node*next;
}node;
node*getnode(int item, node*p, node*n)
{
	node*l = (node*)malloc(sizeof(node));
	l->data = item;
	l->next = n;
	l->prew = p;
	return l;
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
	l->tail->prew = l->head;
}
void print(list*l)
{
	node*p = l->head->next;
	if(p!=l->tail )
	{
		while (p!=l->tail)
		{
			printf("%d\t", p->data);
			p = p->next;
		}
	}
	printf("\n");
}
void insert(int item,list*l)
{
	node*x = getnode(item, l->head ->next->prew  , l->head ->next );
	l->head->next = x;
	x->next->prew = x;
}
int main()
{
	list l;
	initlist(&l);
	insert(1, &l);
	insert(2, &l);
	insert(3, &l);
	insert(5, &l);
	insert(8, &l);
	insert(9, &l);
	insert(56, &l);
	print(&l);
	system("pause");
	return 0;
}