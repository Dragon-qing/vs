#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[10] = { 200,5,6,8,4,5,6,9,57,45 };
	int i,n=0,x;
	while (n < 9)
	{
		for (i = 0; i < 9; i++)
		{
			if (a[i] > a[i + 1])
			{
				x = a[i + 1];
				a[i + 1] = a[i];
				a[i] = x;
			}
		}
		n++;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}
