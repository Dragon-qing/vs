#include"Tree.h"
#include<fstream>
using namespace std;
int main()
{
	Tree<char>T(20);
	ifstream fin;
	fin.open("Treein.txt", ios::in);
	if (!fin) { cout << "cannot open text!" << endl; exit(1); }
	fin >> T;
	ofstream fout;
	fout.open("Treeout.txt", ios::out);
	if (!fout)
	{
		cout << "cannot open treeout.txt\n";
		exit(1);
	}
	fout << T;

	return 0;
}