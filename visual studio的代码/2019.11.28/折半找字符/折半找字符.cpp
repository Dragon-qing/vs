#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char findstr(char*a,char b,int *e)
{
	int low = 0, high = strlen(a)-1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (a[mid] == b) { *e = mid; return 1; }
		else if (b < a[mid]) { high = mid - 1; }
		else { low = mid + 1; }
	}
	if (low > high)return 0;
}
int main()
{
	char a[10] = "abcdefgh",x,s;
	int index=-1;
	scanf("%c", &s);
	x=findstr(a, s, &index);
	if (x == 1)printf("������Ҫ�ҵ�ֵ����%dλ��", index);
	else { printf("δ�ҵ���"); }
	system("pause");
	return 0;
}
