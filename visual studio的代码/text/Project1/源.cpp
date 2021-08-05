#include<iostream>
using namespace std;
bool Leapyear(int y)
{
	if (y % 100 == 0)
	{
		if (y / 400 == 0) { return true; }
		else { return false; }
	}
	else
	{
		if (y / 4 == 0)return true;
		else { return false; }
	}
}

int main()
{
	int x = 401;
	bool i;
	i=Leapyear(x);
	return 0;
}