#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[11] = { 0,123,56,8,9,-1,47,84,59,2,5 };//a[0]”√¿¥¥¢¥Ê
	int i, j;
	for (i = 2; i < 11; i++)
	{
		if (a[i] < a[i - 1]) {
			a[0] = a[i];
			for (j = i - 1; a[0] < a[j]; j--)
			{
				a[j + 1] = a[j];
			}
			a[j+1] = a[0];
		}
	}
	for (i = 1; i < 11; i++) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}