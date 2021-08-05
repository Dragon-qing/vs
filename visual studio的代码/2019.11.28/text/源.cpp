#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* selection(char *str);
int main()
{
	char str[50] = "my dream is to be an";
	printf("%s\n", selection(str));
	system("pause");
	return 0;
}
char* selection(char *str)
{
	int j, i;
	int k;
	char *str1;
	int temp;
	str1 = (char*)malloc(sizeof(char)*strlen(str));
	for (i = 0; i < strlen(str) - 1; i++)
	{
		for (j = 0; j < strlen(str) - 1 - i; j++)
		{
			for (k = strlen(str) - 1; k >= 0; k--)
			{
				str1[j++] = str[k];
				if (str1[j + 1] < str1[j])
				{
					temp = str1[j + 1];
					str1[j + 1] = str1[j];
					str1[j] = temp;
				}
			}
		}
	}
	return str1;
}
//int main()
//{
//	system("pause");
//	return 0;
//}