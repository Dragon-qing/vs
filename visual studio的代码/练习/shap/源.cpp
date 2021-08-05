#include<iostream>
using namespace std;
class shape {
public:
	double len, high, rad;
	shape(int x=0,int y=0,int z=0):len(x),high(y),rad(z){}
};
class Rectangle :public shape
{
public:
	double area() { return len * high; }
	void Display() { cout << "Rectangle area is " << area()<<endl; }
	Rectangle(int l, int h):shape(l,h){}
};
class Circle :public shape
{
public:
	double area() { return 3.14 * rad*rad; }
	void Display() { cout << "Circle area is " << area() << endl; }
	Circle(int r) :shape(0,0,r) {}
};
class Triangle :public shape
{
public:
	double area() { return len*high/2; }
	void Display() { cout << "Triangle area is " << area() << endl; }
	Triangle(int l,int h) :shape(l,h) {}
};
class Square :public Rectangle
{
public:
	double area() { return len * high; }
	void Display() { cout << "Square area is " << area() << endl; }
	Square(int l) :Rectangle(l,l) {}
};
int main()
{
	Rectangle a(5, 10);
	Circle b(10);
	Triangle c(1, 2);
	Square d(9);
	a.Display();
	b.Display();
	c.Display();
	d.Display();
	return 0;
}