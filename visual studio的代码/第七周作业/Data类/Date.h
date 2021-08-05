#pragma once
#ifndef _DATE_H_
#define _DATE_H_
class Date
{
private:
	int yr, mo, day;								//数据成员：年，月，日
	static const int dys[];				//静态成员数据，对应平常年每月的天数
	bool Leapyear(int y) const;					//闰年判定函数，辅助函数

public:
	//构造函数和析构函数
	Date();           		    //默认构造函数 
	Date(int y, int m, int d);          //构造函数 
	Date(const Date& dt);			//复制构造函数
	Date(long ndays);				//类型转换构造函数，实现long类型到Date类型的转换
	~Date() {}					//析构函数
//重载赋值运算符
	Date& operator=(const Date& dt);			//复制赋值，完成Date类对象之间的赋值
	Date& operator=(long ndays);			//转换赋值，完成long类型的数据给类对象赋值
//闰年判断	
	bool Leapyear() const;
//转换函数
	operator long() const; 					//实现Date类型到long类型的转换
//自增自减运算符
	Date& operator++();                   //Date d; ++d;
	Date operator++(int);                  //Date d; d++;
	Date& operator--();                    //Date d; --d;
	Date operator--(int);				    //Date d; d--;
	Date& operator+=(int n);               //Date d; d+=n;
	Date& operator-=(int n);               //Date d; d-=n;
//数据成员取值和赋值	
	int Get_year() const;               //获取年份
	int Get_month() const;             //获取月份
	int Get_day() const;               //获取日期
	void Set_year(int y);               //设置年份
	void Set_month(int m);            //设置月份
	void Set_day(int d);					//设置日期

//输入输出
	friend ostream& operator<<(ostream& ostr, const Date& dt);	//重载插入符，完成输出
	friend istream& operator >> (istream& istr, Date& dt);        //重载提取符，完成输入
};
ostream& operator<<(ostream& ostr, const Date& dt)
{
	ostr << dt.yr << "/" << dt.mo << "/" << dt.day << endl;
	return ostr;
}
#endif