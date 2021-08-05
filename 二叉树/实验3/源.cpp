#include"BTNode.h"
int main()
{
	vector<char>v = { 'A','B','C',0,'D',0,'E',0,0,'F' };
	BTNode<char>* b;
	b=MakeLinked(v);
	Level(b);
	MakeLinked2(&b,0,v );
	cout << endl;
	Level(b);
	return 0;
}