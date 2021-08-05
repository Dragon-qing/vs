#include<stdio.h>
#include<stdlib.h>
int sort(int a[], int l,int h)
{
	int p = a[l];
	int low, high;
	low = l;
	high = h;
	a[0] = a[low];
	while (low < high)
	{
		while (low<high&&a[high] >= p) { high--; }
		a[low] = a[high];
		while (low < high&&a[low] <= p) { low++; }
		a[high] = a[low];
	}
	a[low] = a[0];
	return low;
}
void qsort(int a[], int low,int high)
{
	int mid = sort(a, low, high);
	if (low < high)
	{
		
		qsort(a, low, mid-1);
		qsort(a, mid + 1, high);
	}
}
int main()
{
	int a[] = { 0,12,25,4,-6,-49,58,69,34,641,5,84 };
	qsort(a, 1, 11);
	int i;
	for (i = 1; i < 12; i++) { printf("%d ", a[i]); }
	system("pause");
	return 0;
}