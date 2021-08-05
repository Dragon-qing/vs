#include<stdio.h>
int step = 0;
int x, y, l;
int m, n;
int vis1[100] = { 0 };
int vis2[100] = { 0 };
int main()
{
	int i=0,j;
	scanf_s("%d %d %d %d %d", &x, &y, &m, &n, &l);
	while (x != y)
	{
		x = x + m;
		if (x > l)x = x - l;
		y = y + n;
		if (y > l)y = y - l;
		vis1[i] = x;
		vis2[i] = y;
		i++;
		step++;
		for (j = 0; j < i-1; j++)
		{
			if (x == vis1[i] || y == vis2[i])
			{
				printf("Impossible\n");
				return 0;
			}
		}
		if (x == y)
		{
			printf("%d\n", step);
			return 0;
		}
	}
	return 0;
}
//1 2
//4 1
//2 5
//5 4
//3 3
//1 2
//4 6
//1 4
//4 2
//1 6
//4 4