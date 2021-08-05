void heap(int a[],int n)
{
	int i;
	for (i = n / 2; i >= 1; i--)
	{
		heapadjust(a, i, n);
	}
	for (i = n; i > 1; i--)
	{
		heapadjust(a, 1, i-1);
	}
}