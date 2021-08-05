#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*prev;
	struct node*next;
};
typedef struct node node;
typedef struct {
	node*head;
	node*tail;
	int size;
}list;
node*getnode(int item, node*p, node*n)
{
	node*l = (node*)malloc(sizeof(node));
	l->data = item;
	l->prev = p;
	l->next = n;
	return l;
}
node*getprev(node*l) { return l->prev; }
node*getnext(node*l) { return l->next; }
void initlist(list*l) {
	l->head = getnode(0, NULL, NULL);
	l->tail = getnode(0, NULL, NULL);
	l->head->next = l->tail;
	l->tail->prev = l->head;
	l->size = 0;
}
node*insert(int item, list*l)
{
	node*newnode = getnode(item, l->head, l->head->next );
	node*p = l->head->next ;
	p->prev->next = newnode;
	p->prev = newnode;
	return newnode;
}
void printlist(list*l) {
	node*p = l->head->next;
	while (p) { printf("%d\t", p->data); p = p->next; }
}
int main()
{
	int x;
	list l;
	initlist(&l);
	scanf_s("%d", &x);
	while (x != 0) {
		insert(x, &l);
		scanf_s("%d", &x);
	}
	printlist(&l);
	system("pause");
	return 0;
}