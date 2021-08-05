#include<stdio.h>
#include<stdlib.h>
struct seqlink {
	int id;
	double scores;
	char name[20];
};
typedef struct seqlink seqlink;
struct seqstack {
	struct seqstack*next;
	struct seqstack*prev;
	struct seqlink pointer/*[100]*/;
};
typedef struct seqstack seqstack;
struct link {
	int size;
	seqstack*head;
	seqstack*tail;
};

typedef struct link link;
//void setlink (link*l)
//{
//	l->size=0;
//	l->head=NULL;
//	l->tail=NULL;
//}
seqstack *createseqstack(struct seqlink item, seqstack*itr, seqstack*p)
{
	seqstack*re;
	re = (seqstack*)malloc(sizeof(seqstack));
	re->pointer = item;
	re->next = itr;
	re->prev = p;
	return re;
}
void setseqstack(link*s)
{
	struct seqlink a = { 0,0,{0} };
	s->head = createseqstack(a, NULL, NULL);
	s->tail = createseqstack(a, NULL, NULL);
	s->head->next = s->tail;
	s->tail->prev = s->head;
	s->size = 0;
}
seqstack*insertseqstack(seqstack*s, link*l, struct seqlink item)
{
	seqstack*p = s;
	p->prev->next = createseqstack(item, p, p->prev);
	p->prev = p->prev->next;
	l->size++;
	return p->prev;
}
void selecttionstudent(seqlink*a, seqlink*b)
{
	seqlink temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void findselectstudent(seqstack*p, int number)
{
	int j,i;
	for (i = 0; i < number - 1; i++)
	{
		for (j = 1; j < number - i; p=p->next,j++ )
		{
			if (p->next->pointer.id < p->pointer.id)
			{
				selecttionstudent(&p->next->pointer, &p->pointer);
			}
		}
	}
}
int main()
{
	int item;
	link l;
	seqlink s;
	setseqstack(&l);
	int number = 0;
	int dream = 1;
	int i = 0;
	while (i < 50)
	{
		
		printf("请输入学生%d得学号",number+1);
		scanf("%d", &s.id);
		printf("请输入学生%d名字",number+1);
		scanf("%s", s.name);
		printf("请输入学生%d得成绩",number+1);
		scanf("%lf", &s.scores);
		insertseqstack(l.head->next, &l, s);
		/*insertseqstack(s, &l, s->pointer[i].id);
		insertseqstack(s, &l, s->pointer[i].name);
		insertseqstack(s, &l, s->pointer[i].scores);*/
		number++;
		i++;
		printf("是否继续输入（1 是 0 否）");
		scanf("%d", &dream);
		if (dream == 0)
		{
			break;
		}
	}
	findselectstudent(l.head  , number);
	//输出学生的基本信息 
	{
		struct seqstack *p=l.head->next ;
		while (p != l.tail)
		{
			printf("%d\t", p->pointer.id);
			printf("%s\t", p->pointer.name);
			printf("%f\t", p->pointer.scores);
			printf("\n");
			p = p->next;
		}
	}
	/*for (i = 0; i < 1; i++)
	{
		printf("%d\n", s->pointer[i].id);
		printf("%s\n", s->pointer[i].name);
		printf("%f\n", s->pointer[i].scores);
	}*/
	system("pause");
	return 0;
}
