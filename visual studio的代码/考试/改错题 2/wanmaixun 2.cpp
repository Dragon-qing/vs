#include <iostream>
using namespace std;
class A {
public:
	A(int a = 0, int b = 0) : x(a), y(b) { }
	friend A operator + (const A& x1, const A& x2);  // ������ݳ����޸����д���
	friend ostream& operator << (ostream& out, const A& c);  // ������ݳ����޸����д���
private:
	int x, y;
};

A operator + (const A& x1, const A& x2) {
	return A(x1.x + x2.x, x1.y + x2.y);
}

ostream& operator << (ostream& out, const A& c) { // ������ݳ����޸����д���
	out << "(" << c.x << ", " << c.y << ")";
	return out;   // ������ݳ����޸����д���
}

int main() {
	A x1(5, 4), x2(2, 10), x3;
	x3 = x1 + x2;
	cout << "x3 = x1 + x2 = " << x3 << endl;
	return 0;
}
