#include<stdio.h>
#include<stdlib.h>
int partition(int a[],int low,int high)
{
	int pivokey = a[low];
	a[0] = a[low];
	while (low < high)
	{
		while (low < high&&a[high] >= pivokey) { high--; }
		a[low] = a[high];
		while (low < high&&a[low] <= pivokey) { low++; }
		a[high] = a[low];
	}
	a[low] = a[0];
	return low;
}
void sort(int a[], int low, int high)
{
	if (low < high) {
		int pivotloc = partition(a, low, high);
		sort(a, low, pivotloc - 1);
		sort(a, pivotloc + 1, high);
	}
}
int main()
{
	int a[11] = { 0,52,6,4,89,513,56,48,526,3,1 };
	partition( a,1,10);
	int i;
	for (i = 1; i < 11; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}