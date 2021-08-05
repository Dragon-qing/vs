#include<stdio.h>
#include<stdlib.h>
void partition(int a[],int n )
{
	int low=1;
	int high=n-1;
	int pivokey = a[low];
	a[0] = a[low];
	while (low < high)
	{
		while (low < high&&a[high] >= pivokey) { high--; }
		a[low] = a[high];
		while (low < high&&a[low] <= pivokey) { low++; }
		a[high] = a[low];
	}
	a[low] = a[0];
}
int main()
{
	int a[11] = { 0,56,38,12,198,52,89,62,4,5,1 };
	partition(a, 11);
	{
		int i;
		for (i = 1; i < 11; i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n56ÎªÖ§µã\n");
	}
	system("pause");
	return 0;
}