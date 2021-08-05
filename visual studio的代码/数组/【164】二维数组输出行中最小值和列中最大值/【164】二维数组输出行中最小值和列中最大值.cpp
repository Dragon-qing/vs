#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int row, col ;
void max(int a[][5])
{
	int max[5],z;
for (z = 0; z < 5; z++) {
	max[z] = a[0][z];
}
	for (col = 0; col < 5; col++)
	{
		for (row = 0; row < 3; row++)
		{
			if (a[row][col] > max[col]) { max[col] = a[row][col]; }
		}
	}
	printf("max:");
	for (z = 0; z < 5; z++) { printf("\t%d\t",max[z]); }
	printf("\n");
}
void min(int a[][5])
{
	int min[3];
	for (row = 0; row < 3; row++)
	{
		min[row] = a[row][0];
	}
	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 5; col++)
		{
			if (min[row] > a[row][col]) {
				min[row] = a[row][col];
			}
		}
	}
	printf("min:");
	for (row = 0; row < 3; row++)
	{
		printf("\t%d\t", min[row]);
	}
	printf("\n");
}
int main()
{
	int a[3][5] = { {129,5,6,98,5},{568,152,35,6,9},{58,999,65,2,1} };
	for (row = 0; row < 3; row++)
	{
		for(col=0;col<5;col++)
		{
			printf("\t%d\t", a[row][col]);
		}
		printf("\n");
	}
	max(a);
	min(a);
	system("pause");
	return 0;
}