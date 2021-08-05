#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[100];
	int i, n=0, j,x;
	int low, mid, high;
	scanf_s("%d", &x);
	while (x != 0)
	{
		a[n + 1] = x;
		n++;
		scanf_s("%d", &x);
	}
	for (i = 1; i < n + 1; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
	
	for (i = 2; i < n + 1; i++)
	{
		if (a[i] < a[i - 1])
		{
			a[0] = a[i];
			high = i - 1;
			low = 1;
			j = i - 1;
			while (low <= high)
			{
				mid = (high + low) / 2;
				if (a[0] > a[mid]) { low=mid+1; }
				else { high = mid - 1; }
			}
			for(j;j>=high+1;j--)
			{
				a[j + 1] = a[j];
			}
			a[low] = a[0];
		}
	}
	for (i = 1; i < n + 1; i++)
	{
		printf("%d\t", a[i]);
	}
	system("pause");
	return 0;
}