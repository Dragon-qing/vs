#include"BTNode.h"
#include"HufmLib.h"
int main()
{
	int a[] = { 7,5,2,4 };
	BTNode<int>* root;
	root = MakeHufm(a, 4);
	PrintBTree(root, 40);
	cout << endl;
	return 0;
}