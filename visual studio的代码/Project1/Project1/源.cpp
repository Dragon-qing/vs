#include<stdio.h>
#include<stdlib.h>
int  findmax(int *p, int n);
void selectdown(int *p, int n);
int pd(int *p, int n, int key);
int main()
{
	int item;
	int a[5];
	int i;
	printf("please input number:");
	/*scanf_s("%d", &item);*/
	for (i = 0; i < 5; i++)
	{
		scanf_s("%d", &item);
		a[i] = item;
	}
	selectdown(a, 5);
	/*if (pd(a, 5, item) == 0) {
		printf("exit:");
	}
	else
	{
		printf("dispear:");
	}*/
	for (i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}
int findmax(int *p, int n)
{
	int max = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		if (p[max] <= p[i])
		{
			max = i;
		}
	}
	//printf("%d", max);
	return max;
}
void selectdown(int *p, int n)
{
	int max;
	int i = 0;
	int temp;
	for (i = 0; i < n ; i++) {
		max = findmax(p + i, n - i);//1
		temp = p[max+i];
		p[max+i] = p[i];
		p[i] = temp;
		//n--;
		/*printf("%d\n", p[i]);*/
	}
}
int pd(int *p, int n, int key)
{
	int i;
	for (i = 0; i < n; i++) {
		if (key == p[i])
		{
			return 0;
		}
	}
	return 1;
}


