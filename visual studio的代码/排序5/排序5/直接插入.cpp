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
	int i, j;
	for (i = 2; i <= 10; i++)
	{
		if (a[i] < a[i - 1])
		{
			a[0] = a[i];
			for (j = i - 1; a[0] < a[j]; j--)
			{
				a[j + 1] = a[j];
			}
			a[j + 1] = a[0];
		}
		
	}
	prt(a);
	system("pause");
	return 0;
}