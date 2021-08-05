#include<iostream>
#include"Date.h"
using namespace std;
const int Date::dys[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};
bool Date::Leapyear(int y) const
{
	if (y % 100 == 0)
	{
		if (y % 400 == 0)return true;
		else { return false; }
	}
	else
	{
		if (y % 4 == 0)return true;
		else { return false; }
	}
}
Date::Date():yr(1),mo(1),day(1){}
Date::Date(int y, int m, int d):yr(y),mo(m),day(d){}
Date::Date(const Date& dt)
{
	yr = dt.yr;
	mo = dt.mo;
	day = dt.day;
}
//Date::Date(long ndays)
//{
//
//}

istream& operator >> (istream& istr, Date& dt)
{
	istr >> dt.yr >> dt.mo >> dt.day;
	return istr;
}
bool Date::Leapyear() const
{
	if (yr % 100 == 0)
	{
		if (yr % 400 == 0)return true;
		else { return false; }
	}
	else
	{
		if (yr % 4 == 0)return true;
		else { return false; }
	}
}
