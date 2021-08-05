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
		cout << "家居用电的二氧化碳排放量（Kg）=" << getCarbonFootprint() << endl;
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
		cout << "开车的二氧化碳排放量（Kg）=" << getCarbonFootprint() << endl;
	};
};
class Plane:public CarbonFootprint
{
	double x, con;//x公里数  con该飞机的单位客舱人均碳排放
public:
	Plane(double dis, double co) :x(dis), con(co) {}
	double short_distance() { return x * 0.275 * con; }//短途旅行：200公里以内
	double Half() { return 55 + 0.105 * (x - 200); }//中途旅行：200－1000公里
	double long_journey() { return x * 0.139; }//长途旅行
	double getCarbonFootprint();//计算
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
	cout << "乘坐飞机的二氧化碳排放量（Kg）=" << getCarbonFootprint();
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