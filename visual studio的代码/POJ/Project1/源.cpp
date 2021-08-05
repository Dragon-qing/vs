int pow(int a, int n)
{
	int sum=1;
	int i;
	while (n)
	{
		if (n % 2 == 1)
		{
			sum *= a;
		}
		a *= a;
		n /= 2;
	}
	return sum;
}
1 2
4 1
2 5
5 4
3 3