//���� n�� > 0����ѧ����������ѧ�š��ɼ����ֱ�����ɼ���ߺͳɼ����ѧ����������ѧ�š�
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