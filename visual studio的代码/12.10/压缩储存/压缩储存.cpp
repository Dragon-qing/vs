/*
4 8 1 4 2
8 5 6 5 8
1 6 2 9 9
4 5 9 3 7
2 8 9 7 3
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[15] = { 4,8,5,1,6,2,4,5,9,3,2,8,9,7,3 };
	int i, j,k;
	scanf("%d %d", &i, &j);
	if (i < j) { int k = i; i = j; j = k; }
	k = (i + 1)*i / 2 + j;
	printf("%d", a[k]);
	system("pause");
	return 0;
}