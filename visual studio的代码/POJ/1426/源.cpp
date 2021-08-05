#include<stdio.h>
#include<stdlib.h>
int f, n;
void dfs(unsigned long long m,int deep)
{
	if (f == 1 || deep > 18)
	{
		f = 0;
		return;
	}
	if (m % n == 0)
	{
		f = 1;
		printf("%lld\n", m);
	}
	dfs(m * 10, deep + 1);
	dfs(m * 10 + 1, deep + 1);
}
int main()
{
	unsigned long long m=1;
	n = 1;
	while (n != 0)
	{
		f = 0;
		scanf("%lld", &n);
		dfs(m, 0);
	}
	return 0;
}