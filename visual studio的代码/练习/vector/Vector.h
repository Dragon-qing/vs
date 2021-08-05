
#ifndef _VECTOR_H_
#define _VECTOR_H_
#include<iostream>
using namespace std;
template<class T>
class Vector
{
	T* itr;
	int size;
	int max;
public:
	enum { S_Max = 3 };
	Vector(int n=0):size(0),max(size+S_Max)
	{
		itr = new T[max];
	}
	Vector(const Vector& v) :size(0), max(0) { *this = v; }
	~Vector() { delete[] itr; }
	Vector& operator =(const Vector& v);
	T& operator[](int id) { return itr[id]; }
	const T& operator[](int id) const { return itr[id]; }

	bool Empty() const { return size == 0; }
	int Size() const { return size; }
	int Max() const { return max; }
	void Clear() { size = 0; }

	typedef T* iterator;     //迭代器
	typedef const T* const_iterator;    //常量型迭代器
	iterator Begin() { return itr; }
	const_iterator Begin() const { return itr; }
	iterator End() { return itr + size; }
	const_iterator End() const { return itr + size; }

	T& Front() { return itr[0]; }
	const T& Front() const { return itr[0]; }
	T& Back() { return itr[size - 1]; }
	const T& Back() const { return itr[size - 1]; }

	void Push_back(const T& item);
	void Pop_back()
	{
		if (!Empty()) size--;
	}

	void Reserve(int newMax);  //扩大数组容量为newMax，并保留原来的数据
	void Resize(int newSize, const T& item = T());   //把数据个数增加为newSize,保留原来的数据，其余的值为item

	iterator Insert(iterator itr, const T& item = T()); //在itr所指向的位置插入item
	iterator Erase(iterator itr); //删除itr所指向的元素
};
template <class T>
Vector<T>& Vector<T>::operator =(const Vector& v)
{
	if (v.max != max)
	{
		max = v.max;
		delete[] itr;
		itr = new T[v.max];
	}
	size = v.size;
	for (int i = 0; i < size; i++)
		itr[i] = v.itr[i];
	return *this;
}
template <class T>
void Vector<T>::Push_back(const T& item)
{
	if (size == max)
	{
		Reserve(2 * max + 1);
	}
	itr[size] = item;
	size++;
}
template <class T>
void Vector<T>::Reserve(int newMax)
{
	if (newMax <= max)exit(1);
	iterator old = itr;
	itr = new T[newMax];
	for (int i = 0; i < size; i++)
		itr[i] = old[i];
	max = newMax;
	delete[] old;
}
template <class T>
void Vector<T>::Resize(int newSize, const T& item)
{
	if (newSize > max)
	{
		Reserve(2 * newSize + 1);
	}
	for (int i = size; i < newSize; i++)
	{
		itr[i] = item;
	}
	size = newSize;
}
template <class T>
typename Vector<T>:: iterator Vector<T>::Insert(iterator Itr, const T& item )
{
	if (size == max)
	{
		int temp = Itr-Begin();
		Reserve(2 * max + 1);
		Itr = Begin() + temp;
	}
	if (Itr<Begin() || Itr>End())
	{
		exit(1);
	}
	for (iterator p = End(); p != Itr; p--)
		*p = *(p - 1);
	*Itr = item;
	size++;
	return Itr;
}
template <class T>
typename Vector<T>::
iterator Vector<T>::Erase(iterator Itr)
{
	if (Itr<Begin() || Itr>=End())
	{
		exit(1);
	}
	for (iterator p = Itr; p < End(); p++)
	{
		*p = *(p + 1);
	}
	size--;
	return Itr;
}
#endif