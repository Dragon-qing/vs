#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i=1,n,j;
	int a[100],x;
	scanf_s("%d", &x);
	while (x != 0) {
		a[i] = x;
		i++;
		scanf_s("%d", &x);
	}
	for (n = 1; n < i ; n++)
	{
		printf("%d ",a[n]);
	}
	printf("\n");
	for (n = 2; n < i ; n++)
	{
		if(a[n]<a[n-1])
		{
			a[0] = a[n];
			for (j = n - 1; a[0] < a[j]; j--)
			{
				a[j + 1] = a[j];
		 }
			a[j + 1] = a[0];
		}
	}
	for (n = 1; n < i ; n++)
	{
		printf("%d ", a[n]);
	}
	system("pause");
	return 0;
}