#include<stdio.h>
#include<stdlib.h>
void sort(int a[], int start, int end);
void bucket(int a[], int n)
{
	int temp,h,l;
	int backet[10][10] = {}, i;
	for(i=0;i<n;i++)
	{
		temp = a[i]/10; 
			if (backet[temp][0] == NULL) { backet[temp][0] = a[i]; }
			else
			{
				int x = 1;
					while (backet[temp][x] != NULL) 
					{ 
						x++;
						if (backet[temp][x] == NULL) { backet[temp][x] = a[i]; }
				    }

			}
	}
	i = 0;
	int start;
	for (h = 0; h < 10; h++)
	{
		l = 0;
		start = i;
		while(backet[h][l] != NULL)
		 { 
			a[i++] = backet[h][l++];
		 }
		sort(a, start, i - 1);
	}
}
void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
void sort(int a[], int start, int end)
{
	int i = 0,j;
	while (i <= end - start)
	{
		for (j = start; j <end; j++)
		{
			if (a[j] > a[j + 1]) { swap(&a[j], &a[j + 1]); }
		}
		i++;
	}
}
int main()
{
	int a[10] = { 1,9,5,6,3,4,2,6,7,8 };
	bucket(a, 10);
	int i;
	for (i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}