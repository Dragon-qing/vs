#include <iostream>
using namespace std;
class A {
public:
	A(int a = 0, int b = 0) : x(a), y(b) { }
	friend A operator + (const A& x1, const A& x2);  // ①请根据程序修改其中错误
	friend ostream& operator << (ostream& out, const A& c);  // ②请根据程序修改其中错误
private:
	int x, y;
};

A operator + (const A& x1, const A& x2) {
	return A(x1.x + x2.x, x1.y + x2.y);
}

ostream& operator << (ostream& out, const A& c) { // ③请根据程序修改其中错误
	out << "(" << c.x << ", " << c.y << ")";
	return out;   // ④请根据程序修改其中错误
}

int main() {
	A x1(5, 4), x2(2, 10), x3;
	x3 = x1 + x2;
	cout << "x3 = x1 + x2 = " << x3 << endl;
	return 0;
}
