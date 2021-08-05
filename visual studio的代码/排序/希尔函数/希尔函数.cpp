void shall(int a[], int n, int dlk[], int k)
{
	int i;
	for (i = 0; i < k; i++)
	{
		shallpx(a, n,dlk[i]);
	}
}
void shallpx(int a[], int n,int dk)
{
	int j, i;
	for (i = 1 + dk; i < n, i++)
	{
		if (a[i] < a[i - 1])
		{
			a[0] = a[i];
			for (j = i - dk; a[0] < a[j];j= j+dk)
			{
				a[j + dk] = a[j];
			}
			a[j + dk] = a[0];
		}
	}
}