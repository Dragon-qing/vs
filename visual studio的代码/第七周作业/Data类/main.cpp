#include"date.h"
#include<iostream>
using namespace std;

int main()
{
	Date d;					//Date d=Date();调用默认构造函数
	cout << "Default constructor: ";
	cout << d << endl;      //调用插入符，完成显示

	Date d1(2020, 5, 1);		//调用构造函数
	cout << "Constructor: ";
	cout << d1 << endl;

	long n;
	n = d1;				//调用转换函数
	cout << "Conversion Function: ";
	cout << n << endl;

	Date d2(d1);			//Date d2=d1;调用复制构造函数
	cout << "Copy  constructor: ";
	cout << d2 << endl;

	Date d3(n);				//调用类型转换构造函数
	cout << "Converting  constructor: ";
	cout << d3 << endl;

	d3 = n - 50;					//调用转换赋值运算符函数
	cout << "Overload assignment(converting): ";
	cout << d3 << endl;

	d2 = d3;					//调用复制赋值运算符函数
	cout << "Overload assignment(copy): ";
	cout << d2 << endl;

	d2--;					//调用后--
	cout << "Overload post-decrement : ";
	cout << d2 << endl;

	--d2;                   //调用前--
	cout << "Overload pre-decrement : ";
	cout << d2 << endl;

	d2.Set_day(3);			//调用数据成员赋值函数
	cout << "After set day : ";
	cout << d2 << endl;

	cout << "Overload post-increment : ";
	cout << d2++ << endl;     //调用后++

	cout << "Overload pre-increment : ";
	cout << ++d2 << endl;     //调用前++

	d2 += 5;
	cout << "Overload addition assignment : ";
	cout << d2 << endl;

	Date d4;
	cout << "Please input year, month, day: ";
	cin >> d4;
	cout << "Input date is: " << d4;

	return 0;
