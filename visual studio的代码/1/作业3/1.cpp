#include<iostream>
#include<string>
using namespace std;
double mass(double density, double volume) { return density * volume; }
double mass(double density, int volume = 1) { return density * volume; }
void repeat(string s, int x = 5) { while (x--)cout << s<<endl; }
int average(int x, int y){return (x + y) / 2;}
double average(double x, double y) { return (x + y) / 2; }
void iquote(int x) { cout << "\"int x\"=" << x << endl; }
void iquote(double y) { cout << "\"double y\"=" << y << endl; }
void iquote(string s) { cout << "\"string s\"=" << s << endl; }
int main()
{
	iquote(1);
	iquote(4.0);
	iquote("hello");
	return 0;
}