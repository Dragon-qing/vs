#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char*x(int a)
{
	char b[10];
	char*p = (char*)malloc(sizeof(char) * 10);
	int n,i=0,len;
	char x;
	while(a>0)
	{
		n = a % 16;
		a /= 16;
		if (n >= 10)
		{
			x = 'A' + n - 10;
		}
		else { x = '0' + n; }
		b[i++] = x;
	}
	b[i] = '\0';
	len = strlen(b);
	for (i = 0; i < len; i++)
	{
		p[i] = b[len - 1 - i];
	}
	p[i] = '\0';
	return p;
}
int main()
{
	char*a;
	int f;
	scanf_s("%d", &f);
	a = x(f);
	puts(a);
	system("pause");
	return 0;
}