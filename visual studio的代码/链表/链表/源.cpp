#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node*next;
	struct node*prev;
};
typedef struct node node;
node*getnode(int item, node*n, node*p) {
	node*l;
	l = (node*)malloc(sizeof(node));
	l->data = item;
	l->next = n;
	l->prev = p;
	return l;
}
int getdata(node*l) { return l->data; }
node*getnext(node*l) { return l->next; }
node*getprev(node*l) { return l->prev; }
typedef struct {
	node*head;
	node*tail;
	int size;
}list;
void initlist(list*l) {
	l->head = NULL;
	l->tail = NULL;
	l->head->next = l->tail;
	l->tail->prev = l->head;
	l->size = 0;
}//½¨¿Õ±í
int main()
{
	node*p=getnode(12, NULL, NULL);
	printf("%d\n", getdata(p));
	printf("%d\n", getprev(p));
	printf("%d\n", getnext(p));
	system("pause");
	return 0;
}