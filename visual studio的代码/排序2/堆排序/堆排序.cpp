#include<stdio.h>
#include<stdlib.h>
void heapadjust(int a[], int s, int m)
{
	int i, rc;
	rc = a[s];
	for (i = 2 * s; i <= m; i *=2)
	{
		if (i<m&&a[i + 1] < a[i]) { i++; }
		if (rc < a[i]) { break; }
		a[s] = a[i];
		s = i;
	}
	a[s] = rc;
}
void swap(int *a, int *b);
void heap(int a[], int n)
{
	int i;
	for (i = n / 2; i >= 1; i--)
	{
		heapadjust(a, i, n);
	}
	for (i = n; i > 1; i--)
	{
		swap(&a[1], &a[i]);
		heapadjust(a, 1, i - 1);
	}
}
void swap(int* a, int* b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
void print(int a[], int n)
{
	int i;
	for (i = n-1; i > 0; i--)
	{
		printf("%d\t", a[i]);
	}
}
int main()
{
	int a[] = { 0,11,56,8,45,6,9,12,356,2,4,56 };
	heap(a, 11);
	print(a, 12);
	system("pause");
	return 0;
}