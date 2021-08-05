#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
int maxnumber(int a[], int start,int end)
{
	int maxnumber=start;
	int i;
	for (i = start + 1; i <= end; i++)
	{
		if (a[maxnumber] < a[i])
		{
			maxnumber = i;
		}
	}
	return maxnumber;
}
void sort(int a[], int n)
{
	int i,start=0,end=n-1,x;
	for (i = 0; i < n-1; i++)
	{
		x=maxnumber(a, start, end);
		swap(&a[x], &a[start]);
		start++;
	}
}
int main()
{
	int a[10] = { -1,-2,56,888,623,51,2,5,64,3 };
	sort(a, 10);
	int i;
	for(i=0;i<10;i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}