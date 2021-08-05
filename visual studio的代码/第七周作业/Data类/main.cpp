#include"date.h"
#include<iostream>
using namespace std;

int main()
{
	Date d;					//Date d=Date();����Ĭ�Ϲ��캯��
	cout << "Default constructor: ";
	cout << d << endl;      //���ò�����������ʾ

	Date d1(2020, 5, 1);		//���ù��캯��
	cout << "Constructor: ";
	cout << d1 << endl;

	long n;
	n = d1;				//����ת������
	cout << "Conversion Function: ";
	cout << n << endl;

	Date d2(d1);			//Date d2=d1;���ø��ƹ��캯��
	cout << "Copy  constructor: ";
	cout << d2 << endl;

	Date d3(n);				//��������ת�����캯��
	cout << "Converting  constructor: ";
	cout << d3 << endl;

	d3 = n - 50;					//����ת����ֵ���������
	cout << "Overload assignment(converting): ";
	cout << d3 << endl;

	d2 = d3;					//���ø��Ƹ�ֵ���������
	cout << "Overload assignment(copy): ";
	cout << d2 << endl;

	d2--;					//���ú�--
	cout << "Overload post-decrement : ";
	cout << d2 << endl;

	--d2;                   //����ǰ--
	cout << "Overload pre-decrement : ";
	cout << d2 << endl;

	d2.Set_day(3);			//�������ݳ�Ա��ֵ����
	cout << "After set day : ";
	cout << d2 << endl;

	cout << "Overload post-increment : ";
	cout << d2++ << endl;     //���ú�++

	cout << "Overload pre-increment : ";
	cout << ++d2 << endl;     //����ǰ++

	d2 += 5;
	cout << "Overload addition assignment : ";
	cout << d2 << endl;

	Date d4;
	cout << "Please input year, month, day: ";
	cin >> d4;
	cout << "Input date is: " << d4;

	return 0;
