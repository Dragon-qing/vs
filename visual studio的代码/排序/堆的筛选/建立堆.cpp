void heap(int a[], int n)
{
	int i;
	for(i=n/2;i>=1;i--)
	{
		heapadjust(a, i, n);
	}
}