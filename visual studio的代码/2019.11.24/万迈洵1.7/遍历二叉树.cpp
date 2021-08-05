#include<stdio.h>
#include<stdlib.h>
void prt(int a)
{
	printf("%d\n", a);
}
int main()
{
	void(*p)(int a);
	p = &prt;
	(*p)(678);
	system("pause");
	return 0;
}