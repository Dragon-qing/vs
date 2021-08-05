#include"vector.h"
#include<iostream>
template<class Iterator>	//在指定范围内，输出元素
void Display(Iterator first, Iterator last)
{
	for (; first != last; ++first)
		cout << *first << '\t';
}
int main()  //程序10.3
{
	int i;
	Vector<int> V;
	Vector<int>::iterator itr = V.begin();
	cout << "enter 10 integers(Ctrl+z to end):\n";
	while (cin >> i)
	{
		V.Insert(itr, i);
		++itr;
	}
	V.Erase(V.begin());		//删除首元素
	Display(V.begin(), V.end());
	return 0;
}