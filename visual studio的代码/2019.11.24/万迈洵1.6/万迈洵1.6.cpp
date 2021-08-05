#include<stdio.h>
#include<stdlib.h>
void swap(int&a, int&b)
{
	int c;
	c = a;
	a = b;
	b = c;
}
void bubbledown(int *p, int tail)
{
	int i;
	for (i = tail - 1; i > 0; i--)
	{
		if (p[i - 1] > p[i])
		{
			swap(p[i - 1], p[i]);
		}
	}
}
void bubbleup(int *a, int pre, int lenth)
{
	int i;
	for (i = pre+1 ; i < lenth; i++)
	{
		if (a[i] < a[i-1])
		{
			swap(a[i], a[i - 1]);
		}
	}
}
void bubbledouble(int a[], int lenth)
{
	int pre = 0,tail=lenth-1;
	while (pre < tail)
	{
		bubbleup(a, pre, lenth);
		pre++;
		if (pre >= tail)break;
		bubbledown(a, tail);
		tail--;
		
		
	}
}
int main()
{
	int a[12] = { 5,6,12,8,1,61,52 ,56,585,1,45,2 };
	bubbledouble(a, 12);
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