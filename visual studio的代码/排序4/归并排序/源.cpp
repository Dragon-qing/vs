#include<stdio.h>
#include<stdlib.h>
int main()
{
	int leftsize = 1;
	int *left = (int*)malloc(leftsize * sizeof(int));
	free(left);
	system("pause");
	return 0;
}