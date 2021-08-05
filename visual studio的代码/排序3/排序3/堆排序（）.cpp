#include<stdio.h>
#include<stdlib.h>
void heapadjust(int a[], int s, int m)
{
	int i,  rc;
	rc = a[s];
	for (i = 2 * s; i <= m; i *= 2)
	{
		if (i<m&&a[i + 1] > a[i]) { i++; }
		if (rc > a[i]) { break; }
		a[s] = a[i];
		s = i;
	}
	a[s] = rc;
}
void swap(int *a, int *n)
{
	int x;
	x = *a;
	*a = *n;
	*n = x;
}
void heap(int a[], int n)
{
	int i;
	for (i = n / 2; i >= 1; i--)
	{
		heapadjust(a, i,n);
	}
	for (i = n; i > 1; i--)
	{
		swap(&a[1], &a[i]);
		heapadjust(a, 1, i - 1);
	}
}
int main()
{
	int a[] = { 0,12,58,-2,56,888,1111,25,63,2,5 };
	int i;
	heap(a, 10);
	for(i=1;i<11;i++)
	{
		printf("%d ",a[i]);
	}
	system("pause");
	return 0;
}