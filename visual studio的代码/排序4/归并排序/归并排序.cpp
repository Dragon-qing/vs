#include<stdio.h>
#include<stdlib.h>
void merge(int *a, int start, int mid,int end)
{
	int *temp = (int *)malloc((end - start + 1) * sizeof(int));
	int i = start;
	int j = mid+1;
	int k = 0;
	while (i <= mid && j <= end)
	{
		if (a[i] <= a[j]) { temp[k++] = a[i++]; }
		else { temp[k++] = a[j++]; }
	}
	while (i <= mid) { temp[k++] = a[i++]; }
	while (j <= end) { temp[k++] = a[j++]; }
	for (i = 0; i < k; i++)
	{
		a[start+i] = temp[i];
	}
	free(temp);
}
void mergesort(int a[], int start, int end)
{
	int mid = (start+end) / 2;
	if (start >= end) { return ; }
	mergesort(a, start, mid);
	mergesort(a, mid + 1, end);
	merge(a, start, mid, end);
}
int main()
{
	int a[] = { -1,-25,65,-6,588,5,96,56,24,5 };
	mergesort(a, 0, 9);
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}