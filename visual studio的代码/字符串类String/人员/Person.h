#pragma once
#ifndef _PERSON_H_
#define _PERSON_H_
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
	String& operator=(const char* c);
	String& operator=(const String& s);
	friend ostream& operator<<(ostream& ostr, const String& s);
	friend istream& operator>>(istream& istr, String& s);
};

class Date
{
private:
	int yr, mo, day;								//数据成员：年，月，日
	static const int dys[];				//静态成员数据，对应平常年每月的天数
	bool Leapyear(int y) const;					//闰年判定函数，辅助函数

public:
	//构造函数和析构函数
	Date();           		    //默认构造函数 
	Date(int y, int m, int d);          //构造函数 
	Date(const Date& dt);			//复制构造函数
	Date(long ndays);				//类型转换构造函数，实现long类型到Date类型的转换
	~Date() {}					//析构函数
//重载赋值运算符
	Date& operator=(const Date& dt);			//复制赋值，完成Date类对象之间的赋值
	Date& operator=(long ndays);			//转换赋值，完成long类型的数据给类对象赋值
//闰年判断	
	bool Leapyear() const;
	//转换函数
	operator long() const; 					//实现Date类型到long类型的转换
//自增自减运算符
	Date& operator++();                   //Date d; ++d;
	Date operator++(int);                  //Date d; d++;
	Date& operator--();                    //Date d; --d;
	Date operator--(int);				    //Date d; d--;
	Date& operator+=(int n);               //Date d; d+=n;
	Date& operator-=(int n);               //Date d; d-=n;
//数据成员取值和赋值	
	int Get_year() const;               //获取年份
	int Get_month() const;             //获取月份
	int Get_day() const;               //获取日期
	void Set_year(int y);               //设置年份
	void Set_month(int m);            //设置月份
	void Set_day(int d);					//设置日期

//输入输出
	friend istream& operator >> (istream& istr, Date& dt);	//重载插入符，完成输出
	friend ostream& operator<<(ostream& ostr, const Date& dt);        //重载提取符，完成输入
};
class Person
{
	String name; String sex; Date birth;
public:
	Person(const char* n , const char* s, int y, int m, int d):name(n),sex(s),birth(y,m,d){}
	Person(const Person& p);
	~Person() {}
	virtual void display();
};
class teacher :public Person
{
	String job_number; String rank; double salary;
public:
	teacher(const char* n="", const char* s="", int y=0, int m=0, int d=0, const char* j="", const char* r="", double sal=0) :Person(n, s, y, m, d)
	{
		job_number = j; rank = r;  salary = sal;
	}
	teacher(const teacher& t);
	~teacher(){}
	void display();
};
class student :public Person
{
	String id; String grade; String major; int score;
public:
	student(const char* n="", const char* s="", int y=0, int m=0, int d=0, const char* i = "", const char* g = "", const char* ma = "", int scor=0);
	student(const student& s);
	~student(){}
	void display();
};
//SeqListT.h
template <typename T>
class SeqList
{
private:   //私有
	T* data;
	int size;
	int max;
public:	//公有
//构造函数和析构函数
	explicit SeqList(int n = 100);     	//缺省构造，类型转换构造函数
	SeqList(const SeqList& l);	       //复制构造函数
	~SeqList() { delete[] data; } 	   //析构

//用于修改的的成员函数
	SeqList& operator=(const SeqList& l);
	void InsertRear(const T& item);
	void Insert(int id, const T& item);
	void Erase(int id);
	void Clear() { size = 0; }
	T& operator[](int id);
	const T& operator[](int id)const;

	int Size()const { return size; }
	bool Empty()const { return size == 0; }
	bool Full()const { return size == max; }

	//Operation based on pointer
	T* Begin() { return data; }
	const T* Begin() const { return data; }
	T* End() { return data + size; }
	const T* End() const { return data + size; }

	void Insert(T* itr, const T& item);
	void Erase(T* itr);

	//Swap two item according to the id
	void Swap(int id1, int id2);
	void Replace(int id, const T& item);
};

template <typename T>
SeqList<T>::SeqList(int n)
{
	data = new T[n];
	size = 0;
	max = n;
}

template <typename T>
SeqList<T>::SeqList(const SeqList& l)
{
	data = new T[l.max];

	//深复制
	for (int i = 0; i < l.size; i++)
	{
		data[i] = l.data[i];
	}
	size = l.size;
	max = l.max;
}

//赋值运算符重载，实现顺序表之间的拷贝
template <typename T>
SeqList<T>& SeqList<T>::operator=(const SeqList<T>& l)
{
	if (this == &l) return *this;              //检查是否自我赋值

	if (max != l.max)							//如果数组容量不同
	{
		delete[] data;                          //注意释放原来的空间
		data = new T[l.max];
	}

	for (int i = 0; i < l.size; i++)
		data[i] = l.data[i];
	size = l.size;
	max = l.max;

	return *this;               //返回值的类型是引用，因此返回对当前对象的引用
}

template <typename T>
T& SeqList<T>::operator[](int id)	           //下标操作符重载
{
	if (id<0 || id>size - 1)
	{
		cout << "id illegal!";
		exit(1);
	}
	return data[id];
}

template <typename T>
const T& SeqList<T>::operator[](int id)const//常量型下标操作符重载
{
	if (id<0 || id>size - 1)
	{
		cout << "id illegal!";
		exit(1);
	}
	return data[id];
}

template <typename T>
void SeqList<T>::InsertRear(const T& item)
{
	if (size == max)
	{
		cout << "InsertRear: list is full！\n";//错误类型提示
		exit(1);        				//停止程序运行
	}
	data[size] = item;
	size++;
}

template <typename T>
void SeqList<T>::Insert(int id, const T& item)
{
	if (id<0 || id>size || size == max)
	{
		cout << "Insert: id is illegal or list is full！\n";//错误类型提示
		exit(1);        				//停止程序运行
	}
	for (int i = size - 1; i >= id; i--)
		data[i + 1] = data[i];

	data[id] = item;
	size++;
}

template <typename T>
void SeqList<T>::Erase(int id)
{
	if (id<0 || id>size - 1)
	{
		cout << "Erase: id is illegal or list is empty！\n"; //错误类型提示
		exit(1);        						//停止程序运行
	}

	for (int i = id + 1; i < size; i++)
		data[i - 1] = data[i];
	size--;
}

//基于指针的Insert，Erase
template <typename T>
void SeqList<T>::Insert(T* itr, const T& item) {
	if (itr < Begin() || itr > End()) {
		cout << "The pointer is out of range!" << endl;
		system("pause");
		exit(1);
	}

	for (T* ptr = this->End(); ptr != itr; ptr--)
		*ptr = *(ptr - 1);
	*itr = item;

	size++;
}

template <typename T>
void SeqList<T>::Erase(T* itr) {
	if (itr < Begin() || itr >= End()) {
		cout << "The pointer is out of range!" << endl;
		system("pause");
		exit(1);
	}
	for (T* ptr = itr + 1; ptr != this->End(); ptr++)
		*(ptr - 1) = *ptr;

	size--;
}

//交换索引分别为id1和id2的两个元素
template <typename T>
void SeqList<T>::Swap(int id1, int id2) {
	T temp = data[id1];
	data[id1] = data[id2];
	data[id2] = temp;
}

//用元素item替换索引为id的元素
template <typename T>
void SeqList<T>::Replace(int id, const T& item) {
	data[id] = item;
}

#endif