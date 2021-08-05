#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node*next;
};
typedef struct node node;
node*creatlist()
{
	node*headnode=(node*)malloc(sizeof(node));
	headnode->data = 0;
	headnode->next = NULL;
	return headnode;
}
node*getnode(int item)
{
	node*newnode = (node*)malloc(sizeof(node));
	newnode->data = item;
	newnode->next = NULL;
	return newnode;
}
void printlist(node*l)
{
	node*p = l->next;
	if (p == NULL) { printf("读取错误！"); }
	else {
		while (p) {
			printf("%d\t", p->data);
			p = p->next;
		}
		printf("\n");
	}
}
node*insert(int item, node*l)
{
	node*newnode=getnode(item);
	newnode->next = l->next;
	l->next = newnode;
	return newnode;
}
void delate(int x, node*l)
{
	node*post = l->next;
	node*n = l;
	//printf("%d\t", post->data);
	if (post == NULL) { printf("链表为空无法删除"); }
	//printf("%d\t", post->next->data);
	do
	{
		n = post;
		post = post->next;
		if (post == NULL) { printf("未找到节点"); return; }
		
	} while (post ->data != x);
	n->next = post->next;
	free(post);
	return;
}
int main()
{
	node*l;
	l = creatlist();
	insert(1, l);
	insert(2, l);
	insert(3, l);
	insert(4, l);
	insert(5, l);
	insert(6, l);
	insert(7, l);
	printlist(l);
	/*printf("%d", l->next->data );*/
	delate(5,l);
	printlist(l);
	delate(10, l);
	system("pause");
	return 0;
}