#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include<iostream>
#include<stdlib.h>
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
	~Vector(void) { delete[]data; }
	Vector& operator=(const Vector<T>& v);		//复制赋值函数
	T& operator[](int id) { return(data[id]); }	//下标运算符函数
	const T& operator[](int id)const { return(data[id]); }//常量型下标运算符函数
	bool Empty(void)const { return(size == 0); }		//判空
	int Size(void)const { return(size); }			//求数据个数
	int Max(void)const { return(max); }			//求数组容量
	void Push_back(const T& item);				//尾插
	void Pop_back(void);						//尾删
	const T& Back(void)const;					//返回尾元素的引用
	const T& Front(void)const;					//返回首元素的引用
	void Clear(void) { size = 0; }					//清空。删除所有数据元素
	void Reserve(int newMax);					//扩大数组容量为newmax，保留原来数据
	void Resize(int newSize, const T& item = T());	//把数据个数增加为newsize，原来的数据保留，其余的值为item

//迭代器类型
	typedef T* iterator;						//迭代器
	typedef const T* const_iterator;			//指向const常量的迭代器
	iterator begin() { return &data[0]; }			//使迭代器指向容器起始位置
	const_iterator begin()const { return &data[0]; }
	iterator end() { return(&data[size]); }	//使迭代器指向容器结束位置
	const_iterator end()const { return(&data[size]); }
	iterator Insert(iterator itr, const T& item);
	iterator Erase(iterator itr);
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
	return(*this);
}
template<class T>
void Vector<T>::Push_back(const T& item)//尾插
{
	if (size == max)			//如果空间数据已满，就要先扩大容量
		Reserve(2 * max + 1);
	data[size++] = item;		//插入元素到尾部，数据个数增1
}

template<class T>				//模板参数表
typename Vector<T>::iterator				//返回值类型
Vector<T>::Erase(iterator itr)	//删除指示器指向的元素
{
	if (size == 0)				//检查是否是空表			
		Error("Erase:an empty Vector!");
	if (itr<begin() || itr>end() - 1)//检查删除位置是否合法					
		Error("Erase: out of illegal!");
	for (iterator p = itr; p != end(); ++p)
		*p = *(p + 1);
	size--;
	return(itr);
}
template<class T>				//模板参数表
typename Vector<T>::iterator				//返回值类型
Vector<T>::Insert(iterator itr, const T& item)//把元素item插入到指示器指向的位置
{
	if (size == max)
		Reserve(2 * max + 1);		//如果空间数据已满，就要先扩大容量
	if (itr<begin() || itr>end())	//检查插入位置是否合法
		Error("Insert:out of range");
	for (iterator p = end(); p != itr; --p)//从尾元素到插入位置上元素往后移动一个位置
		*p = *(p - 1);
	*itr = item;					//插入元素到指定位置
	size++;						//数据个数增1
	return(itr);
}
template<class T>
void Vector<T>::Pop_back(void)	//尾删
{
	if (size == 0)
		Error("Empty Vector!");
	size--;
}

template<class T>
const T& Vector<T>::Back(void)const//返回尾元素的引用
{
	if (size == 0)
		Error("Empty Vector!");
	return(data[size - 1]);
}
template<class T>
const T& Vector<T>::Front(void)const//返回起始元素的引用
{
	if (size == 0)
		Error("Empty Vector!");
	return(data[0]);
}

template<class T>
void Vector<T>::Reserve(int newmax)
{
	if (newmax < max)			//如果数组容量以满足，则返回
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


#endif