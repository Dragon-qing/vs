#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[10] = { 1,5,6,8,4,5,6,99,4,5 };
	int x,i,j;
	for (i = 1;i < 10; i++)
	{
		if (a[i] < a[i - 1]) {
			x = a[i];
			for (j = i - 1; x < a[j] && j>0; j--)
			{
				a[j + 1] = a[j];
			}
			a[j+1] = x;
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}