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
Date::Date() :yr(1), mo(1), day(1) {}
Date::Date(int y, int m, int d) : yr(y), mo(m), day(d) {}
Date::Date(const Date& dt)
{
	yr = dt.yr;
	mo = dt.mo;
	day = dt.day;
}
Date::Date(long ndays)
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
	this->yr = year;
	this->mo = mou;
	this->day = day;
}
istream& operator >> (istream& istr, Date& dt)
{
	istr >> dt.yr>> dt.mo >> dt.day;
	return istr;
}
ostream& operator << (ostream& ostr, const Date& dt)
{
	ostr << dt.yr << "/" << dt.mo << "/" << dt.day ;
	return ostr;
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
Date& Date::operator=(const Date& dt)
{
	yr = dt.yr;
	mo = dt.mo;
	day = dt.day;
	return *this;
}
Date& Date:: operator=(long ndays)
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
	this->yr = year;
	this->mo = mou;
	this->day = day;
	return *this;
}
Date::operator long() const
{
	int y = 1, m;
	long days = 0;
	int temp = 0;
	while (y != yr)
	{
		if (Leapyear(y))
		{
			temp = 366;
			days += temp;
		}
		else
		{
			temp = 365;
			days += temp;
		}
		y++;
	}
	if (!Leapyear())
	{
		for (m = 1; m != mo; m++)
		{
			days += dys[m];
		}
	}
	else
	{
		for (m = 1; m != mo; m++)
		{
			if (m != 2)days += dys[m]; else { days += 29; }
		}
	}
	days += day;
	return days;
}
Date& Date::operator++()
{
	++day;
	if (!Leapyear())
	{
		if (day > dys[mo])
		{
			mo++;
			day = 1;
			if (mo > 12) { yr++; mo = 1; }
		}
	}
	else {
		if (mo != 2)
		{
			if (day > dys[mo])
			{
				mo++;
				day = 1;
				if (mo > 12) { yr++; mo = 1; }
			}
		}
		else {
			if (day > 29)
			{
				mo++;
				day = 1;
				if (mo > 12) { yr++; mo = 1; }
			}
		}
	}
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
	--day;
	if (day < 0){
		if (mo - 1 != 2) {
			day = dys[mo - 1];
			mo--;
			if (mo < 0)
			{
				yr--;
				mo = 12;
			}
		}
		else {
			if (!Leapyear()) {
				day = dys[mo - 1];
				mo--;
			}
			else {
				day = 29;
				mo--;
			}
		}
	}
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
	temp = *this+n;
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
	return yr;
}
int Date::Get_month() const
{
	return mo;
}
int Date::Get_day() const
{
	return day;
}
void Date::Set_year(int y)
{
	this->yr = y;
}
void Date::Set_month(int m)
{
	this->mo = m;
}
void Date::Set_day(int d)
{
	this->day = d;
}