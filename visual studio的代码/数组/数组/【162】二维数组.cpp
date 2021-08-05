#include<stdio.h>
#include<stdlib.h>
void print(int(*p)[5]);
int main()
{
	int a[5][5] = { {12,5,6,89,56},{156,65,89,13,56},{15,68,95,624,52},
	{15,89,64,85,25},{568,956,24,1,5,} };
	int(*p)[5];
	p = a;
	print(p);
	system("pause");
	return 0;
}
void print(int(*p)[5])
{
	int row, col;
	for (row = 0; row < 5; row++)
	{
		for (col = 0; col < 5; col++)
		{
			printf("%d\t", p[row][col]);
		}
		printf("\n");
	}
}