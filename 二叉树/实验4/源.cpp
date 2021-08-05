#include"BTNode.h"
int main()
{
	vector<char>v = { 'A','B','C',0,'D',0,'E',0,0,'F' };
	BTNode<char>* b;
	b = MakeLinked(v);
	PrintBTree(b, 40);
	return 0;
}