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
		printf("��˳�������� :");
		scanf("%s", s->data.num);
		printf("��˳���������� :");
		scanf("%s", s->data.name);
		printf("��˳�������Ա�:");
		scanf("%s", s->data.sex);
		printf("��˳������绰 :");
		scanf("%s", s->data.phone);
		printf("��˳�������ַ:");
		scanf("%s", s->data.adder);
		printf("�Ƿ�������루1 �� 0 �񣩣�");
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
	printf("1 ����Ų\n");
	printf("2 �������飺\n");
	printf("=================\n");
	printf("��ѡ�� ��");
	p = head->next;
	scanf("%d", &i);
	if (i == 1)
	{
		printf("������Ҫ�����˵ı�ţ�");
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
			printf("������Ҫ�����˵�������");
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
	printf("�밴��ʾ����Ҫɾ����ͨѶ��\n");
	p = searchnode(head);
	if (p == NULL)
	{
		printf("û�в鵽Ҫɾ���˵�ͨѶ��");
		return;
	}
	while (q&&q->next != p)
	{
		q = q->next;
		q->next = p->next;
	}
	free(p);
	printf("ͨѶ��ɾ���ɹ�\n");
}
void exchange(node*head)
{
	node*p;
	p = searchnode(head);
	if (p != NULL)
	{
		printf("������ͨѶ�˵���ȷ�绰��ͨѶ��ַ���ÿո񽨸�������");
		scanf("%s%s", p->data.phone, p->data.adder);
	}
	else
	{
		printf("û�в鵽���ˣ�");
	}
}
void printlist(node*head)
{
	node*p;
	p = head->next;
	printf("ͨѶ¼�嵥�б�\n");
	printf("=================\n");
	printf("��� ���� �Ա� �绰 ��ַ");
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
		printf("��ѯʧ�ܣ�");
	}
	else
	{
		printf("��ѯ�ɹ�����ѯ�Ľ����:%s,%s\n", p->data.num, p->data.name);
	}
	p = (node*)malloc(sizeof(node));
	printf("�밴˳�������¼����ͨѶ�˵ı��:");
	scanf("%s", p->data.num);
	printf("�밴˳�������¼����ͨѶ�˵�����:");
	scanf("%s", p->data.name);
	printf("�밴˳�������¼����ͨѶ�˵��Ա�:");
	scanf("%s", p->data.sex);
	printf("�밴˳�������¼����ͨѶ�˵ĵ绰:");
	scanf("%s", p->data.phone);
	printf("�밴˳�������¼����ͨѶ�˵ĵ�ַ:");
	scanf("%s", p->data.adder);
	insertnode(head, p);
	deletenode(head);
	exchange(head);
	printlist(head);
	return 0;
}