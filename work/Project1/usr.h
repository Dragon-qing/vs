#include<iostream>
using namespace std;
class Person
{
private:

	static const int LIMIT = 25;

	string lname;// Person’s last name 

	char fname[LIMIT];// Person’s first name 

public:

	Person() { lname = ""; fname[0] = '\0'; } // #1 

	Person(const string& ln, const char* fn = "Heyyou");// #2

	// the following methods display lname and fname 

	void Show() const;// firstname lastname format 

	void FormalShow() const;// lastname, firstname format 

};

//请写出未定义的成员函数的实现代码。
//并实现一个测试程序，在程序中用以下代码段进行测试：
int main()
{
	Person one;               // use default constructor 

	Person two("Smythecraft");       // use #2 with one default argument 

	Person three("Dimwiddy", "Sam");    // use #2, no defaults 

	one.Show();

	cout << endl;

	one.FormalShow();
	two.Show();

	cout << endl;

	two.FormalShow();
	three.Show();

	cout << endl;

	three.FormalShow();
	return 0;
}
//还可以给出对对象two和three的测试。