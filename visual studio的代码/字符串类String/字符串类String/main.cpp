#include <iostream>
#include "String.h"
using namespace std;

void printStar()
{
	for (int i = 0; i < 15; i++)
		cout << "*";
	cout << endl;
}

int main()
{
	//���Թ��캯���͸�ֵ�����
	String s1 = (String)"Hello guys!";      //�Ҳ��ַ���ǰ��Ϊʲô��(String)?
	String s2 = s1;

	//����<<�����
	cout << s1 << endl;
	cout << s2 << endl;
	printStar();

	//���Ը�ֵ�����
	char a[] = "Are you ready?";
	s2 = a;                  //ת����ֵ�������s2Ϊ"Are you ready?"
	String s3;

	cout << "Please input YES/NO: ";
	cin >> s3;                      //���� >> �����
	if (s3 == "YES")                 //���ԱȽ������==
		cout << "OK!Let's go!" << endl;
	else if (s3 == "NO")
		cout << "em......" << endl;
	printStar();

	cout << s1 << endl;
	cout << s2 << endl;
	if (s1 < s2)                       //���ԱȽ������<
		cout << "s1 is less than s2!" << endl;
	else
		cout << "s1 isn't less than s2" << endl;
	printStar();

	//�����ַ���������
	String s4;
	s4 = s1 + s2;        //String�മ + String�മ,s4Ϊ"Hello guys!Are you ready? "
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "After s1+s2: " << s4 << endl;
	s4 += a;             //String�മ += C����s4Ϊ"Hello guys!Are you ready? Are you ready? "
	cout << "After s4+=a: " << s4 << endl;

	String s5(" I am thinking......");
	s5 = a + s1;          //C��+String�മ��s5���¸�ֵΪ"Are you ready?Hello guys! "
	cout << "a is: " << a << endl;
	cout << "s1 is: " << s1 << endl;
	cout << "After a + s1: " << s5 << endl;

	printStar();
	//���Ե����ַ�����
	char ch = 'Y';
	cout << s1.Find_First_Of(ch, 0) << endl; //s1�ַ����в�����Y��,���-1

	printStar();
	//�����Ӵ�����Insert���Ӵ�ɾ��Erase,ȡ�Ӵ�SubStr
	cout << "s1: " << s1 << endl;
	s1.Insert(5, " Welcome to program with C++!");
	cout << "After Insert, s1: " << s1 << endl;
	cout << endl;

	cout << "s2: " << s2 << endl;
	s2.Erase(3, 4);
	cout << "After Erase(3,4), s2: " << s2 << endl;

	cout << "SubStr(6,7) of s1 is�� " << s1.SubStr(6, 7) << endl;

	printStar();
	//��������ת����
	char b[100] = "Go to film!";
	String s6("I want to see \"Little Women\"");
	cout << "s6 is��";
	for (int i = 0; i < s6.Size(); i++)
	{
		cout << s6[i];
	}
	strcat_s(b, strlen(b) + s1.Size() + 1, (const char*)s6);    //��String����ת��ΪC�ַ���
	cout << "\n After b+s6,b is ; " << b;

	return 0;
}
