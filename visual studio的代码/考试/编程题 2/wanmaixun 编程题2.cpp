#include<iostream>
using namespace std;
class student
{
public:
	virtual void printScore()=0;
};
class senior :public student
{
	double physics, chemistry;
public:
	senior(double p=0,double c=0):physics(p),chemistry(c){}
	void printScore()
	{
		cout << "physics:" << physics << "  " << "chemistry:" << chemistry << "  ";
	}
};
class college :public senior
{
	double OOP;
public:
	college(double p=0, double c=0,double o = 0):senior(p,c),OOP(o){}
	void printScore()
	{
		senior::printScore();
		cout << "OOP:" << OOP;
	}
};
int main()
{
	senior s1(85, 90);
	college s2(85, 90, 95);
	student* p;
	p = &s1;
	p->printScore();
	cout << endl;
	p = &s2;
	p->printScore();
	cout << endl;
	return 0;
}