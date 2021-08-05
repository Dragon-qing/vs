#include <iostream>
#include "Vector.h"
using namespace std;

template<typename Iterator>	//��ָ����Χ�����Ԫ��
void display_vector(Iterator first, Iterator last)
{
	for (; first != last; ++first)
		cout << *first << ' ';
	cout << endl;
}

int main()
{

	//��1���ֲ���:constructor,Insert,Erase
	Vector<int> V;

	for (int i = 0; i < 10; i++)
	{
		V.Push_back(i);
	}
	cout << "The original numbers are:" << endl;
	display_vector(V.Begin(), V.End());

	Vector<int>::iterator itr = V.Begin();		   //ȡ��Ԫ��ָ��
	V.Erase(itr);								//ɾ����һ��Ԫ��
	cout << "after erasing the first:" << endl;
	display_vector(V.Begin(), V.End());

	itr += 3;
	V.Insert(itr, 999);
	cout << "after insert 999:" << endl;
	display_vector(V.Begin(), V.End());


	//��2���ֲ���:copyconstructor,operator=,Resize,operator[]
	Vector<int> V1(V);							//���ƹ���
	V1.Resize(15, 5);
	for (int i = 0; i < V1.Size(); i++)
		V1[i]++;
	cout << "The elements in Vector V1 are:" << endl;
	display_vector(V1.Begin(), V1.End());

	Vector<int> V2(V1);

	itr = V2.End();
	itr--;
	V2.Erase(itr);
	cout << "The elements in Vector V2 are:" << endl;
	display_vector(V2.Begin(), V2.End());

	return 0;
}
