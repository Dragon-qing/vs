#include<iostream>
#include<string>
using namespace std;
void transform(string& l)
{
	for (int i = 0; i <  l.length(); i++)
		l[i] = toupper(l[i]);
	cout << l<<endl;
}
int main()
{
	string l;
	cout << "Enter a string(\"q\"to quit):";
	getline(cin, l);
	if(l!="q")transform(l);
	while (l != "q")
	{
		cout << "Next string(\"q\"to quit):";
		getline(cin, l);
		if (l != "q")transform(l);
	}
	return 0;
}