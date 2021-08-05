#include"BTNode.h"
int main()
{
	const char* pl = "ABDHIEJCFKGM";
	const char* il = "HDIBJEAFKCGM";
	BTNode<char>* root = MakeLinked3(pl, il, 12);
	PrintBTree(root, 40);
	return 0;
}