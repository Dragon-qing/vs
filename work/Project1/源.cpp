#include<iostream>
using namespace std;
class Student
{
	int id;
	string name;
	int age;
public:
	Student(int i = 0, string n = " ", int a = 0):id(i),name(n),age(a){}
	~Student(){}
	Student(Student& a) { id = a.id; name = a.name; age = a.age; }
	void display();
};
void Student::display()
{
	cout << "学号：" << id << endl
		<< "姓名：" << name << endl
		<< "年龄：" << age << endl;
}
int main()
{
	Student s[3] = { {1,"Jack",19},{2,"Tom",18},{3,"Linda",20} };
	for (int i = 0; i < 3; i++)
	{
		cout << "****************" << endl;
		s[i].display();
		cout << "****************" << endl;
	}
	return 0;
}