#pragma once
template<class T>
void PercolateDown(T* pa, int pos, int size)
{
	int p = pos, c = 2 * p + 1;
	T temp = pa[p];
	while (c < size)
	{
		if (c + 1 < size && pa[c + 1] > pa[c])
			++c;
		if (temp >= pa[c])
			break;
		else {
			pa[p] = pa[c];
			p = c; c = 2 * p + 1;
		}
	}
	pa[p] = temp;
}
template<class T>
void BuildHeap(T* pa, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		PercolateDown(pa, i, size);
}

template<class T>
void HeapSort(T* pa, int n)
{
	T temp;
	BuildHeap(pa, n);
	for (int i = n - 1; i > 0; --i) {
		temp = pa[0];
		pa[0] = pa[i];
		pa[i] = temp;
		PercolateDown(pa, 0, i);
	}
}