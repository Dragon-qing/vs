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
	~Vector(void) { delete[]data; }
	Vector& operator=(const Vector<T>& v);		//���Ƹ�ֵ����
	T& operator[](int id) { return(data[id]); }	//�±����������
	const T& operator[](int id)const { return(data[id]); }//�������±����������
	bool Empty(void)const { return(size == 0); }		//�п�
	int Size(void)const { return(size); }			//�����ݸ���
	int Max(void)const { return(max); }			//����������
	void Push_back(const T& item);				//β��
	void Pop_back(void);						//βɾ
	const T& Back(void)const;					//����βԪ�ص�����
	const T& Front(void)const;					//������Ԫ�ص�����
	void Clear(void) { size = 0; }					//��ա�ɾ����������Ԫ��
	void Reserve(int newMax);					//������������Ϊnewmax������ԭ������
	void Resize(int newSize, const T& item = T());	//�����ݸ�������Ϊnewsize��ԭ�������ݱ����������ֵΪitem

//����������
	typedef T* iterator;						//������
	typedef const T* const_iterator;			//ָ��const�����ĵ�����
	iterator begin() { return &data[0]; }			//ʹ������ָ��������ʼλ��
	const_iterator begin()const { return &data[0]; }
	iterator end() { return(&data[size]); }	//ʹ������ָ����������λ��
	const_iterator end()const { return(&data[size]); }
	iterator Insert(iterator itr, const T& item);
	iterator Erase(iterator itr);
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
	return(*this);
}
template<class T>
void Vector<T>::Push_back(const T& item)//β��
{
	if (size == max)			//����ռ�������������Ҫ����������
		Reserve(2 * max + 1);
	data[size++] = item;		//����Ԫ�ص�β�������ݸ�����1
}

template<class T>				//ģ�������
typename Vector<T>::iterator				//����ֵ����
Vector<T>::Erase(iterator itr)	//ɾ��ָʾ��ָ���Ԫ��
{
	if (size == 0)				//����Ƿ��ǿձ�			
		Error("Erase:an empty Vector!");
	if (itr<begin() || itr>end() - 1)//���ɾ��λ���Ƿ�Ϸ�					
		Error("Erase: out of illegal!");
	for (iterator p = itr; p != end(); ++p)
		*p = *(p + 1);
	size--;
	return(itr);
}
template<class T>				//ģ�������
typename Vector<T>::iterator				//����ֵ����
Vector<T>::Insert(iterator itr, const T& item)//��Ԫ��item���뵽ָʾ��ָ���λ��
{
	if (size == max)
		Reserve(2 * max + 1);		//����ռ�������������Ҫ����������
	if (itr<begin() || itr>end())	//������λ���Ƿ�Ϸ�
		Error("Insert:out of range");
	for (iterator p = end(); p != itr; --p)//��βԪ�ص�����λ����Ԫ�������ƶ�һ��λ��
		*p = *(p - 1);
	*itr = item;					//����Ԫ�ص�ָ��λ��
	size++;						//���ݸ�����1
	return(itr);
}
template<class T>
void Vector<T>::Pop_back(void)	//βɾ
{
	if (size == 0)
		Error("Empty Vector!");
	size--;
}

template<class T>
const T& Vector<T>::Back(void)const//����βԪ�ص�����
{
	if (size == 0)
		Error("Empty Vector!");
	return(data[size - 1]);
}
template<class T>
const T& Vector<T>::Front(void)const//������ʼԪ�ص�����
{
	if (size == 0)
		Error("Empty Vector!");
	return(data[0]);
}

template<class T>
void Vector<T>::Reserve(int newmax)
{
	if (newmax < max)			//����������������㣬�򷵻�
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


#endif