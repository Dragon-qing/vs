#pragma once
#include<iostream>
#include<list>
#include<queue>
using namespace std;
template<class T>
class Tree
{
	T* NA;
	list<int>* HL;
	int root;
	int sizeN, sizeC;
	int maxN;
public:
	Tree(int n = 100) :root(-1), sizeN(0), sizeC(0), maxN(n)
	{
		NA = new T[n];
		HL = new list<int>[n];
	}
	~Tree() { delete[]NA; delete[]HL; }
	int Empty()const { return sizeN == 0; }
	int Full()const { return sizeN == maxN; }
	int SizeN()const { return sizeN; }
	int SizeC()const { return sizeC; }
	int FindNode(const T& node)const;
	bool FindNode(T& v, int pos)const;
	bool InsertN(const T& node);
	bool InsertC(const T& parent, const T& child);
	void ReadTree(const char* filename,Tree<T>&t);
	void WriteTree(const char* filename,const Tree<T>&t);
	template<class T>
	friend ostream& operator<<(ostream& ostr, const Tree<T>& t);
	template<class T>
	friend istream& operator>>(istream& istr, Tree<T>& t);
	void BFS(list<T> &L);
	void DFS(list<T> &L,int t);
};
template<class T>
int Tree<T>::FindNode(const T& node)const
{
	for (int i = 0; i < sizeN; ++i) {
		if (NA[i] == node)
			return i;
	}
	return -1;
}
template<class T>
bool Tree<T>::FindNode(T& node, int pos)const
{
	if (pos < 0 || pos >= sizeN)
		return 0;
	node = NA[pos];
	return 1;
}
template<class T>
bool Tree <T>::InsertN(const T& node)
{
	if (sizeN == maxN)
		return 0;
	NA[sizeN] = node;
	sizeN++;
	return 1;
}
template<class T>
bool Tree<T>::InsertC(const T& parent, const T& child)
{
	int pi = FindNode(parent), cj = FindNode(child);
	if (pi == -1 || cj == -1 || pi == cj)
		return 0;
	HL[pi].insert(HL[pi].end(), cj);
	sizeC++;
	return 1;
}
template<class T>
istream& operator>>(istream& istr, Tree<T>& t)
{
	char str[50];
	int n;
	T parent, child;
	istr >> str >> n;
	istr >> str >> parent;
	t.InsertN(parent);
	t.root = t.sizeN - 1;
	istr >> str;
	for (int i = 1; i <= n-1; ++i)
	{
		istr >> child;
		t.InsertN(child);
	}
	istr >> str >> n;
	for (int i = 1; i <= n; ++i)
	{
		istr >> parent >> child;
		t.InsertC(parent, child);
	}
	return istr;
}
template<class T>
ostream& operator<<(ostream& ostr, const Tree<T>& t)
{
	for (int i = 0; i < t.sizeN; ++i)
	{
		ostr << i << '-' << t.NA[i] << ':';
		typename list<int>::iterator first = t.HL[i].begin(), last = t.HL[i].end();
		for (; first != last; ++first)
			ostr << '(' << *first << ')' << ' ';
		ostr << endl;
	}
	return ostr;

}
template<class T>
void Tree<T>::BFS(list<T>& L)
{
	if (sizeN == 0)
		return;
	queue<int>Q;
	Q.push(root);
	list<int>::const_iterator first, last;
	while (!Q.empty())
	{
		int pos = Q.pop();
		L.push_back(NA[pos]);
		first = HL[pos].begin();
		last = HL[pos].end();
		for (; first != last; ++first)
		{
			Q.push(*first);
		}
	}

}
template<class T>
void Tree<T>::DFS(list<T>& L, int t)
{
	if (t < 0 || t >= sizeN)
		return;
	L.push_back(NA[t]);
	list<int>::iterator first, last;
	first = HL[t].begin(); last = HL[t].end();
	for (; first != last; ++first)
		DFS(L, *first);
}
template<class T>
void Tree<T>::ReadTree(const char* filename, Tree<T>& t)
{
	ifstream fin;
	fin.open(filename, ios::in | ios::_Nocreate);
	if (!fin)
	{
		cout << "cann't open the file" << endl;
		exit(1);
	}
	fin >> t;
}
template<class T>
void Tree<T>::WriteTree(const char* filename, const Tree<T>& t)
{
	ofstream fout;
	fout.open(filename, ios::out);
	if (!fout)
	{
		cout << "cann't open the file" << endl;
		exit(1);
	}
	fout << t;
}