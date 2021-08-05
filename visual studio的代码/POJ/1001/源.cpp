#include<stdio.h>
#include<string.h>
int output[120];
int m;
void cal(int sum);
int main()
{
	char str[6];
	int n;
	while (scanf("%s%d", str, &n) != EOF)
	{
		int length = strlen(str);
		int i;
		int point = 0;
		int sum=0;
		int temp;
		for (i = 0; i < length; i++)
		{
			if (str[i] == '.')
			{
				point = (length - i-1)*n;
			}
			else
			{
				sum = str[i] - '0' + sum * 10;
			}
		}
		memset(output, 0, sizeof(output));
		output[0] = 1;
		m = 1;
		for (i = 0; i < n; i++)
			cal(sum);
		temp = 0;
		for (i = 0; i < m; i++)
		{
			if (output[i] != 0)
			{
				temp = i;
				break;
			}
		}
		if(temp-point>0)
		{
			for (i = m - 1; i >= point; i--)
			{
				printf("%d", output[i]);
			}
		}
		else
		{
			if (point > m)m = point;
			for (i = m - 1; i >= point;i--)
				printf("%d", output[i]);
			printf(".");
			for (; i >= temp; i--)
				printf("%d", output[i]);
		}
		printf("\n");
	}
	return 0;
}
void cal(int sum)
{
	int i;
	int p;
	int t;
	for (i = 0; i < m; i++)
	{
		output[i] = output[i] * sum;
	}
	for (i = 0; i < m - 1; i++)
	{
		if (output[i] >= 10) 
		{
			output[i + 1] = output[i + 1]+output[i]/10;
			output[i] %= 10;
		}
	}
		 p = m - 1;
		 t = output[m - 1];
	if (t >= 10)
	{
		while (t > 0)
		{
			output[p++]= t %10;
			t /= 10;
		}
	}
	m = p;
}