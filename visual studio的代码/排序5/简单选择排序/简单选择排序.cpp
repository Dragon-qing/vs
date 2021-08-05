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
int main()
{
	int a[11] = { 0,12,5,6,87,4,51,96,52,1,5 };
	int min,i,j,x;
	for (i = 1; i < 11; i++)
	{
		min = i;
		for (j = i + 1; j < 11; j++)
		{
			if(a[j]<a[min])
			{
				min = j;
			}
		}
		if(i!=min)
		{
			x = a[i];
			a[i] = a[min];
			a[min] = x;
		}
	}
	prt(a);
	system("pause");
	return 0;
}