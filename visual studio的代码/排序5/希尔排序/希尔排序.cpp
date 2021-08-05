#include<stdio.h>
#include<stdlib.h>
void prt(int a[])
{
	int i;
	for (i = 1; i <= 10; i++)
	{
		printf("%d ", a[i]);
	}
}

void shallsort(int a[], int n, int dk);
void shall(int a[], int n, int dlk[], int rnd)
{
	int i;
	for (i = 0; i < rnd; i++)
	{
		shallsort(a, n, dlk[i]);
	}
}
void shallsort(int a[], int n, int dk)
{
	int i,j;
	for (i = dk + 1; i < n; i++)
	{
		if (a[i] < a[i - dk])
		{
			a[0]=a[i];
			for (j = i - dk; a[0] < a[j]; j -= dk)
			{
				a[j + dk] = a[j];
			}
			a[j + dk] = a[0];
		}
	}
}
int main()
{
	int a[11] = { 0,12,5,6,87,4,51,96,52,1,5 };
	int dlk[3] = { 5,3,1 };
	shall(a, 11, dlk, 3);
	prt(a);
	system("pause");
	return 0;
}