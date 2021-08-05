#include"Vector.h"
#include<iostream>
template<class Iterator>	
void Display(Iterator first, Iterator last)
{
	for (; first != last; ++first)
		cout << *first << '\t';
}
int main()  
{
	int i;
	Vector<int> V;
	Vector<int>::iterator itr = V.begin();
	cout << "enter 10 integers(Ctrl+z to end):\n";
	while (cin >> i)
	{
		itr=V.Insert(itr, i);
		++itr;
	}
	cin >> V[0];
	V.Erase(V.begin());		
	Display(V.begin(), V.end());
	return 0;
}