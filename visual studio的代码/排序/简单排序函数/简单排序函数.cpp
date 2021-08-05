void sclectsort(int a[], int lenth)
{
	int i, j, x,min;
	for (i = 0; i < lenth; i++)
	{
		min = i;
		for (j = i + 1; j < lenth; j++)
		{
			if (a[j] < a[min]) { min = j; }
		}
		if (min != i) { x = a[i]; a[i] = a[min]; a[min] = x; }
	}
}