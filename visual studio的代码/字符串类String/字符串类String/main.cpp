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
	//测试构造函数和赋值运算符
	String s1 = (String)"Hello guys!";      //右侧字符串前面为什么加(String)?
	String s2 = s1;

	//测试<<运算符
	cout << s1 << endl;
	cout << s2 << endl;
	printStar();

	//测试赋值运算符
	char a[] = "Are you ready?";
	s2 = a;                  //转换赋值运算符，s2为"Are you ready?"
	String s3;

	cout << "Please input YES/NO: ";
	cin >> s3;                      //测试 >> 运算符
	if (s3 == "YES")                 //测试比较运算符==
		cout << "OK!Let's go!" << endl;
	else if (s3 == "NO")
		cout << "em......" << endl;
	printStar();

	cout << s1 << endl;
	cout << s2 << endl;
	if (s1 < s2)                       //测试比较运算符<
		cout << "s1 is less than s2!" << endl;
	else
		cout << "s1 isn't less than s2" << endl;
	printStar();

	//测试字符串的连接
	String s4;
	s4 = s1 + s2;        //String类串 + String类串,s4为"Hello guys!Are you ready? "
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "After s1+s2: " << s4 << endl;
	s4 += a;             //String类串 += C串，s4为"Hello guys!Are you ready? Are you ready? "
	cout << "After s4+=a: " << s4 << endl;

	String s5(" I am thinking......");
	s5 = a + s1;          //C串+String类串，s5重新赋值为"Are you ready?Hello guys! "
	cout << "a is: " << a << endl;
	cout << "s1 is: " << s1 << endl;
	cout << "After a + s1: " << s5 << endl;

	printStar();
	//测试单个字符查找
	char ch = 'Y';
	cout << s1.Find_First_Of(ch, 0) << endl; //s1字符串中不含’Y’,输出-1

	printStar();
	//测试子串插入Insert，子串删除Erase,取子串SubStr
	cout << "s1: " << s1 << endl;
	s1.Insert(5, " Welcome to program with C++!");
	cout << "After Insert, s1: " << s1 << endl;
	cout << endl;

	cout << "s2: " << s2 << endl;
	s2.Erase(3, 4);
	cout << "After Erase(3,4), s2: " << s2 << endl;

	cout << "SubStr(6,7) of s1 is： " << s1.SubStr(6, 7) << endl;

	printStar();
	//测试类型转换符
	char b[100] = "Go to film!";
	String s6("I want to see \"Little Women\"");
	cout << "s6 is：";
	for (int i = 0; i < s6.Size(); i++)
	{
		cout << s6[i];
	}
	strcat_s(b, strlen(b) + s1.Size() + 1, (const char*)s6);    //将String类型转换为C字符串
	cout << "\n After b+s6,b is ; " << b;

	return 0;
}
