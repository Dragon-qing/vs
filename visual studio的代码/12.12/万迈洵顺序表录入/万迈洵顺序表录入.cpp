#include<stdio.h>
#include<stdlib.h>
typedef struct ifn
{
	int id;
	char name[8];
	int c;
}ifn;
struct student
{
	int max;
	int size;
	ifn *data;
};
typedef struct student student;
student*initlist(int max)
{
	student*l = (student*)malloc(sizeof(student));
	ifn*i = (ifn*)malloc(sizeof(ifn)*max);
	l->data = i;
	l->max = max;
	l->size = 0;
	return l;
}
void insert(student *l,int number,ifn v)
{
	l->data[number] = v;
	l->size++;
}
void swap(ifn*a, ifn *b)
{
	ifn x;
	x = *a;
	*a = *b;
	*b = x;
}
void sort(student*l)
{
	int i,cnt=0;
	while (cnt <l->size -1)
	{
		for (i = 2; i <= l->size  - cnt;i++)
		{
			if (l->data[i].id < l->data[i - 1].id)
				swap(&l->data[i], &l->data[i - 1]);
		}
		cnt++;
	}
}
void prt(student*l)
{
	int i;
	for (i = 1; i <= l->size; i++)
	{
		printf("************\n");
		printf("ѧ�ţ�%d\n", l->data[i].id);
		printf("������%s\n", l->data[i].name);
		printf("�������%d\n", l->data[i].c);
		printf("************\n");
	}
}
int main()
{
	ifn v;
	int d=1;
	int number = 1;
	student*l;
	l=initlist(50);
	while (d != 0)
	{
		printf("�������%d��ѧ����ѧ�ţ�", number);
		scanf("%d",&v.id);
		printf("�������%d��ѧ����������", number);
		scanf("%s", v.name);
		printf("�������%d��ѧ���ļ�����ɼ���", number);
		scanf("%d", &v.c);
		insert(l, number, v);
		printf("�Ƿ������0�˳���");
		scanf("%d", &d);
		number++;
	}
	sort(l);
	prt(l);
	system("pause");
	return 0;
}