#include"Person.h"
#include<iostream>
using namespace std;
void f(Person* p)
{
	p->display();
}
int main()
{
	teacher t1("吴晓刚", "男", 1978, 8, 6,"19960053","教师",4000);
	teacher t2("曾黎", "女", 1965, 1, 23, "19900025", "教授", 5000);
	student s1("Lee", "男", 2002, 5, 3, "20190098", "一年级", "计算机", 580);
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