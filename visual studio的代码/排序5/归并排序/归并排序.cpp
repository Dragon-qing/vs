#include<stdio.h>
#include<stdlib.h>
void merge(int a[], int start, int mid, int end)
{
	int *temp = (int*)malloc(sizeof(int)*(end - start + 1));
	int i, j,k=0;
	i = start, j = mid + 1;
	while (i <= mid && j <= end)
	{
		if (a[i] < a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];
		}
	}
	while (i <= mid) { temp[k++] = a[i++]; }
	while (j <= end) { temp[k++] = a[j++]; }
	for (i = 0; i < k; i++)
	{
		a[start +i] = temp[i];
	}
	free(temp);
}
void mergesort(int a[], int start, int end)
{
	int mid=(start+end)/2;
	if (start >= end) { return; }
	mergesort(a, start, mid);
	mergesort(a, mid + 1, end);
	merge(a, start, mid, end);
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
	mergesort(a, 1, 10);
	prt(a);
	system("pause");
	return 0;
}
