#include"List.h"
#include<iostream>
using namespace std;
template<class Iterator>
void Swap(Iterator it1, Iterator it2)	//½»»»µü´úÆ÷it1ºÍit2Î»ÖÃµÄÔªËØ
{
	_Swap(it1, it2, *it1);
}
template <typename Iterator, typename T>
void Replace(Iterator first, Iterator last, const T& old_val, const T& new_val)
{
	for (first; first != last; ++first)
		if (*first == old_val)*first = new_val;
}
template<class Iterator, class T>
void _Swap(Iterator it1, Iterator it2, T)//Èý½Çµ÷»»£¬¹©Swapµ÷ÓÃ
{
	T tmp(*it1);
	*it1 = *it2;
	*it2 = tmp;
}
template<class Iterator>
void Sort_by_selection(Iterator first, Iterator last)//Ñ¡ÔñÅÅÐò
{
	Iterator i, j, min;
	for (i = first; i != last; ++i)			//±éÀúÑ°ÕÒ×îÐ¡ÖµÔªËØ
	{
		min = i;
		for (j = i, ++j; j != last; ++j)
			if ((*j) < (*min))
				min = j;			//µü´úÆ÷minÖ¸Ïòµ±Ç°×îÐ¡ÔªËØ
		if (min != i)
			Swap(i, min);
	}
}
template<class Iterator>				//Êä³ö¹æ¶¨·¶Î§µÄÔªËØ
void Display(Iterator first, Iterator last)
{
	for (; first != last; ++first)
		cout << *first << '\t';
}
template <typename Iterator, typename T>
T Accumulate(Iterator first, Iterator last, T val)
{
	for (; first != last; ++first)
	{
		val += *first;
	}
	return val;
}
template <typename Iterator, typename T>
Iterator Find(Iterator first, Iterator last, const T& val)
{
	for (; first != last; ++first)
	{
		if (*first == val)return first;
	}
	if (first == last) { cout << "未找到！" << endl; exit(1); };
}
int main()  //³ÌÐò11.1
{
	int i;
	List<int> V;
	cout << "enter 10 integers(Ctrl+z to end):\n";
	while (cin >> i)
		V.Push_back(i);
	V.Pop_back();
	Sort_by_selection(V.begin(), V.End());
	Replace(V.begin(), V.End(), 1, 100);
	cout<<Accumulate(V.begin(), V.End(), 10000)<<endl;
	Display(V.begin(), V.End());
	Find(V.begin(), V.End(), 50);
	return 0;
}