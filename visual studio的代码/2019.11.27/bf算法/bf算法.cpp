#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxlen 255
typedef struct
{
	char ch[maxlen + 1];
	int length;
}sstring;//Ë³Ðò
int index(sstring s, sstring t,int pos)
{
	int i, j;
	i = pos; j = 0;
	while (i <= s.length && j <= t.length-1)
	{
		if (s.ch[i] == t.ch[j])
		{
			i++;
			j++;
		}
		else { i = i - j + 2; j = 0; }
	}
	if (j > t.length-1) { return i - t.length; }
	else return 0;
}
int main()
{
	sstring s, t;
	gets_s(s.ch);
	s.length = strlen(s.ch);
	gets_s(t.ch);
	t.length = strlen(t.ch);
	printf("%d\n", index(s, t, 0));
	system("pause");
	return 0;
}