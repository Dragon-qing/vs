#include"Person.h"
#include<iostream>
using namespace std;
void f(Person* p)
{
	p->display();
}
int main()
{
	teacher t1("������", "��", 1978, 8, 6,"19960053","��ʦ",4000);
	teacher t2("����", "Ů", 1965, 1, 23, "19900025", "����", 5000);
	student s1("Lee", "��", 2002, 5, 3, "20190098", "һ�꼶", "�����", 580);
	SeqList<Person*>l;
	l.InsertRear(&t1);
	l.InsertRear(&t2);
	l.InsertRear(&s1);
	for (int i = 0; i < l.Size(); i++)
	{
		cout << i + 1 << "th" << endl;
		f(l[i]);
	}
	return 0;
}