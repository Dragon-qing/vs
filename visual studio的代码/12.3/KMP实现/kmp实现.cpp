#include<stdio.h>
#include<stdlib.h>
typedef struct sstring
{
	char ch[50];
	int length;
}sstring;
void get_next(int next[], sstring t)
{
	int i = 1, j = 0;
	next[1] = 0;
	while (i < t.length)
	{
		if (j == 0 || t.ch[i] == t.ch[j])
		{
			i++; j++;
			next[i] = j;
		}
		else { j = next[j]; }
	}
}
int kmp(sstring s, sstring t, int pos, int next[])
{
	int i=pos, j=1;
	while (i < s.length&&j <=t.length)
	{
		if (j == 0 || t.ch[j] == s.ch[i])
		{
			i++; j++;
		}
		else { j = next[j]; }
	}
	if (j > t.length)
	{
		return i - t.length;
	}
	else { return 0; }
}
int main()
{
	sstring t = { {0,'a','b','c','a','a','b','b','c','a','b','c','a','a','b','d','a','b'},17 };
	sstring s = { {"abxabcaabbcabcaabdabkj"},22 };
	int next[18] = {0};
	int i;
	get_next(next, t);
	int ret = kmp(s, t, 0,next);
	printf("next[]=");
	for (i = 1; i < 18; i++)printf("%d ", next[i]);
	if (ret != 0)printf("\nÔÚs.ch[%d]Î»ÖÃ\n", ret); else printf("\nÎ´ÕÒµ½£¡\n");
	system("pause");
	return 0;
}