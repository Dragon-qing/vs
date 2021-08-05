#include <iostream> 
using namespace std;
class Complex
{
private:
    double r, i;
public:
    Complex(int x = 0, int y = 0) :r(x), i(y) {}
    Complex& operator=( Complex& a);
    Complex operator+(Complex& b);
    Complex operator-(Complex& c);
    friend ostream& operator<<(ostream& out, const Complex& a);
    void Print()
    {
        cout << r << "+" << i << "i" << endl;
    }
};
ostream& operator<<(ostream& out, const Complex& a)
{
    out<< a.r << "+" << a.i << "i" << endl;
    return out;
}
Complex& Complex::operator=(const Complex& a)
{
    r = a.r;
    i = a.i;
    return *this;
}
Complex Complex::operator+(Complex& b)
{
    return Complex(r + b.r, i + b.i);
}
Complex Complex::operator-(Complex& c)
{
    return Complex(r - c.r, i - c.i);
}
int main()
{
    Complex a(10, 9), b(5, 3), sum, dif;
    sum = a + b;
    cout << "Sum of a and b is: " << sum << endl;
    dif = a - b;
    cout << "Difference of a and b is: " << dif << endl;

    return 0;
}