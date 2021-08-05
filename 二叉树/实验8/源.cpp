#include"BTNode.h"
int main()
{
	vector<char>sL, pL;
	sL.push_back('a');
	sL.push_back('b');
	sL.push_back('c');
	vector<vector<char>>outl;
	Power(outl, sL, pL,0);
	Display(outl);
	return 0;
}
