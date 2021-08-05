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
	char x;
	node*p = l->next;
	if (p != NULL)
	{
		while (p) { printf("%d\t", p->data); p = p->next;
		if (p == l) { printf("已经循环一轮,继续循环则输入Y退出输入N\n");
		x=getchar();
		if (x == 'N') { break; }
		else if (x == 'Y') {
			x = getchar(); continue;
		}
		}
		}
		printf("\n");
	}
}
void cycliclist(node*l)
{
	node*p = l;
	while (p->next != NULL) { p = p->next; }
	p->next = l;
}
int main()
{
	node*l;
	node*s;
	l = list();
	insert(1, l);
	insert(2, l);
	insert(3, l);
	insert(4, l);
	insert(5, l);
	insert(6, l);
	//print(l);
	cycliclist(l);
	print(l);
	system("pause");
	return 0;
}