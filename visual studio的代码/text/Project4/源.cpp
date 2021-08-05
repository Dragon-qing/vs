#include<iostream>
using namespace std;
namespace n1 { int x = 1; }
namespace n2 { int x = 10; }
namespace { int y = 400; }
class point
{
	int x, y;
	static int count;
public:
	static int getcount() { return count; }
	point(int a, int b) :x(a), y(b) { count++; }
	int getx() { return x; }
};
int point::count = 0;
int main()
{
	using namespace n1;
	cout << x << endl;
	{
	int x = 100; 
	x += 1;
	cout << x << "," << n1::x<<"," << n2::x << endl;
	}
	//using  n1::x;
	cout << x << endl; 
	cout << n2::x << endl;
	cout << ::y << endl;
	return 0;
}