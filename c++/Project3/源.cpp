#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
void Display(const int* p, int n);
void Queue();
int main()
{
	Queue();
	return 0;
}
void Queue()
{
	int  A[22], B[22], C[22], Y[22];
	int x = 0, y = 0;
	for (; y < 9;)
	{
		for (; x < 8; x++){
			if (!A[x + 7] && !B[x + y + 7] && !C[x - y + 7])
			{
				Y[y] = x;
				A[x + 7] = B[x + y + 7] = C[x - y + 7] = 1;
				break;
			}
		}
		if (Y[y] < 8) {
			y++;
			x = 0;
		}
		else {
			y--;
			A[x + 7] = B[x + y + 7] = C[x - y + 7] = 0;
			x = Y[y];
		}
		if (y == 8) {
			Display(Y, 8);
			y--;
		}
	}
}
void Display(const int* p, int n)
{
	static int totall = 1;
	for (int y = 0; y < n; y++) {
		if (y % 8 == 0) {
			cout << totall++ << endl;
		}
		for (int x = 0; x < 8; x++) {
			if (x != p[y]) {
				cout << " # ";
			}
			else
			{
				cout << " @ ";
			}
		}
		cout << endl;
	}
	cout << "please entor any key to see" << endl;
	getchar();
}
//#include<stdio.h>
//#include<iostream>
//#include<math.h>
//using namespace std;
//int x[100];
//void Display(const int* p, int n);
//bool place(int k)//����ʺ�k������x[k]���Ƿ�����ͻ
//{
//	int i;
//	for (i = 1; i < k; i++)
//		if (x[k] == x[i] || abs(k - i) == abs(x[k] - x[i]))
//			return false;
//	return true;
//}
//
//
//void queue(int n)
//{
//	int i, k;
//	for (i = 1; i <= n; i++)
//		x[i] = 0;
//	k = 1;
//	while (k >= 1)
//	{
//		x[k] = x[k] + 1;   //����һ�з��õ�k���ʺ�
//		while (x[k] <= n && !place(k))
//			x[k] = x[k] + 1;//������һ��
//		if (x[k] <= n && k == n)//�õ�һ�����
//		{
//			for (i = 1; i <= n; i++)
//				printf("%d ", x[i]);
//			printf("\n");
//			//return;//��return��ֻ�������һ�ֽ⣬����return����Լ������ݣ����ȫ���Ŀ��ܵĽ�
//		}
//		else if (x[k] <= n && k < n)
//			k = k + 1;//������һ���ʺ�
//		else
//		{
//			x[k] = 0;//����x[k],����
//			k = k - 1;
//		}
//	}
//}
//void Display(const int* p, int n)
//{
//	static int totall = 1;
//	for (int y = 0; y < n; y++) {
//		if (y % 8 == 0) {
//			cout << totall++ << endl;
//		}
//		for (int x = 0; x < 8; x++) {
//			if (x != p[y]) {
//				cout << " # ";
//			}
//			else
//			{
//				cout << " @ ";
//			}
//		}
//		cout << endl;
//	}
//	cout << "please entor any key to see" << endl;
//	getchar();
//}
//
//void main()
//{
//	int n;
//	printf("����ʺ����n:\n");
//	scanf_s("%d", &n);
//	queue(n);
//}


