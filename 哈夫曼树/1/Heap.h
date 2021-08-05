#pragma once
#include<iostream>
#include<vector>
using namespace std;
template<class T>
class Heap
{
	vector<T> vec;
	int size;
	void BuildHeap();
	void PercolateDown(int h);
	void PercolateUp();
public:
	explicit Heap(int max = 100) :vec(max), size(0) {}
	explicit Heap(const vector<T>& vt);
	bool Empty()const { return size == 0; }
	int Size() { return size; }
	void Insert(const T& item);
	const T& Top()const { return vec[0]; }
	void DeleteMin();
	void DeleteMin(T& item);
	void Clear() { size = 0; };
};
template<class T>
void Heap<T>::PercolateDown(int h)
{
	int p = h, c = 2 * p + 1;
	T temp = vec[p];
	while (c < size)
	{
		if (c + 1 < size && vec[c + 1] < vec[c])
			++c;
		if (temp <= vec[c])
			break;
		else {
			vec[p] = vec[c];
			p = c;
			c = 2 * p + 1;
		}

	}
	vec[p] = temp;
}
template<class T>
void Heap<T>::DeleteMin()
{
	if (size == 0) {
		cout << "Heap empty!" << endl;
		exit(1);
	}
	vec[0] = vec[size - 1];
	size--;
	PercolateDown(0);
}
template<class T>
void Heap<T>::DeleteMin(T& item)
{
	if (size == 0) {
		cout << "Heap is empty!" << endl;
		exit(1);
	}
	item = vec[0];
	vec[0] = vec[size - 1];
	size--;
	PercolateDown(0);
}
template<class T>
void Heap<T>::PercolateUp()
{
	int c = size - 1, p = (c - 1) / 2;
	T temp = vec[c];
	while (c > 0)
		if (vec[p] <= temp)
			break;
		else {
			vec[c] = vec[p];
			c = p;
			p = (c - 1) / 2;
		}
	vec[c] = temp;
}
template<class T>
void Heap<T>::Insert(const T& item)
{
	if (size == vec.size()) {
		vec.resize(vec.size() * 2);
	}
	vec[size] = item;
	size++;
	PercolateUp();
}
template<class T>
Heap<T>::Heap(const vector<T>& vt) :vec(vt.size() + 10), size(vt.size())
{
	for (int i = 0; i < size; ++i) {
		vec[i] = vt[i];
	}
	BuildHeap();
}
template<class T>
void Heap<T>::BuildHeap()
{
	for (int i = size / 2 - 1; i >= 0; --i)
		PercolateDown(i);
}