#include"BTNode.h"
int main()
{
	vector<char>v = { 'A','B','C',0,'D',0,'E',0,0,'F' };
	BTNode<char>* b;
	b = MakeLinked(v);
	Preorder(b);
	cout << endl;
	SimPreorder(b);
	cout << endl;
	Inorder(b);
	cout << endl;
	SimInoder(b);
	cout << endl;
	Postorder(b);
	cout << endl;
	SimPostorder(b);
	cout << endl;
	return 0;
}