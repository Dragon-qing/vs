#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node*next;
};
typedef struct node node;
node*getnode(int item) {
	node*newnode = (node*)malloc(sizeof(node));
	newnode->data = item;
	newnode->next = NULL;
	return newnode;
}
node*list() {
	node*headnode = getnode(0);
	return headnode;
}
void insert(int item, node*headnode)
{
	node*s = getnode(item);
	s->next = headnode->next;
	headnode->next = s;
}
void print(node*l) {
	node*p = l->next;
	if (p != NULL)
	{
		while (p) { printf("%d\t", p->data); p = p->next; }
		printf("\n");
	}
}
void insertlist(node*l, node*s,int x)
{
	node*p = s;
	node*n = l->next ;
	while (p->next != NULL) { p = p->next; }
	while (n->data != x) { n = n->next; }
	p->next =n->next;
	n->next = s->next;
	free(s);

}
int main()
{
	node*l;
	node*s;
	l = list();
	s = list();
	insert(1, l);
	insert(2, l);
	insert(3, l);
	insert(4, l);
	insert(5, l);
	insert(6, l);
	print(l);
	insert(19, s);
	insert(52, s);
	insert(65, s);
	insert(100, s);
	print(s);
	insertlist(l, s,4);
	print(l);
	system("pause");
	return 0;
}