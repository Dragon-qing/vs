#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node*next;
};
typedef struct node node;
node*creatlist(node*headnode) {
	headnode = (node*)malloc(sizeof(node));
	headnode->data = 0;
	headnode->next = NULL;
	return headnode;
}
node*getnode(int item) {
	node*l = (node*)malloc(sizeof(node));
	l->data = item;
	l->next = NULL;
	return l;
}
node* insert(int item, node*headnode) {
	node*newnode=getnode(item);
	newnode->next = headnode->next;
	headnode->next = newnode;
	return newnode;
}
void printlist(node*headnode)
{
	node*p =headnode->next ;
	if (p == NULL) { printf("¶ÁÈ¡Ê§°Ü£¡"); }
	else {
		while (p) {
			printf("%d\t", p->data);
			p = p->next;
	} 
	}
}
int main()
{
	node*l=NULL;
	int x;
	l=creatlist(l);
	scanf_s("%d", &x);
	while (x != 0)
	{
		insert(x, l);
		scanf_s("%d", &x);
	}
	printlist(l);
	system("pause");
	return 0;
  }