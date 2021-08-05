#include"Heap.h"
#include"Heapsort.h"
int main()
{
	vector<int>v;
	for (int i = 0; i < 100; i++)
		v.push_back(rand() % 100);
	Heap<int>h(v);
	v.clear();
	int x;
	while (!h.Empty())
	{
		h.DeleteMin(x);
		v.push_back(x);
	}
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << '\t';
	cout << endl << "HeapSort:";
	int a[] = { 4,5,8,9,6,7,6,2 };
	cout << endl << "array:" << endl;
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
		cout << a[i] << '\t';
	cout << endl;
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
		cout << a[i] << '\t';
	cout << endl;
	return 0;
}