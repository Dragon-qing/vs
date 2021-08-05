#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node*next;
};
typedef struct node node;
node*creatlist()
{
	node*headnode = (node*)malloc(sizeof(node));
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
	if (p == NULL) { printf("¶ÁÈ¡´íÎó£¡"); }
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
	node*newnode = getnode(item);
	newnode->next = l->next;
	l->next = newnode;
	return newnode;
}
void delate(int x, node*l)
{
	node*post = l->next;
	node*n = l;
	//printf("%d\t", post->data);
	if (post == NULL) { printf("Á´±íÎª¿ÕÎŞ·¨É¾³ı"); }
	//printf("%d\t", post->next->data);
	do
	{
		n = post;
		post = post->next;
		if (post == NULL) { printf("Î´ÕÒµ½½Úµã"); return; }

	} while (post->data != x);
	n->next = post->next;
	free(post);
	return;
}
void printnxlist(node*l)
{
	if (l->next != NULL) { printnxlist(l->next); }
	printf("%d\t", l->data);
}//µİ¹é
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
	printf("Ë³ĞòÊä³ö£º");
	printlist(l);
	printf("ÄæĞòÊä³ö£º");
	printnxlist(l);
	system("pause");
	return 0;
}