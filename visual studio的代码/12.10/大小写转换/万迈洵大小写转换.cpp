#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void switchs(char s[], int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		if (s[i] <= 'Z'&&s[i] >= 'A')
		{
			s[i] += 'a' - 'A';
		}
	}
}
int main()
{
	char a[50];
	gets_s(a);
	switchs(a,strlen(a));
	puts(a);
	system("pause");
	return 0;
}