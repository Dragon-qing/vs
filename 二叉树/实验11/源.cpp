#include"BTNode.h"
int main()
{
	vector<char>v = { 'A','B','C',0,'D',0,'E',0,0,'F' };
	BTNode<char>* b,*x;
	b = MakeLinked(v);
	x = CopyTree(b);
	Preorder(x);
	return 0;
}