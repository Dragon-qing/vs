#include"BTNode.h"
int main()
{
	vector<char>v = { 'A','B','C',0,'D',0,'E',0,0,'F' };
	BTNode<char>* b;
	b=CreatBTree(v,0);
	Level(b);
	cout << endl;
	PrintBTree(b, 40);
	return 0;
}