#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[5][3] = { {1,2,3},{2,3,4},{4,5,6},{7,8,9},{8,9,10} };
	int row, col;
	for (row = 0; row < 5; row++)
	{
		for (col = 0; col < 3; col++)
		{
			printf("%d\t",a[0][row*3+col] );
		}
		printf("\n");
	}
	system("pause");
	return 0;
}