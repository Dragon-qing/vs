#include<stdio.h>
#include<stdlib.h>
void swap(int&a, int&b);
void bubbledown(int*p, int n)
{
	int i,cnt=1;
	while (cnt <n-1)
	{
		for (i = 1; i <n; i++)
		{
			if (p[i] < p[i - 1])
			{
				swap(p[i], p[i - 1]);
			}
		}
		cnt++;
	}
}
void swap(int&a, int&b)
{
	int c;
	c = a;
	a = b;
	b = c;
}
int main()
{
	int a[12] = { 5,6,12,8,1,61,52 ,56,585,1,45,2 };
	bubbledown(a, 12);
	{
		int i;
		for (i = 0; i < 12; i++)
		{
			printf("%d ", a[i]);
		}
	}
	system("pause");
	return 0;
}