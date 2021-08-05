#include<stdio.h>
#include<stdlib.h>
void f(int a[10]);
int main()
{
	int a[10] = {1,5,6,8,9,56,5,4,4,5};
	f(a);
	system("pause");
	return 0;
}
void f(int a[1])
{
	printf("%d", a[9]);
	printf("hello");
}