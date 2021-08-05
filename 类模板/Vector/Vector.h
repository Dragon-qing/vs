
#ifndef _VECTOR_H_
#define _VECTOR_H_
#include<iostream>
#include<stdlib.h>
using namespace std;
template <typename T>
class Vector
{
private:
	T* data;
	int size;
	int max;
	void Error(const char* cs)const { cout << cs << endl; exit(1); }
public:
	enum{SPARE_MAX=3};
	explicit Vector(int n=0):size(0),max(n+SPARE_MAX){
		if (max > 0)data = new T[max];
	}
	Vector(const Vector& v) :data(NULL), max(0) { operator=(v); }
	~Vector(void) { delete[]data; }
	Vector& operator =(const Vector<T>& v);
	T& operator[](int id) { return data[id]; }
	const T& operator[](int id)const { return(data[id]); }
	bool Empty(void)const { return (size == 0); }
	int Size(void)const { return(size); }
	int Max(void)const { return (max); }
	void Push_back(const T& item);
	void Pop_back(void);
	const T& Back(void)const;
	const T& Front(void)const;
	void Clear(void) { size = 0; }
	void Reserve(int newmax);
	void Resize(int newSize, const T& item = T());
	typedef T* iterator;						
	typedef const T* const_iterator;
	iterator begin() { return data; }
	const_iterator begin()const { return data; }
	iterator end() { return &data[size]; }
	const_iterator end()const{ return &data[size]; }
	iterator Insert(iterator itr, const T& item);
	iterator Erase(iterator itr);
};
template<typename T>
Vector<T>& Vector<T>::operator =(const Vector<T>& v)
{
	if (max != v.Max())
	{
		max = v.max;
		delete[]data;
		data = new T[max];
	}
	size = v.size;
	for (int i = 0; i < v.size; i++)
	{
		data[i] = v.data[i];
	}
	return *this;
}
template<typename T>
void Vector<T>::Push_back(const T& item)
{
	if (size == max)
	{
		Reserve(2 * max + 1);
	}
	data[size++] = item;
}
template<typename T>
void Vector<T>::Pop_back(void)
{
	if (size == 0)Error("empty Vector!");
	size--;
}
template<typename T>
const T&Vector<T>:: Back(void)const
{
	if (size == 0)Error("empty Vector!");
	return data[size - 1];
}
template<typename T>
const T& Vector<T>::Front(void)const
{
	if (size == 0)Error("empty Vector!");
	return data[0];
}
template<typename T>
void Vector<T>::Reserve(int newmax)
{
	if (newmax < max)
	{
		return;
	}
	T* old = data;
	data = new T[newmax];
	for (int i = 0; i < size; i++)
	{
		data[i] = old[i];
	}
	max = newmax;
	delete[]old;
}
template<typename T>
void Vector<T>::Resize(int newSize, const T& item)
{
	if (newSize > max)
	{
		Reserve(2 * max + 1);
	}
	for (int i = size; i < newSize; i++)
	{
		data[i] = item;
	}
	size = newSize;
}
template<typename T>
typename Vector<T>::iterator
Vector<T>::Insert(iterator itr, const T& item)
{
	if (size == max)
	{
		int n = itr - begin();
		Reserve(2 * max + 1);
		itr = begin() + n;
	}
	if(itr<begin()||itr>end())
	{
		Error("Insert:out of range!");
	}
	for (iterator p = end(); p != itr; --p)
	{
		*p = *(p - 1);
	}
	*itr = item;
	size++;
	return itr;
}
template <typename T>
typename Vector<T>::iterator Vector<T>::Erase(iterator itr)
{
	if (Empty())Error("Erase:empty Vector");
	if (itr<begin() || itr>end()-1)
	{
		Error("out of range!");
	}
	for (iterator p = itr ; p != end(); p++)
	{
		*p = *(p+1);
	}
	size--;
	return itr;
}
#endif
