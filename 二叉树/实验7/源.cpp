#include"BTNode.h"
int main()
{
	int v[] = { 1,5,4,8,6,3,4 };
	int n = sizeof(v) / sizeof(v[0]);
	QuickSort(v,n);
	for (int i = 0; i < n; ++i)
		cout << v[i];
	return 0;
}