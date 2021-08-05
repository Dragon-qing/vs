
#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include <stdlib.h>
#include<iostream>
using namespace std;
template<class T>
class Vector
{
private:
	T* data;						//指向动态数组指针
	int size;						//数组的数据元素个数
	int max;						//数组容量
	void Error(const char* cs)const { cout << cs << endl; exit(1); }//错误信息报告
public:
	enum { SPARE_MAX = 16 };				//枚举常量表示数组最小长度
	explicit Vector(int n = 0) :size(0), max(n + SPARE_MAX)
	{
		if (max > 0) data = new T[max];
	}
	Vector(const Vector& v) :data(NULL), max(0) { operator=(v); }//复制构造函数
	~Vector() { delete[]data; }
	Vector& operator=(const Vector<T>& v);		//复制赋值函数
	T& operator[](int id) { return data[id]; }		//下标运算符函数
	const T& operator[](int id)const { return data[id]; }//常量型下标运算符函数
	bool Empty()const { return size == 0; }			//判空
	bool isFull() const { return size == max; } //判满
	int Size()const { return size; }				//求数据个数
	int Max()const { return max; }					//求数组容量
	void Clear() { size = 0; }						//清空。删除所有数据元素
	//迭代器类型
	typedef T* iterator;						//迭代器
	typedef const T* const_iterator;			//指向const常量的迭代器

	iterator Begin() { return data; }				//使迭代器指向容器起始位置
	const_iterator Begin()const { return data; }
	iterator End() { return data + size; }			//使迭代器指向容器最后一个数据元素的后继
	const_iterator End()const { return data + size; }

	const T& Front()const { return data[0]; }		//返回首元素的引用(可以返回*begin())
	T& Front() { return data[0]; }
	const T& Back()const { return data[size - 1]; }	//返回尾元素的引用(不能返回*--end())
	T& Back() { return data[size - 1]; }
	void Push_back(const T& item);              //尾插
	void Pop_back() { size--; }					//尾删
	void Reserve(int newMax);					//扩大数组容量为newmax，保留原来数据
	void Resize(int newSize, const T& item = T());	//把数据个数增加为newsize，保留原来的数据，其余的值为item
	iterator Insert(iterator itr, const T& item);
	iterator Erase(iterator itr);

	iterator Erase(iterator first, iterator last); //删除[first,last)区间的数据，返回当前数据的位置。
	void Insert(iterator pos, iterator first, iterator last);//在pos处插入另一个Vector容器指定区间[first, last)的数据
	void Swap(Vector<T>& v); //交换两个Vector中的数据。
};

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)//复制赋值函数
{
	if (max != v.Max())
	{
		delete[]data;
		max = v.max;
		data = new T[max];
	}
	size = v.Size();
	for (int i = 0; i < size; i++)
		data[i] = v.data[i];
	return *this;
}

template<class T>				//模板参数表
typename Vector<T>::iterator				//返回值类型
Vector<T>::Erase(iterator itr)	//删除指示器指向的元素
{
	for (iterator p = itr, q = itr + 1; q != data + size; ++p, ++q)
		*p = *q;
	size--;
	return itr;
}

template<class T>	//把元素item插入到迭代器itr的位置
typename Vector<T>::iterator Vector<T>::Insert(iterator itr, const T& item)
{
	/*******************请在此处写出成员函数的定义***********************/
	if (size == max)
	{
		int old = itr - Begin();
		Reserve(max * 2 + 1);
		itr = Begin() + old;
	}
	if (itr<Begin() || itr>End())
	{
		exit(1);
	}
	for (iterator p = End(); p != itr; p--)
	{
		*p = *(p - 1);
	}
	*itr = item;
	size++;
	return itr;
	/***********************************************************************/
}

template<class T>
void Vector<T>::Push_back(const T& item)
{
	if (size < max) {
		data[size] = item;
	}
	else {
		T* old = data;
		int len = 2 * max + 1;
		data = new T[len];
		int i = 0;
		for (; i < size; i++) {
			data[i] = old[i];
		}
		data[i] = item;

		max = len;
		delete[] old;
	}

	size++;						//数据个数增1
}

template<class T>
void Vector<T>::Reserve(int newmax)
{
	if (newmax < max)			//如果数组容量已满，则返回
		return;
	T* old = data;			//保留原数组
	data = new T[newmax];		//重新分配新数组		
	for (int i = 0; i < size; i++)	//把原数组中的数据复制到新数组
		data[i] = old[i];
	max = newmax;				//修改数组容量
	delete[]old;			//释放原数组空间			
}

template<class T>//数据个数增为newsize，原数据保留，增加的数据元素初始化为item
void Vector<T>::Resize(int newsize, const T& item)
{
	if (newsize > max)					//如果数据元素个数大于数组容量
		Reserve(newsize * 2 + 1);		//扩大数组容量
	for (int i = size; i < newsize; i++)	//把增加的数据元素初始化为item
		data[i] = item;
	size = newsize;
}

template<class T>
typename Vector<T>::iterator Vector<T>::Erase(iterator first, iterator last)
{
	/*******************请在此处写出成员函数的定义*********************/
	if (first < Begin() || last >= End())
	{
		exit(1);
	}
	for (iterator p = first; p <= last; p++)
	{
		Erase(first);
	}
	return first;
	/******************************************************************/
}

template<class T>
void Vector<T>::Insert(iterator pos, iterator first, iterator last)
{
	/*******************请在此处写出成员函数的定义*********************/
	iterator a = pos;
	for (iterator p = first; p <= last; ++p, ++a)
	{
		a=Insert(a, *p);
	}

	/******************************************************************/
}

template<class T>
void Vector<T>::Swap(Vector<T>& v)
{
	/*******************请在此处写出成员函数的定义*********************/
	Vector<T> temp = *this;
	*this = v;
	v = temp;
	/******************************************************************/
}
#endif
