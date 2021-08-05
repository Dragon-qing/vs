#include<iostream>
#include"seqlist.h"
typedef int Type;
using namespace std;
int main()
{
	Type a = 5, b = 15, c = 20, d = 10;
	seqlist L1;
	if (!L1.Full())
	{
		L1.InsertRear(5);
		L1.InsertRear(b);
		L1.InsertRear(c);
		L1.Insert(1, d);
	}
	if (!L1.Empty())
		L1.Erase(0);
	int n = L1.Size();
	for (int i = 0; i < n; i++)
		cout << L1.Getdata(i) << '\t';
	L1.Swap(0, 1);//½»»»
	L1.Replace(1, 1000);//Ìæ»»
	cout << "\n"<<"L1:";
	for (int i = 0; i < n; i++)
		cout << L1.Getdata(i) << '\t';
	seqlist L2;
	L2= L1;//²âÊÔ=ÖØÔØ
	cout << "\n" << "L2:";
	for (int i = 0; i < n; i++)
		cout << L2[i] << '\t';//[]ÖØÔØ
	L2.Clear();
	const seqlist L3(L1);
	cout << "\n"<<"L3:";
	for (int i = 0; i < L3.Size(); i++)
		cout << L3[i] << '\t';//const[]
	return 0;
}