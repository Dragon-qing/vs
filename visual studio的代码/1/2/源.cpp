#include<iostream>
using namespace std;
struct Candybar {
	char name[20];
	double wight;
	int calorie;
};
using candybar = struct Candybar;
void print1(candybar & l, const char* s="Millennium Munch", const double wight= 2.85, const int calorie= 350)
{
	cout << "showCandybar with 3 parameters\n";
	cout << "Name:" << s << "   " << "Weight:" << wight << "   " << "Calorie:" << calorie << endl;
}
void print2(candybar& l)
{
	cout << "showCandybar with 1 parameters\n";
	cout << "Name:" << l.name << "   " << "Weight:" << l.wight << "   " << "Calorie:" << l.calorie << endl;
}
int main()
{
	candybar l;
	cout << "please input candybar's name:";
	cin >> l.name;
	cout << "please input candybar's weight:";
	cin >> l.wight;
	cout << "please input candybar's calorie:";
	cin >> l.calorie;
	print2(l);
	print1(l, l.name, l.wight, l.calorie);
	return 0;
}