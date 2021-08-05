#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node*next;
};
typedef struct node node;
node*getnode(int item)
{
	node*n = (node*)malloc(sizeof(node));
	n->data = item;
	n->next = NULL;
	return n;
}
void list(node*l)
{
	l->data = 0;
	l->next = NULL;
}
void insert(node*l, int item)
{
	node*x = getnode(item);
	x->next = l->next;
	l->next = x;
}
void print(node*l)
{
	node*p = l->next;
	if (p) {
		while (p)
		{
			printf("%d\t", p->data);
			p = p->next;
		}
		printf("\n");
	}
}
node*re(node*l)
{
	node*temp = l->next;
	node*l2;
	l2 = getnode(0);
	while (temp ) { 
		l->next = temp->next;
		temp->next  = l2->next;
		l2->next = temp;
		temp  = l->next;
	}
	return l2;
}
int main()
{
	node*l = getnode(0);
	insert(l, 1);
	insert(l, 2);
	insert(l, 3);
	insert(l, 4);
	insert(l, 5);
	insert(l, 6);
	print(l);
	node*l2=re(l);
	print(l2);
	system("pause");
	return 0;
}