#include<iostream>
#include"seqlist.h"
using namespace std;
seqlist::seqlist(int Max)
{
	data = new Type[Max];
	if (data == NULL) { cout << "error!"; exit(1); }
	size = 0;
	max = Max;
}
seqlist::seqlist() :seqlist(10) {};//委托构造
seqlist::~seqlist()
{
	delete []data;
	cout << "\n已删除顺序表\n";
}
void seqlist::InsertRear(const Type& item)
{
	if (size == max) { cout << "InsertRear: list is full！\n"; exit(1); }
	data[size] = item;
	size++;
}
void seqlist::Insert(int id, const Type& item)
{
	int i;
	if (id<0 || id>size ||size == max)
	{
		cout<<"Insert: id is illegal or list is full！\n";  
		exit(1);        						        
	}
	for (i = size - 1; i >= id; i--)
		data[i + 1] = data[i];
		data[id] = item;
		size++;
}
void seqlist::Erase(int id)
{
	if (id<0 || id>size - 1)
	{
		cout << "Erase: id is illegal or list is empty！\n"; exit(1);
	}
	for (int i = id + 1; i < size; i++)
		data[i - 1] = data[i];
	/*cout << "删除成功！\n";*/
	size--;
}
void seqlist::Clear()
{
	size = 0;
}
Type seqlist::Getdata(int id)const
{
	if (id<0 || id>size-1)    		
	{
		cout<<"Getdata: id is illegal or list is empty！\n"; 
		exit(1);        						
	}
	return data[id];
}
int seqlist::Size()const
{
	return size;
}
int seqlist::Empty()const
{
	return size == 0;
}
int seqlist::Full()const
{
	return size == max;
}
seqlist::seqlist(const seqlist& x)
{
	size = x.size;
	max = x.max;
	data = new Type[x.max];
	if (data == NULL)
	{
		exit(1);
	}
	if (max < x.size) { cout << "error!\n"; exit(1); }
	for (int i = 0; i < x.size; i++)data[i] = x.data[i];
}
void seqlist::Swap(int id1, int id2)
{
	Type temp;
	temp = data[id1];
	data[id1] = data[id2];
	data[id2] = temp;
}
seqlist& seqlist:: operator=(const seqlist& l)
{
	size = l.size;
	max = l.max;
	data = new Type[l.max];
	if (data == NULL)
	{
		exit(1);
	}
	if (max < l.size) { cout << "error!\n"; exit(1); }
	for (int i = 0; i < l.size; i++)data[i] = l.data[i];
	return*this;
}
const Type& seqlist::operator[](int i)const
{
	if (i > size)
	{
		cout << "索引超过最大值" << endl;
		// 返回第一个元素
		return data[0];
	}
	return data[i];
}
void seqlist::Replace(int id1, const Type& item)
{
	data[id1] = item;
}

