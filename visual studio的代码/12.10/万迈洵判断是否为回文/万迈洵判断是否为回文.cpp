#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int hw(char a[], int n)
{
	int i, j;
	i = 0;
	j = n - 1;
	int is = 1;
	for (; i < j; i++, j--)
	{
		while(a[i] == ' ')i++;
		while(a[j] == ' ')j--;
		if (a[i] != a[j])
		{
			is = 0;
			break;
		}
	}
	return is;
}
int main()
{
	char s[50];
	int i;
	gets_s(s);
	i = hw(s,strlen(s));
	if (i == 1)printf("是回文！");
	else printf("不是回文！");
	system("pause");
	return 0;
}