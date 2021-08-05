#include <iostream>
#include "Vector.h"
using namespace std;

template<typename Iterator>	//在指定范围内输出元素
void display_vector(Iterator first, Iterator last)
{
	for (; first != last; ++first)
		cout << *first << ' ';
	cout << endl;
}

int main()
{

	//第1部分测试:constructor,Insert,Erase
	Vector<int> V;

	for (int i = 0; i < 10; i++)
	{
		V.Push_back(i);
	}
	cout << "The original numbers are:" << endl;
	display_vector(V.Begin(), V.End());

	Vector<int>::iterator itr = V.Begin();		   //取首元素指针
	V.Erase(itr);								//删除第一个元素
	cout << "after erasing the first:" << endl;
	display_vector(V.Begin(), V.End());

	itr += 3;
	V.Insert(itr, 999);
	cout << "after insert 999:" << endl;
	display_vector(V.Begin(), V.End());


	//第2部分测试:copyconstructor,operator=,Resize,operator[]
	Vector<int> V1(V);							//复制构造
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
