
#pragma once
#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
template<class T>
struct BTNode
{
	T data;
	BTNode* left, * right;
	BTNode(const T& item = T(), BTNode* lptr = NULL, BTNode* rptr = NULL) :data(item), left(lptr), right(rptr) {}
};
template<class T>
BTNode<T>* GetBTNode(const T& item, BTNode<T>* lp = NULL, BTNode<T>* rp = NULL)
{
	BTNode<T>* p;
	p = new BTNode<T>(item, lp, rp);
	if (p == NULL) {
		cout << "Memory allocation failure!" << endl;
		exit(1);
	}
	return p;
}
template<class T>
void Level(BTNode<T>* t)
{
	if (t == NULL)
	{
		cout << "the tree is empty!" << endl;
		exit(1);
	}
	queue<BTNode<T>*>Q;
	Q.push(t);
	while (!Q.empty()) {
		t = Q.front();
		Q.pop();
		cout << t->data;
		if (t->left)
			Q.push(t->left);
		if (t->right)
			Q.push(t->right);
	}
}
template<class T>
BTNode<T>* MakeLinked(const vector<T>& L)//顺序存储转链式存储
{
	if (L.size() == 0) {
		return 0;
	}
	queue<BTNode<T>*>Q;
	BTNode<T>* t = GetBTNode(L[0]);
	BTNode<T>* parent, * child;
	Q.push(t);
	int i = 0, n = L.size();
	while (!Q.empty()) {
		parent = Q.front();
		Q.pop();
		if (2 * i + 1 < n && L[2 * i + 1] != T()) {
			child = GetBTNode(L[2 * i + 1]);
			parent->left = child;
			Q.push(child);
		}
		if (2 * i + 2 < n && L[2 * i + 2] != T()) {
			child = GetBTNode(L[2 * i + 2]);
			parent->right = child;
			Q.push(child);
		}
		i++;
		while (i < n && L[i] == T()) {
			++i;
		}
	}
	return t;
}//非递归转换
template<class T>
void MakeLinked2(BTNode<T>** p, int i, vector<T>v)
{
	if (i >= (int)v.size() || v[i] == T())
		*p = NULL;
	else {
		*p = GetBTNode(v[i]);
		MakeLinked2(&(*p)->left, 2 * i + 1, v);
		MakeLinked2(&(*p)->right, 2 * i + 2, v);
	}

}//递归转换
struct Location
{
	int xindent, ylevel;
};
void Gotoxy(int x, int y)
{
	static int level = 0, indent = 0;
	if (y == 0)
	{
		indent = 0;
		level = 0;
	}
	if (level != y) {
		cout << endl;
		indent = 0;
		level++;
	}
	cout.width(x - indent);
	indent = x;
}
template<class T>
void PrintBTree(const BTNode<T>* t, int screenwidth)//垂直输出
{
	if (t == NULL)
	{
		return;
	}
	int level = 0, offset = screenwidth;
	Location fLoc, cLoc;
	queue<const BTNode<T>*>Q;
	queue<Location>LQ;
	fLoc.xindent = offset;
	fLoc.ylevel = level;
	Q.push(t);
	LQ.push(fLoc);
	while (!Q.empty())
	{
		t = Q.front();
		Q.pop();
		fLoc = LQ.front();
		LQ.pop();
		Gotoxy(fLoc.xindent, fLoc.ylevel);
		cout << t->data;
		if (fLoc.ylevel != level) {
			level++;
			offset /= 2;
		}
		if (t->left) {
			Q.push(t->left);
			cLoc.ylevel = fLoc.ylevel + 1;
			cLoc.xindent = fLoc.xindent - offset / 2;
			LQ.push(cLoc);
		}
		if (t->right) {
			Q.push(t->right);
			cLoc.ylevel = fLoc.ylevel + 1;
			cLoc.xindent = fLoc.xindent + offset / 2;
			LQ.push(cLoc);
		}
	}
	cout << endl;
}
template <class T>
void Preorder(const BTNode<T>* t)
{
	if (t == NULL)return;
	cout << t->data;
	if (t->left)
		Preorder(t->left);
	if (t->right)
		Preorder(t->right);
}//前序遍历递归算法
template <class T>
void SimPreorder(const BTNode<T>* t)
{
	if (!t)
		return;
	stack<const BTNode<T>*>S;
	while (t || !S.empty()) {
		if (t) {
			cout << t->data;
			if (t->right)
				S.push(t->right);
			t = t->left;
		}
		else {
			t =S.top();
			S.pop();
		}
	}
}//前序遍历非递归算法
template<class T>
void Inorder(const BTNode<T>* t)
{
	if (!t)
		return;
	if (t->left)
		Inorder(t->left);
	cout << t->data;
	if (t->right)
		Inorder(t->right);
}//中序遍历递归算法
template<class T>
void SimInoder(const BTNode<T>* t)
{
	if (!t)
		return;
	stack<const BTNode<T>*>S;
	while (t || !S.empty())
		if (t) {
			S.push(t);
			t = t->left;
		}
		else {
			t = S.top();
			S.pop();
			cout << t->data;
			t = t->right;
		}
}//中序遍历非递归算法
template<class T>
void Postorder(const BTNode<T>* t)
{
	if (!t)
		return;
	if (t->left)
		Postorder(t->left);
	if (t->right)
		Postorder(t->right);
	cout << t->data;
}//后序遍历递归算法
template<class T>
void SimPostorder(const BTNode<T>* t)
{
	if (!t)
		return;
	int tag;
	stack<const BTNode<T>*>s;
	stack<int>tags;
	const BTNode<T>* temp;
	while (t || !s.empty())
	{
		if (t) {
			s.push(t);
			tags.push(1);
			t = t->left;
		}
		else {
			temp = s.top();
			s.pop();
			tag = tags.top();
			tags.pop();
			if (tag == 1) {
				s.push(temp);
				tags.push(2);
				t = temp->right;
			}
			else
				cout << temp->data;
		}
	}
}//后序遍历非递归算法