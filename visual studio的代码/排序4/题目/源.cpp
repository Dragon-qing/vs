//读入 n（ > 0）名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。
#include<stdio.h>
#include<stdlib.h>
struct data {
	char name[10];
	char number[10];
	int mark;
};
typedef struct data data;
void f()
{
	data*p = (data*)malloc(sizeof(data));

}
int main()
{
	int n;
	scanf_s("%d", &n);

	system("pause");
	return 0;
}