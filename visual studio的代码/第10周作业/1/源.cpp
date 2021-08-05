#include<iostream>
using namespace std;
class CarbonFootprint
{
public:
	virtual double getCarbonFootprint() = 0;
};
class House :public CarbonFootprint
{
	double consumption; double coefficient;
public:
	House(double x, double y) :consumption(x), coefficient(y) {}
	double getCarbonFootprint() { return consumption * 0.785 * coefficient; }
	void display() 
	{
		cout << "�Ҿ��õ�Ķ�����̼�ŷ�����Kg��=" << getCarbonFootprint() << endl;
	}
};
class Car:public CarbonFootprint
{
	double Fuel;
public:
	Car(int x) :Fuel(x) {}
	double getCarbonFootprint() { return Fuel * 0.785; }
	void display()
	{
		cout << "�����Ķ�����̼�ŷ�����Kg��=" << getCarbonFootprint() << endl;
	};
};
class Plane:public CarbonFootprint
{
	double x, con;//x������  con�÷ɻ��ĵ�λ�Ͳ��˾�̼�ŷ�
public:
	Plane(double dis, double co) :x(dis), con(co) {}
	double short_distance() { return x * 0.275 * con; }//��;���У�200��������
	double Half() { return 55 + 0.105 * (x - 200); }//��;���У�200��1000����
	double long_journey() { return x * 0.139; }//��;����
	double getCarbonFootprint();//����
	void display();
};
double Plane::getCarbonFootprint()
{
	if (x <= 200)return short_distance();
	else if (x <= 1000)return Half();
	else return long_journey();
	
}
void Plane::display()
{
	cout << "�����ɻ��Ķ�����̼�ŷ�����Kg��=" << getCarbonFootprint();
}
void print(CarbonFootprint* p)
{
	cout << "getCarbonFootprint()=" << p->getCarbonFootprint() << endl;
}
int main()
{
	House a(12.5, 0.75);
	Car b(100);
	Plane c(300,10);
	CarbonFootprint* arr[5] = {&a,&b,&c};
	for (int i = 0; i < 3; i++)
	{
		print(arr[i]);
	}
	return 0;
}