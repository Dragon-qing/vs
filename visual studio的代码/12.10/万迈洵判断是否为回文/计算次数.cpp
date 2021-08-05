#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int find(char s[],int length, char t[],int len)
{
	int i = 0; int j = 0;
	int cnt = 0;
	while (i < length)
	{
		if (s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
		if (j == len)
		{
			cnt++;
			j = 0;
		}
	}
	return cnt;
}
int main()
{
	char s[50] = "absract abc";
	char t[50];
	int cnt = 0;
	gets_s(t);
	cnt = find(s, strlen(s), t, strlen(t));
	printf("在%s中%s", s, t);
	printf("有%d次",cnt);
	system("pause");
	return 0;
}