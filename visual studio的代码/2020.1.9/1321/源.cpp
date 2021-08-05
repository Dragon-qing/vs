#include<stdio.h>
#include<stdlib.h>
char map[10][10];
int vis[10] = { 0 };
int n, k;
int m;//放入棋盘的棋子
int sum;//方案
void dfs(int x)
{
	int j; 
	if (m == k)
	{
		sum++;
		return;
	}
	if (x >= n)
	{
		return;
	}
	for ( j = 0; j < n; j++)
	{
		if (map[x][j] == '#' && vis[j] == 0)
		{
			m++;
			vis[j] = 1;
			dfs(x+1);
			vis[j] = 0;
			m--;
		}
	}
	dfs(x+1);
}
int main()
{
	int i;
	scanf("%d %d", &n, &k);
	while ( n != -1 && k != -1)
	{
		m = 0;
		sum = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%s", &map[i]);
		}
		dfs(0);
		printf("%d\n", sum);
		 scanf("%d %d", &n, &k);
	}
	return 0;
}
