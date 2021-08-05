#include<iostream>
using namespace std;
template<class T>
T* sort(T*a,int size)
{
	int i, j;
	for(i=0;i<size;i++)
		for(j=0;j<size-1;j++)
			if (a[j] > a[j + 1])
			{
				T temp;
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
	return a;
}
template<class T>
void Print(T* a,int size)
{
	for (int i = 0; i < size; i++)
		cout << a[i] << '\t';
		cout << endl;
}
int main()
{
	int Int[8] = { 25,12,6,-5,9,-22,6,13 };
	double Dou[7] = { 4.08,6.12,-0.35,6,12,-9,8.23 };
	sort(Int, 8);
	sort(Dou, 7);
	Print(Int,8);
	Print(Dou, 7);
	return 0;
}