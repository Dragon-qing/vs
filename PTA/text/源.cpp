#include<iostream>
using namespace std;
int main()
{
	double a1, a2, b1, b2, w;
	double u, v;
	cin >> a1 >> a2 >> b1 >> b2 >> w;
	u =  w-(b1 + b2) / 2 ;
	v = w - (a1 + a2) / 2 ;
	cout << (u * v) / (u + v);
	return 0;
}