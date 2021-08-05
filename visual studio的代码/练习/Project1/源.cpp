#include <iostream>
#include <string>
using namespace std;
class CBug {
    int legNum, color;
public:
    CBug(int ln, int c1) : legNum(ln), color(c1)
    {
        cout << "CBug Constructor" << endl;
    };
    ~CBug()
    {
        cout << "CBug Destructor" << endl;
    }
    void Printlnfo()
    {
        cout << legNum << "," << color << endl;
    }
};
class CFlyingBug : public CBug
{
    int wingNum;
public:
    //CFlyingBug(){}  Èô²»×¢ÊÍµôÔò»á±àÒë³ö´í
    CFlyingBug(int ln, int c1, int wn) : CBug(ln, c1), wingNum(wn)
    {
        cout << "CFlyingBug Constructor" << endl;
    }
    ~CFlyingBug()
    {
        cout << "CFlyingBug Destructor" << endl;
    }
};
int main() {
    CFlyingBug fb(2, 3, 4);
    fb.Printlnfo();
    return 0;
}