#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int c, n;
char s1[101];
char s2[101];
char s12[201];
char s13[201];
int x;
int flag = 0;
typedef struct stack
{
	char data[201];
	struct stack* next;
}stack;
stack head;
stack* copy(stack*head,char*s12)
{
	int i;
	stack* p = (stack*)malloc(sizeof(stack));
	if (p == NULL)exit(1);
	else 
	{
		head->next = p;
		p->next = NULL;
		for (i = 0; i < 2 * x + 1; i++)
		{
			p->data[i] = s12[i];
		}
	}
	/*printf("p->data=%s\n", p->data);*/
	return p;
}
void make()
{
	scanf_s("%s", s1,sizeof(s1));
	scanf_s("%s", s2,sizeof(s2));
	scanf_s("%s", s13,sizeof(s13));
}
void pop(stack *head)
{
	stack* p = head->next;
	stack* n = p->next;
	while (n != NULL)
	{
		free(p);
		p = n;
		n = n->next;
	}
}
int dfs(int deep)
{
	int i, j;
	stack* p=&head;
	if (!strcmp(s12, s13))
	{
		return deep;
	}
	if (flag == 1)
	{
		return -1;
	}
	for (i = 0,j=0; i < x; i++)
	{
		s12[j++] = s2[i];
		s12[j++] = s1[i];
	}
	s12[j] = '\0';
	copy(&head, s12);
	p = p->next;
	while (p != NULL)
	{
		printf("p=%s\n", p->data);
		p = p->next;
	}
	while (p != NULL)
	{
		p = p->next;
		if (p != NULL)
		{
			if (!strcmp(p->data, s12))
			{
				flag = 1;
				pop(&head);
			}
		}
	}
	for (i = 0; i < x; i++)
	{
		s1[i] = s12[i];
	}
	s1[i] = '\0';
	for (i = x,j=0; i < 2 * x + 1; i++,j++)
	{
		s2[j] = s12[i];
	}
	/*printf("deep=%d\n", deep);*/
	dfs(deep + 1);

}
int main()
{
	int n,number=1;
	int times;
	scanf("%d", &n);
	while (n > 0)
	{
		scanf("%d", &x);
		make();
		times=dfs(0);
		printf("%d %d\n", number, times);
		number++;
		n--;
	}
	return 0;
}