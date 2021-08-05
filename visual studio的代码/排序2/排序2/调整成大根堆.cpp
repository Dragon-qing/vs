#include<stdio.h>
#include<stdlib.h>
void heapadjust(int a[], int s,int m)
{
	int j,rc,i;
	rc = a[s];
	for (i =2*s ; i<=m; i*=2)
	{
		if (i<m&&a[i] > a[i + 1]) { i++; }
		if (rc <= a[i]) { break; }
		a[s] = a[i];
		s = i;
	}
	a[s] = rc;
}
int main()
{
	int a[] = { 0,30,12,13,19,21 };
	heapadjust(a, 1, 5);
	int i;
	for (i = 1; i < 6; i++) { printf(" %d", a[i]); }
	system("pause");
	return 0;
}