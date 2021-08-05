#include<stdio.h>
#include<stdlib.h>
void heapadjust(int a[], int s, int e)
{
	int rc = a[s];
	int j;
	for (j = 2 * s; j <= e; j *= 2)
	{
		if (j<e&&a[j+1] > a[j])
		{
			j++;
		}
		if (rc >= a[j]) { break; }
		a[s] = a[j];
		s = j;
	}
	a[s] = rc;
}
void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
void heapsort(int a[],int n)
{
	int i;
	for (i = (n-1) / 2; i >= 1; i--)
	{
		heapadjust(a, i, n - 1);
	}
	for (i = n-1; i > 1; i--)
	{
		swap(&a[i], &a[1]);
		heapadjust(a, 1, i - 1);
	}
}
void prt(int a[])
{
	int i;
	for (i = 1; i <= 10; i++)
	{
		printf("%d ", a[i]);
	}
}
int main()
{
	int a[11] = { 0,12,5,6,87,4,51,96,52,1,5 };
	heapsort(a, 11);
		prt(a);
	system("pause");
	return 0;
}