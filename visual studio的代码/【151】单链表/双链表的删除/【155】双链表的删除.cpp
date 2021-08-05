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
	node*newnode = getnode(item, l->head, l->head->next);
	node*p = l->head->next;
	p->prev->next = newnode;
	p->prev = newnode;
	return newnode;
}
void printlist(list*l) {
	node*p = l->head->next;
	while (p) { printf("%d\t", p->data); p = p->next; }
	printf("\n");
} 
void deletelist(int x,list*l)
{
	node*p = l->head->next;
	//printf("\n%d\n", p->data);
	while (p->data != x) { p = p->next; if (p == NULL) { goto a; }; }
	a:
	if (p == NULL) { printf("Î´ÕÒµ½\n"); }
	else {
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
	}
}
int main()
{
	int x;
	list l;
	initlist(&l);
	insert(1, &l);
	insert(2, &l);
	insert(3, &l);
	insert(4, &l);
	insert(5, &l);
	insert(6, &l);
	printlist(&l);
	deletelist(5, &l);
	printlist(&l);
	deletelist(9, &l);
	deletelist(6, &l);
	printlist(&l);
	system("pause");
	return 0;
}