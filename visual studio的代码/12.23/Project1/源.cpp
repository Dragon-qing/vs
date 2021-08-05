#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
struct person {
	char num[5];
	char name[50];
	char sex[13];
	char phone[15];
	char adder[30];
};
typedef struct person person;
struct node {
	struct person data;
	struct node*next;
};
typedef struct node node;
node*createnode()
{
	node*head;
	node*s, *r;
	head = (node*)malloc(sizeof(node));
	s = (node*)malloc(sizeof(node));
	int dream = 1;
	int i = 0;
	r = head;
	while (i<50)
	{
		printf("请顺序输入编号 :");
		scanf("%s", s->data.num);
		printf("请顺序输入姓名 :");
		scanf("%s", s->data.name);
		printf("请顺序输入性别:");
		scanf("%s", s->data.sex);
		printf("请顺序输入电话 :");
		scanf("%s", s->data.phone);
		printf("请顺序输入地址:");
		scanf("%s", s->data.adder);
		printf("是否继续输入（1 是 0 否）：");
		scanf("%d", &dream);
		if (dream == 0)
		{
			break;
		}
		r->next = s;
		i++;
		r = s;
	}
	r->next = NULL;
	return head;
}
node*searchnode(node*head)
{
	node*p;
	char num[5];
	char name[20];
	int i;
	printf("=================\n");
	printf("1 按编号差：\n");
	printf("2 按姓名查：\n");
	printf("=================\n");
	printf("请选择 ：");
	p = head->next;
	scanf("%d", &i);
	if (i == 1)
	{
		printf("请输入要查找人的编号：");
		scanf("%s", num);
		while (p&&strcmp(p->data.num, num)<0)
		{
			p = p->next;
		}
		if (p == NULL || strcmp(p->data.num, num)>0)
			p = NULL;
	}
	else
		if (i == 2) {
			printf("请输入要查找人的姓名：");
			scanf("%s", name);
			while (p&&strcmp(p->data.name, name) != 0)
			{
				p = p->next;
			}
		}
	return p;
}
void insertnode(node*head, node*p)
{
	node*p1, *p2;
	p1 = head;
	p2 = p1->next;
	while (p2&&strcmp(p2->data.num, p->data.num)<0)
	{
		p1 = p2;
		p2 = p2->next;
	}
	p1->next = p;
	p->next = p2;
}
void deletenode(node*head)
{
	node*p, *q;
	q = head;
	printf("请按提示查找要删除的通讯人\n");
	p = searchnode(head);
	if (p == NULL)
	{
		printf("没有查到要删除人的通讯人");
		return;
	}
	while (q&&q->next != p)
	{
		q = q->next;
		q->next = p->next;
	}
	free(p);
	printf("通讯人删除成功\n");
}
void exchange(node*head)
{
	node*p;
	p = searchnode(head);
	if (p != NULL)
	{
		printf("请输入通讯人的正确电话，通讯地址（用空格建隔开）：");
		scanf("%s%s", p->data.phone, p->data.adder);
	}
	else
	{
		printf("没有查到此人！");
	}
}
void printlist(node*head)
{
	node*p;
	p = head->next;
	printf("通讯录清单列表：\n");
	printf("=================\n");
	printf("编号 姓名 性别 电话 地址");
	printf("=================\n");
	while (p)
	{
		printf("%s", p->data.num);
		printf("%s", p->data.name);
		printf("%s", p->data.sex);
		printf("%s", p->data.phone);
		printf("%s", p->data.adder);
		p = p->next;
	}
	printf("=================\n");
}
int main()
{
	node*head = createnode();
	node*p;
	p = searchnode(head);
	if (p == NULL)
	{
		printf("查询失败：");
	}
	else
	{
		printf("查询成功！查询的结果是:%s,%s\n", p->data.num, p->data.name);
	}
	p = (node*)malloc(sizeof(node));
	printf("请按顺序输入新加入的通讯人的编号:");
	scanf("%s", p->data.num);
	printf("请按顺序输入新加入的通讯人的姓名:");
	scanf("%s", p->data.name);
	printf("请按顺序输入新加入的通讯人的性别:");
	scanf("%s", p->data.sex);
	printf("请按顺序输入新加入的通讯人的电话:");
	scanf("%s", p->data.phone);
	printf("请按顺序输入新加入的通讯人的地址:");
	scanf("%s", p->data.adder);
	insertnode(head, p);
	deletenode(head);
	exchange(head);
	printlist(head);
	return 0;
}