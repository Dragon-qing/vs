#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(char*a, char*b)
{
	char c;
	 c = *a;
	*a = *b;
	*b = c;
}
void sort(char*a)
{
	int i, cnt = 1;
	int len = strlen(a);
	while (cnt++ < len)
	{
		for (i = 1; i < len; i++)
		{
			if (a[i] < a[i - 1])
			{
				swap(&a[i], &a[i - 1]);
			}
		}
	}
}
int main()
{
	char a[50];
	gets(a);
	/*puts(a);*/
	sort(a);
	puts(a);
	system("pause");
	return 0;
}
