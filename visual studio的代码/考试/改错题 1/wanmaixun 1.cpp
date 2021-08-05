#include<iostream>
using namespace std;
class Date
{
	int yr, mo, day;
	static const int dys[];
	bool Leapyear(int y)const
	{
		return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
	}
public:
	Date() { yr = mo = day = 1; }
	Date(int y , int m , int d )						//请修改其中的错误① 
	{
		yr = y; mo = m; day = d;
	}
	Date(const Date& dt)	         			//请修改其中的错误②	
	{
		yr = dt.yr;
		mo = dt.mo;
		day = dt.day;
	}
	Date(long ndays)
	{
		if (ndays == 0)
			yr = mo = day = 0;
		else
		{
			day = ndays;
			yr = 1;
			while (1)
			{
				int n = Leapyear(yr) ? 366 : 365;
				if (day <= n)		break;
				day -= n;
				++yr;
			}
			for (mo = 1; mo < 13; mo++)
			{
				int n = dys[mo - 1];
				if (mo == 2 && Leapyear(yr))
					n++;
				if (day <= n)	break;
				day -= n;
			}
		}
	}
	~Date() {}
	Date & operator= (const Date & dt)				//请修改其中的错误③ 
	{
		yr = dt.yr; mo = dt.mo; day = dt.day;
		return  *this;
	}
		operator long()const
	{
		long ndays = 0;
		for (int i = 1; i < yr; ++i)
			ndays += Leapyear(i) ? 366 : 365;
		for (int i = 1; i < mo; ++i)
			ndays += dys[i - 1];
		if (mo > 2 && Leapyear(yr))
			++ndays;
		ndays += day;
		return ndays;
	}
	Date  operator--(int)
	{
		Date temp(*this);
		long ndays = *this;
		--ndays;
		*this = ndays;
		return (temp);          //请修改其中的错误④
	}
	void Display()const { cout << yr << '/' << mo << '/' << day << endl; }
};
const int Date::dys[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

int main()
{
	Date d;
	d.Display();
	Date d1(2012, 2, 10);
	d1.Display();
	d = d1--;
	d.Display();
	d1.Display();
	return 0;
}
