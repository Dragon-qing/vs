
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
	T* data;						//ָ��̬����ָ��
	int size;						//���������Ԫ�ظ���
	int max;						//��������
	void Error(const char* cs)const { cout << cs << endl; exit(1); }//������Ϣ����
public:
	enum { SPARE_MAX = 16 };				//ö�ٳ�����ʾ������С����
	explicit Vector(int n = 0) :size(0), max(n + SPARE_MAX)
	{
		if (max > 0) data = new T[max];
	}
	Vector(const Vector& v) :data(NULL), max(0) { operator=(v); }//���ƹ��캯��
	~Vector() { delete[]data; }
	Vector& operator=(const Vector<T>& v);		//���Ƹ�ֵ����
	T& operator[](int id) { return data[id]; }		//�±����������
	const T& operator[](int id)const { return data[id]; }//�������±����������
	bool Empty()const { return size == 0; }			//�п�
	bool isFull() const { return size == max; } //����
	int Size()const { return size; }				//�����ݸ���
	int Max()const { return max; }					//����������
	void Clear() { size = 0; }						//��ա�ɾ����������Ԫ��
	//����������
	typedef T* iterator;						//������
	typedef const T* const_iterator;			//ָ��const�����ĵ�����

	iterator Begin() { return data; }				//ʹ������ָ��������ʼλ��
	const_iterator Begin()const { return data; }
	iterator End() { return data + size; }			//ʹ������ָ���������һ������Ԫ�صĺ��
	const_iterator End()const { return data + size; }

	const T& Front()const { return data[0]; }		//������Ԫ�ص�����(���Է���*begin())
	T& Front() { return data[0]; }
	const T& Back()const { return data[size - 1]; }	//����βԪ�ص�����(���ܷ���*--end())
	T& Back() { return data[size - 1]; }
	void Push_back(const T& item);              //β��
	void Pop_back() { size--; }					//βɾ
	void Reserve(int newMax);					//������������Ϊnewmax������ԭ������
	void Resize(int newSize, const T& item = T());	//�����ݸ�������Ϊnewsize������ԭ�������ݣ������ֵΪitem
	iterator Insert(iterator itr, const T& item);
	iterator Erase(iterator itr);

	iterator Erase(iterator first, iterator last); //ɾ��[first,last)��������ݣ����ص�ǰ���ݵ�λ�á�
	void Insert(iterator pos, iterator first, iterator last);//��pos��������һ��Vector����ָ������[first, last)������
	void Swap(Vector<T>& v); //��������Vector�е����ݡ�
};

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)//���Ƹ�ֵ����
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

template<class T>				//ģ�������
typename Vector<T>::iterator				//����ֵ����
Vector<T>::Erase(iterator itr)	//ɾ��ָʾ��ָ���Ԫ��
{
	for (iterator p = itr, q = itr + 1; q != data + size; ++p, ++q)
		*p = *q;
	size--;
	return itr;
}

template<class T>	//��Ԫ��item���뵽������itr��λ��
typename Vector<T>::iterator Vector<T>::Insert(iterator itr, const T& item)
{
	/*******************���ڴ˴�д����Ա�����Ķ���***********************/
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

	size++;						//���ݸ�����1
}

template<class T>
void Vector<T>::Reserve(int newmax)
{
	if (newmax < max)			//������������������򷵻�
		return;
	T* old = data;			//����ԭ����
	data = new T[newmax];		//���·���������		
	for (int i = 0; i < size; i++)	//��ԭ�����е����ݸ��Ƶ�������
		data[i] = old[i];
	max = newmax;				//�޸���������
	delete[]old;			//�ͷ�ԭ����ռ�			
}

template<class T>//���ݸ�����Ϊnewsize��ԭ���ݱ��������ӵ�����Ԫ�س�ʼ��Ϊitem
void Vector<T>::Resize(int newsize, const T& item)
{
	if (newsize > max)					//�������Ԫ�ظ���������������
		Reserve(newsize * 2 + 1);		//������������
	for (int i = size; i < newsize; i++)	//�����ӵ�����Ԫ�س�ʼ��Ϊitem
		data[i] = item;
	size = newsize;
}

template<class T>
typename Vector<T>::iterator Vector<T>::Erase(iterator first, iterator last)
{
	/*******************���ڴ˴�д����Ա�����Ķ���*********************/
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
	/*******************���ڴ˴�д����Ա�����Ķ���*********************/
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
	/*******************���ڴ˴�д����Ա�����Ķ���*********************/
	Vector<T> temp = *this;
	*this = v;
	v = temp;
	/******************************************************************/
}
#endif
