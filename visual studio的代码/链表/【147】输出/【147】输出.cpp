#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node*next;
	struct node*prev;
};
typedef struct node node;
node*getnode(int item, node*n, node*p) {
	node*l;
	l = (node*)malloc(sizeof(node));
	l->data = item;
	l->next = n;
	l->prev = p;
	return l;
}
int getdata(node*l) { return l->data; }
node*getnext(node*l) { return l->next; }
node*getprev(node*l) { return l->prev; }
typedef struct {
	node*head;
	node*tail;
	int size;
}list;
void initlist(list*l) {
	l->head = NULL;
	l->tail = NULL;
	l->head->next = l->tail;
	l->tail->prev = l->head;
	l->size = 0;
}//���ձ�
node*begin(list*l) { return l->head->next; }
node*end(list*l) { return l->tail; }
node*insert(list*l, node*itr, int item) {
	node*p = itr;
	p->prev->next = getnode(item, itr->prev, itr);
	p->prev = itr->prev->next;
	l->size++;
	return p->prev;
}//����
void pushfront(list*l, int item) { insert(l, begin(l), item); }//ͷ��
void pushback(list*l, int item) { insert(l, end(l), item); }//β��
void outputlist(list*l) {
	node*first = begin(l);
	node*last = end(l);
	for (; first != last; first = getnext(first)) {
		printf("%d\t", getdata(first));
		printf("\n");
	}
}//��ǰ�������

int main()
{

	system("pause");
	return 0;
}