#include<iostream>
#include"Date.h"
using namespace std;
const int Date::dys[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
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
void Date::Get_date(int& y, int& m, int& d) const
{
	int x = 0;
	long days = 0;
	int year = 1, mou, day;
	int temp = 0;
	for (year; days < ndays; year++)
	{
		if (Leapyear(year) == true)days += 366;
		else { days += 365; }
	}
	year--;
	if (Leapyear(year) == true)days -= 366;
	else { days -= 365; }
	days = ndays - days;
	for (mou = 1; x < days; mou++)
	{
		if (!Leapyear(year))
		{
			temp = dys[mou];
			x += temp;
		}
		else
		{
			if (mou != 2)
			{
				temp = dys[mou];
				x += temp;
			}
			else
			{
				temp = 29;
				x += temp;
			}
		}
	}
	mou--;
	x -= temp;
	day = days - x;
	y = year;
	m = mou;
	d = day;
}
void Date::Set_date(int y, int m, int d)
{
	int yr = 1, mo;
	long days = 0;
	int temp = 0;
	while (yr != y)
	{
		if (Leapyear(yr))
		{
			temp = 366;
			days += temp;
		}
		else
		{
			temp = 365;
			days += temp;
		}
		yr++;
	}
	if (!Leapyear())
	{
		for (mo = 1; mo != m; mo++)
		{
			days += dys[mo];
		}
	}
	else
	{
		for (mo = 1; mo != m; mo++)
		{
			if (mo != 2)days += dys[mo]; else { days += 29; }
		}
	}
	days += d;
	ndays= days;
}
Date::Date() :ndays(1) {}
Date::Date(int y, int m, int d) { Set_date(y, m, d); }
Date::Date(const Date& dt)
{
	ndays = dt.ndays;
}
Date:: Date(long ndays)
{
	this->ndays = ndays;
}
Date& Date::operator=(const Date& dt)
{
	ndays = dt.ndays;
	return *this;
}
Date& Date::operator=(long ndays)
{
	this->ndays = ndays;
	return *this;
}
bool Date::Leapyear() const
{
	int yr ,m,d;
	Get_date(yr, m, d);
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
Date::operator long() const
{
	return ndays;
}
Date& Date::operator++()
{
	ndays++;
	return *this;
}
Date Date::operator++(int)
{
	Date temp = *this;
	++(*this);
	return temp;
}
Date& Date::operator--()
{
	ndays--;
	return *this;
}
Date Date::operator--(int)
{
	Date temp = *this;
	--(*this);
	return temp;
}
Date& Date::operator+=(int n)
{
	long temp;
	temp = *this + n;
	*this = temp;
	return *this;
}
Date& Date::operator-=(int n)
{
	long temp;
	temp = *this - n;
	*this = temp;
	return *this;
}
int Date::Get_year() const
{
	int yr, mo, day;
	Get_date(yr, mo, day);
	return yr;
}
int Date::Get_month() const
{
	int yr, mo, day;
	Get_date(yr, mo, day);
	return mo;
}
int Date::Get_day() const
{
	int yr, mo, day;
	Get_date(yr, mo, day);
	return day;
}
void Date::Set_year(int y)
{
	int yr, mo, day;
	Get_date(yr, mo, day);
	Set_date(y, mo, day);
}
void Date::Set_month(int m)
{
	int yr, mo, day;
	Get_date(yr, mo, day);
	Set_date(yr, m, day);
}
void Date::Set_day(int d)
{
	int yr, mo, day;
	Get_date(yr, mo, day);
	Set_date(yr, mo, d);
}
istream& operator >> (istream& istr, Date& dt)
{
	int yr, mo, day;
	istr >> yr >> mo >> day;
	dt.Set_date(yr, mo, day);
	return istr;
}
ostream& operator << (ostream& ostr, const Date& dt)
{
	int yr, mo, day;
	dt.Get_date(yr, mo, day);
	ostr << yr << "/" << mo << "/" << day;
	return ostr;
}