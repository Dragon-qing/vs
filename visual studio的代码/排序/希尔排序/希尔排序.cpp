#include<stdio.h>
#include<stdlib.h>
void shallpx(int a[], int n, int dk);
void shall(int a[],int n, int dlk[], int k)
{
	int i;
	for (i = 0; i < k; i++)
	{
		shallpx(a,n, dlk[i]);
	}
}
void shallpx(int a[],int n, int dk)
{
	int j,i;
	for (i = dk + 1; i < n; i++)
	{
		if (a[i] < a[i - dk]) {
			a[0] = a[i];
			for (j = i - dk; a[0] < a[j];j=j-dk ) {
				a[j + dk] = a[j];
			}
			a[j + dk] = a[0];
		}
	}
}
void print(int a[],int n)
{
	int i;
	for (i = 1; i < n ; i++) { printf("%d\t", a[i]); }
}
int main()
{
	int dlk[3] = { 5,3,1 };
	int a[17] = { 0,1,5,9,8,4,54,62,3,4,84,45,822,6,4,95,-1 };
	shall(a, 17, dlk, 3);
	print(a,17);
	system("pause");
	return 0;
}