#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[10] = { 1,56,4,5,89,56,45,45,5,7 };
	int min;
	int i,j,x;
	for (i = 0; i < 10; i++)
	{
		min = i;
		for (j = i + 1; j < 10; j++)
		{
			if (a[j] < a[min]) { min = j; }	
		}
		if (min != i) { x = a[i]; a[i] = a[min]; a[min] = x; }
	}
	for (i = 0; i < 10; i++) { printf("%d\t", a[i]); }
	system("pause");
	return 0;
}