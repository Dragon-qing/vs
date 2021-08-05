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
	int low, i, high, mid,j;
	for (i = 2; i < 11; i++)
	{
		if (a[i] < a[i - 1])
		{
			a[0] = a[i];
			low = 1;
			high = i - 1;
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (a[0] < a[mid]) { high = mid - 1; }
				else { low = mid + 1; }
			}
			for (j = i - 1; j >= high + 1; j--)
			{
				a[j+1] = a[j];
			}
			a[high + 1] = a[0];
		}
	}
	prt(a);
	system("pause");
	return 0;
}