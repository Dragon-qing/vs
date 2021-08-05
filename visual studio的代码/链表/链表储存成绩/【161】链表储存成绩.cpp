#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	char name[10];
	int grade;
	node*next;
}node;
node*getnode(char *a, int b)
{
	node*l = (node*)malloc(sizeof(node));
	strcpy_s(l->name, a);
	l->grade = b;
	l->next = NULL;
	return l;
}
node*list()
{
	char s[10] = { 0 };
	node*head = getnode(s, 0);
	return head;
}
void insert(char n[], int g,node*head)
{
	node*l = getnode(n, g);
	l->next = head->next;
	head->next = l;
}
void print(node*head)
{
	node*p = head->next;
	if (p != NULL)
	{ 
		while (p)
		{
			printf("%s:%d\n", p->name, p->grade);
			p = p->next;
		}
	}
}
int main()
{
	node*l;
	char name[10];
	int g;
	l = list();
	printf("请输入姓名和分数\n");
	scanf_s("%s %d", name,sizeof(name), &g);
	while (g)
	{
		insert(name, g, l);
		scanf_s("%s %d", name, sizeof(name), &g);
	}
	print(l);
	system("pause");
	return 0;
}