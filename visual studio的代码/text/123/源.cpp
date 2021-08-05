#include<iostream>
#include<string>
using namespace std;

class Complex
{
private:
	double r, i;
public:
	friend ostream& operator<<(ostream& cout, Complex& a);//�������������
	friend Complex operator+(Complex& a, Complex& b);//�Ӻ�����
	friend Complex operator-(Complex& a, Complex& b);//��������
	Complex& operator=( const Complex& a)
	{
		i = a.i;
		r = a.r;
		return *this;
	}
	Complex(double a = 0, double b = 0) :r(a), i(b) {}
};

Complex temp;

Complex operator+(Complex& a, Complex& b)//�Ӻ�����
{
	temp.i = a.i + b.i;
	temp.r = a.r + b.r;
	return temp;
}

Complex operator-(Complex& a, Complex& b)//��������
{
	temp.i = a.i - b.i;
	temp.r = a.r - b.r;
	return temp;
}

ostream& operator<<(ostream& cout, Complex& a)//�������������
{
	cout << a.r << "+" << a.i << "i" << endl;
	return cout;
}

int main()
{
	Complex a(10, 9), b(5, 3), sum, dif;
	sum = a+b ;
	cout << "Sum of a and b is:" << sum << endl;
	dif = a-b ;
	cout << "Difference of a and b is:" << dif << endl;

	return 0;
}
