#include<iostream>
using namespace std;
class Complex
{
private:
	int a;
	int b;
public:
	Complex(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	void printCom()
	{
		cout << a << "+" << b << "i" << endl;
	}
	Complex operator-(Complex& c2)
	{
		Complex tmp;
		tmp.a = this->a - c2.a;
		tmp.b = this->b - c2.b;
		return tmp;
	}
	Complex operator+(Complex& c2)
	{
		Complex tmp;
		tmp.a = a + c2.a;
		tmp.b = b + c2.b;
		return tmp;
	}
	Complex& operator++()
	{
		a++;
		b++;
		return *this;
	}
	Complex& operator++(int)
	{
		Complex tmp(a,b);
		a++;
		b++;
		return tmp;
	}
};
int main()
{
	Complex c1(1, 2), c2;
	c2 = ++c1;
	c2.printCom();//2+3i

	c2 = c1++;
	c2.printCom();//2+3i
	cout << "\n";
	return 0;
}
