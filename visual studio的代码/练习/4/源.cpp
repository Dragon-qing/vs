#include<iostream>
using namespace std;
class Household_electricity
{
private:
	double consumption, coefficient;
public:
	Household_electricity(int x,int y):consumption(x), coefficient(y){}
	double cal() { return consumption * 0.785 * coefficient; }
	void display();
};
class car
{
	double Fuel;
public:
	car(int x):Fuel(x){}
	double cal() { return Fuel * 0.785; }
	void display();
};
class plane
{
	double x, con;//x公里数  con该飞机的单位客舱人均碳排放
public:
	plane(double dis,double co):x(dis),con(co){}
	double short_distance() { return x * 0.275 * con; }//短途旅行：200公里以内
	double Half() {return 55 + 0.105 * (x-200);}//中途旅行：200－1000公里
	double long_journey() {return x * 0.139;}//长途旅行
	double cal();//计算
	void display();
};
int main()
{
	return 0;
}