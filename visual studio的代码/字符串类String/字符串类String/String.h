#pragma once
#ifndef _STRING_H_
#define _STRING_H_
#include<iostream>
using namespace std;
class String
{
private:
	char* str;          //String类是对C字符串的封装，底层仍是用字符类型的数组存放字符
	int size;           //字符串中字符的个数，不算'\0'
public:
	explicit String(const char* c = "");      //类型转换构造函数，只允许显式转换
	String(const String& s);                  //复制构造函数

	~String() { delete[] str; size = 0; }                //析构函数

	int Size() const { return size; }         //返回字符串中字符的个数

	String& operator=(const String& s);       //复制赋值运算符重载，String类类型字符串之间赋值
	String& operator=(const char* c);         //转换赋值运算符重载，用C字符串为String类类型字符串赋值

	//比较字符串是否相同，返回值为布尔型
	bool operator==(const String& s) const;    //String类字符串之间的比较，即String类串 == String类串
	bool operator==(const char* c) const;      //String类字符串与C字符串之间的比较，即String类串 == C字符串 
	friend bool operator==(const char* c, const String& s);//C字符串与String类字符串之间的比较，即C字符串 == String类串

	//比较字符串的大小，返回值为布尔型
	bool operator<(const String& s) const;    //String类字符串之间的比较，即String类串 <= String类串
	bool operator<(const char* c) const;      //String类字符串与C字符串之间的比较，即String类串 <= C字符串 
	friend bool operator<(const char* c, const String& s);//C字符串与String类字符串之间的比较，即C字符串 <= String类串

	//字符串的连接
	String operator+(const String& s);    //String类串 + String类串
	String operator+(const char* c);      //String类串 + C字符串
	friend String operator+(const char* c, const String& s);    //C字符串+String类串

	String& operator+=(const String& s);    //String类串 += String类串
	String& operator+=(const char* c);      //String类串 += C字符串

	//从id开始查找字符首次出现的位置，如果找到返回其下标，否在返回-1
	int Find_First_Of(const char c, int id) const;

	//在字符串下标为id处插入String类型的字符串s
	String& Insert(int id, const String& s);
	//在字符串下标为id处插入C字符串c
	String& Insert(int id, const char* c);

	//从下标id开始连续删除num个字符。
	String& Erase(int id, int num);

	//从字符串下标为id处开始连续取num各字符，组成新字符串返回
	String SubStr(int id, int num) const;

	//Type-cast operator, 将String类型转换为char*类型。
	explicit operator char* ();
	//Type-cast operator, 将String类型转换为const char*类型。
	explicit operator const char* () const;

	//下标运算符[]的重载
	char& operator[](int id) { return str[id]; }
	const char& operator[](int id)const { return str[id]; }

	//输入输出
	friend ostream& operator<<(ostream& ostr, const String& s);
	friend istream& operator>>(istream& istr, String& s);
};
#endif
