#include<iostream>
const int Max = 100;
using namespace std;
struct Linked {
	int sid;
	float scores;
	int size;
	Linked* next;
};
Linked* Create()
{
	Linked* p;
	p = new Linked;
	p->next = NULL;
	return p;
}
void InsertAfter(Linked* node, int num, float sc)
{
	Linked* p;
	p = new Linked;
	p->sid = num;
	p->scores = sc;
	node->next = p;
	p->next = NULL;
	size++;
}

void DeleteAfter(Linked* node)
{
	Linked* p = node;
	p = p->next->next;
	size--;
}
Linked* GetByIndex(Linked* head, int index)
{
	Linked* p;
	p = head->next;
	int flag = 0;
	while (flag!=index)
	{
		p = p->next;
		flag++;
	}
	return p;
}
void PrintAll(Linked* head)
{
	Linked* p = head->next;
	while (p->next != NULL)
	{
		cout << p->sid << " " << p->scores;
		size++;
		p = p->next;
	}
}
int main()
{
	int num;
	float score;
	cin >> num >> score;
	Linked* lk = Create();
	InsertAfter(lk, num, score);
	cin >> num >> score;
	InsertAfter(GetByIndex(lk, 0), num, score);
	cin >> num >> score;
	InsertAfter(GetByIndex(lk, 1), num, score);
	DeleteAfter(GetByIndex(lk, 0));
	PrintAll(lk);
	return 0;
}
//1 59.5
//2 99.5
//3 60.5