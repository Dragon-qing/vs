#include<stdio.h>
#include<stdlib.h>
void heapadjust(int a[], int s, int m)
{
	int i, rc;
	rc = a[s];
	for (i = s * 2; i <= m; i =i* 2)
	{
		if (a[i + 1] < a[i]) { i++; }
		if (rc < a[i]) { break; }
		a[s] = a[i];
		s = i;
	}
	a[s] = rc;
}
void heap(int a[], int n)
{
	int i;
	for (i = n / 2; i >= 1; i--)
	{
		heapadjust(a, i, n);
	}
}
int main()
{
	int a[] = { 0,11,56,8,45,6,9,12,356,2,4,56 };
	heap(a, 11);
	int i;
	for (i = 1; i < 12; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}