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
	int i,j;
	for (i = 1; i < 10; i++)
	{
		for (j = 2; j < 11; j++)
		{
			if (a[j] < a[j - 1])
			{
				int x;
				x = a[j];
				a[j] = a[j - 1];
				a[j - 1] = x;
			}
		}
	}
	prt(a);
	system("pause");
	return 0;
}