#include"Vector.h"
#include<iostream>
using namespace std;
template<class T>
 void display(Vector<T> V)
{
	 typename Vector<T>::iterator p = V.Begin();
	for (p; p < V.End(); p++)
		cout << *p << "  ";
}
int main()
{
	Vector<int> V1;
	Vector<int> V2;
	for (int i = 0; i < 10; i++)
		V1.Push_back(i);
	for (int i = 1; i < 20; i += 2)
		V2.Push_back(i);
	cout << "original V1:";
	display(V1);
	cout << endl;
	cout << "original V2:";
	display(V2);
	cout << endl;
	V1.Swap(V2);
	cout << "after swap,V1:";
	display(V1);
	cout << endl;
	cout << "V2:";
	display(V2);
	cout << endl;
	V1.Insert(V1.Begin() + 3, V2.Begin(), V2.End()-1);
	cout << "after insert V2 into V1,V1:";
	display(V1);
	cout << endl;
	V1.Erase(V1.Begin(), V1.Begin() +4);
	cout << "after erase 5 elements V1:";
	display(V1);
	cout << endl;
	for (int i = 0; i < 5; i++)
		V1.Insert(V1.Begin() + 5, 999);
	cout << "after insert 5 999 V1:";
	display(V1);
	cout << endl;
	return 0;
}