#include<assert.h>
template <class T>
class Array {
private:
	T* list;
	int size;
public:
	Array(int sz = 50);				Array(const Array<T>& a);
	~Array();
	Array<T>& operator = (const Array<T>& rhs);
	T& operator [] (int i);
	const T& operator [] (int i) const;		operator T* ();
	operator const T* () const;
	int getSize() const;
	void resize(int sz);
};
//构造函数
template <class T>
Array<T>::Array(int sz) {
	assert(sz >= 0);
	size = sz;
	list = new T[size];
}

//析构函数
template <class T>
Array<T>::~Array() {
	delete[] list;
}
template <class T>
Array<T>::Array(const Array<T>& a) {
	size = a.size;

	list = new T[size];

	//从对象X复制数组元素到本对象  
	for (int i = 0; i < size; i++)
		list[i] = a.list[i];
}
template <class T>
Array<T>& Array<T>::operator = (const Array<T>& rhs) {
	if (&rhs != this) {
		if (size != rhs.size) {
			delete[] list;					      size = rhs.size;
			list = new T[size];
		}
		//从对象X复制数组元素到本对象  
		for (int i = 0; i < size; i++)
			list[i] = rhs.list[i];
	}
	return *this;
}
template <class T>
T& Array<T>::operator[] (int n) {
	assert(n >= 0 && n < size);
	return list[n];
}


template <class T>
const T& Array<T>::operator[] (int n) const {
	assert(n >= 0 && n < size);
	return list[n];
}

template <class T>
Array<T>::operator T* () {
	return list;
}

template <class T>
Array<T>::operator const T* () const {
	return list;
}
//取当前数组的大小
template <class T>
int Array<T>::getSize() const {
	return size;
}

//将数组大小修改为sz
template <class T>
void Array<T>::resize(int sz) {
	assert(sz >= 0);
	if (sz == size)
		return;
	T* newList = new T[sz];
	int n = (sz < size) ? sz : size;
	//将原有数组中前n个元素复制到新数组中
	for (int i = 0; i < n; i++)
		newList[i] = list[i];
	delete[] list;
	list = newList;
	size = sz;
}
