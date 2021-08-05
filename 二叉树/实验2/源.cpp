#include"BTNode.h"
int main()
{
	BTNode<char>* nullp = NULL;
	BTNode<char>* f = GetBTNode('f');
	BTNode<char>* d = GetBTNode('d', f, nullp);
	BTNode<char>* b = GetBTNode('b', nullp, d);
	BTNode<char>* e = GetBTNode('e');
	BTNode<char>* c = GetBTNode('c', nullp, e);
	BTNode<char>* a = GetBTNode('a', b, c);
	Level(a);
	return 0;
}