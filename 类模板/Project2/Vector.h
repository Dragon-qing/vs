
#pragma once
template <typename T>
class Vector

{
private:
	T* data;
	int size;
	int max;
public:
	enum { SPARE_MAX = 3 };  //�˴������ֵ��С�㣬���Դ�������⡣
	explicit Vector(int n = 0) :size(0), max(n + SPARE_MAX)
	{
		data = new T[max];
	}

	Vector(const Vector& v) :data(NULL), max(0) { operator=(v); }

	~Vector() { delete[] data; }

	Vector& operator=(const Vector& v);

	T& operator[](int id) { return data[id]; }
	const T& operator[](int id) const { return data[id]; }

	bool Empty() const { return size == 0; }
	int Size() const { return size; }
	int Max() const { return max; }
	void Clear() { size = 0; }

	typedef T* iterator;     //������
	typedef const T* const_iterator;    //�����͵�����
	iterator Begin() { return data; }
	const_iterator Begin() const { return data; }
	iterator End() { return data + size; }
	const_iterator End() const { return data + size; }

	T& Front() { return data[0]; }
	const T& Front() const { return data[0]; }
	T& Back() { return data[size - 1]; }
	const T& Back() const { return data[size - 1]; }

	void Push_back(const T& item);
	void Pop_back()
	{
		if (!Empty()) size--;
	}

	void Reserve(int newMax);  //������������ΪnewMax��������ԭ��������
	void Resize(int newSize, const T& item = T());   //�����ݸ�������ΪnewSize,����ԭ�������ݣ������ֵΪitem

	iterator Insert(iterator itr, const T& item = T()); //��itr��ָ���λ�ò���item
	iterator Erase(iterator itr); //ɾ��itr��ָ���Ԫ��
};

//��ֵ���������
/************Begin***********************/
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

/************End*************************/

//β����������
/************Begin***********************/
template<typename T>
void Vector<T>::Push_back(const T& item)
{
	if (size == max)
	{
		Reserve(2 * max + 1);
	}
	data[size++] = item;
}

/************End*************************/

//������������ΪnewMax��������ԭ��������
/************Begin***********************/
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

/************End*************************/

//�����ݸ�������ΪnewSize,����ԭ�������ݣ������ֵΪitem
/************Begin***********************/
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

/************End*************************/

//����ָ���������
/************Begin***********************/
template<typename T>
typename Vector<T>::iterator
Vector<T>::Insert(iterator itr, const T& item)
{
	if (size == max)
	{
		int n = itr - Begin();
		Reserve(2 * max + 1);
		itr = Begin() + n;
	}
	if (itr<Begin() || itr>End())
	{
		exit(1);
	}
	for (iterator p = End(); p != itr; --p)
	{
		*p = *(p - 1);
	}
	*itr = item;
	size++;
	return itr;
}

/************End*************************/

//����ָ��ɾ������
/************Begin***********************/

template <typename T>
typename Vector<T>::iterator Vector<T>::Erase(iterator itr)
{
	if (Empty())exit(1);
	if (itr<Begin() || itr>End() - 1)
	{
		exit(1);
	}
	for (iterator p = itr; p != End(); p++)
	{
		*p = *(p + 1);
	}
	size--;
	return itr;
}
/************End*************************/
