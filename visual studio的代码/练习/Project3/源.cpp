#include<iostream>
using namespace std;
class String
{
private:
	char* str;          //String类是对C字符串的封装，底层仍是用字符类型的数组存放字符
	int size;           //字符串中字符的个数，不算'\0'
public:
	explicit String(const char* c = "");      //类型转换构造函数，只允许显式转换
	String(const String& s);                  //复制构造函数

	~String() { delete[] str; size = 0; }                //析构函数
	String& operator=(const char* c);
	String& operator=(const String& s);
	friend ostream& operator<<(ostream& ostr, const String& s);
	friend istream& operator>>(istream& istr, String& s);
};

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
	friend istream& operator >> (istream& istr, Date& dt);	//重载插入符，完成输出
	friend ostream& operator<<(ostream& ostr, const Date& dt);        //重载提取符，完成输入
};
const int Date::dys[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
bool Date::Leapyear(int y) const
{
	if (y % 100 == 0)
	{
		if (y % 400 == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (y % 4 == 0)
		{
			return true;
		}

		else
		{
			return false;
		}
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
		if (Leapyear(year) == true)
		{
			days += 366;
		}
		else
		{
			days += 365;
		}
	}
	year--;
	if (Leapyear(year) == true)
	{
		days -= 366;
	}
	else
	{
		days -= 365;
	}
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

bool Date::Leapyear() const
{
	if (yr % 100 == 0)
	{
		if (yr % 400 == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (yr % 4 == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
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
		if (Leapyear(year) == true)
		{
			days += 366;
		}
		else
		{
			days += 365;
		}
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
			if (m != 2) {
				days += dys[m];
			}
			else
			{
				days += 29;
			}
		}
	}
	days += day;
	return days;
}
Date& Date::operator++()
{
	day++;
	return *this;
}

Date& Date::operator--()
{
	day--;
	return *this;
}

Date Date::operator++(int)
{
	++(*this);
	return *this;
}
Date Date::operator--(int)
{
	--(*this);
	return *this;
}
Date& Date::operator+=(int n)
{
	long temp = *this + n;
	*this = temp;
	return *this;
}
Date& Date::operator-=(int n)
{
	long temp = *this - n;
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
	yr = y;
}
void Date::Set_month(int m)
{
	mo = m;
}
void Date::Set_day(int d)
{
	day = d;
}
istream& operator >> (istream& istr, Date& dt)
{
	istr >> dt.yr >> dt.mo >> dt.day;
	return istr;
}
ostream& operator << (ostream& ostr, const Date& dt)
{
	ostr << dt.yr << "/" << dt.mo << "/" << dt.day;
	return ostr;
}
class Person {
	String name;
	String sex;
	Date birth;
public:
	Person(const char* n, const char* s, int y, int m, int d) :name(n), sex(s), birth(y, m, d) {}
	Person(const Person& p);
	~Person() {}
	virtual void display();
};
class teacher :public Person {
	String job_number;
	String rank;
	double salary;
public:
	teacher(const char* n = "", const char* s = "", int y = 0, int m = 0, int d = 0, const char* j = "", const char* r = "", double sal = 0) :Person(n, s, y, m, d)
	{
		job_number = j; rank = r;  salary = sal;
	}
	teacher(const teacher& t);
	~teacher() {}
	void display();
};
class student :public Person {
	String id;
	String grade;
	String major;
	int score;
public:
	student(const char* n = "", const char* s = "", int y = 0, int m = 0, int d = 0, const char* i = "", const char* g = "", const char* ma = "", int scor = 0);
	student(const student& s);
	~student() {}
	void display();
};
//SeqListT.h
template <typename T>
class SeqList
{
private:   //私有
	T* itr;
	int size;
	int max;
public:	//公有
//构造函数和析构函数
	explicit SeqList(int n = 100);     	//缺省构造，类型转换构造函数
	SeqList(const SeqList& l);	       //复制构造函数
	~SeqList() { delete[] itr; } 	   //析构

//用于修改的的成员函数
	SeqList& operator=(const SeqList& l);
	void InsertRear(const T& item);
	void Insert(int id, const T& item);
	void Erase(int id);
	void Clear() { size = 0; }
	T& operator[](int id);
	const T& operator[](int id)const;

	int Size()const { return size; }
	bool Empty()const { return size == 0; }
	bool Full()const { return size == max; }

	//Operation based on pointer
	T* Begin() { return itr; }
	const T* Begin() const { return itr; }
	T* End() { return itr + size; }
	const T* End() const { return itr + size; }

	void Insert(T* itr, const T& item);
	void Erase(T* itr);

	//Swap two item according to the id
	void Swap(int id1, int id2);
	void Replace(int id, const T& item);
};

template <typename T>
SeqList<T>::SeqList(int n)
{
	itr = new T[n];
	size = 0;
	max = n;
}

template <typename T>
SeqList<T>::SeqList(const SeqList& l)
{
	itr = new T[l.max];

	//深复制
	for (int i = 0; i < l.size; i++)
	{
		itr[i] = l.itr[i];
	}
	size = l.size;
	max = l.max;
}

//赋值运算符重载，实现顺序表之间的拷贝
template <typename T>
SeqList<T>& SeqList<T>::operator=(const SeqList<T>& l)
{
	if (this == &l) return *this;              //检查是否自我赋值

	if (max != l.max)							//如果数组容量不同
	{
		delete[] itr;                          //注意释放原来的空间
		itr = new T[l.max];
	}

	for (int i = 0; i < l.size; i++)
		itr[i] = l.itr[i];
	size = l.size;
	max = l.max;

	return *this;               //返回值的类型是引用，因此返回对当前对象的引用
}

template <typename T>
T& SeqList<T>::operator[](int id)	           //下标操作符重载
{
	if (id<0 || id>size - 1)
	{
		cout << "id illegal!";
		exit(1);
	}
	return itr[id];
}

template <typename T>
const T& SeqList<T>::operator[](int id)const//常量型下标操作符重载
{
	if (id<0 || id>size - 1)
	{
		cout << "id illegal!";
		exit(1);
	}
	return itr[id];
}

template <typename T>
void SeqList<T>::InsertRear(const T& item)
{
	if (size == max)
	{
		cout << "InsertRear: list is full！\n";//错误类型提示
		exit(1);        				//停止程序运行
	}
	itr[size] = item;
	size++;
}

template <typename T>
void SeqList<T>::Insert(int id, const T& item)
{
	if (id<0 || id>size || size == max)
	{
		cout << "Insert: id is illegal or list is full！\n";//错误类型提示
		exit(1);        				//停止程序运行
	}
	for (int i = size - 1; i >= id; i--)
		itr[i + 1] = itr[i];

	itr[id] = item;
	size++;
}

template <typename T>
void SeqList<T>::Erase(int id)
{
	if (id<0 || id>size - 1)
	{
		cout << "Erase: id is illegal or list is empty！\n"; //错误类型提示
		exit(1);        						//停止程序运行
	}

	for (int i = id + 1; i < size; i++)
		itr[i - 1] = itr[i];
	size--;
}

//基于指针的Insert，Erase
template <typename T>
void SeqList<T>::Insert(T* itr, const T& item) {
	if (itr < Begin() || itr > End()) {
		cout << "The pointer is out of range!" << endl;
		system("pause");
		exit(1);
	}

	for (T* ptr = this->End(); ptr != itr; ptr--)
		*ptr = *(ptr - 1);
	*itr = item;

	size++;
}

template <typename T>
void SeqList<T>::Erase(T* itr) {
	if (itr < Begin() || itr >= End()) {
		cout << "The pointer is out of range!" << endl;
		system("pause");
		exit(1);
	}
	for (T* ptr = itr + 1; ptr != this->End(); ptr++)
		*(ptr - 1) = *ptr;

	size--;
}

//交换索引分别为id1和id2的两个元素
template <typename T>
void SeqList<T>::Swap(int id1, int id2) {
	T temp = itr[id1];
	itr[id1] = itr[id2];
	itr[id2] = temp;
}

//用元素item替换索引为id的元素
template <typename T>
void SeqList<T>::Replace(int id, const T& item) {
	itr[id] = item;
}
void f(Person* p)
{
	p->display();
}
int main()
{
	teacher t1("吴晓刚", "男", 1978, 8, 6, "19960053", "教师", 4000);
	teacher t2("曾黎", "女", 1965, 1, 23, "19900025", "教授", 5000);
	student s1("Lee", "男", 2002, 5, 3, "20190098", "一年级", "计算机", 580);
	SeqList<Person*>l;
	l.InsertRear(&t1);
	l.InsertRear(&t2);
	l.InsertRear(&s1);
	for (int i = 0; i < l.Size(); i++)
	{
		cout << i + 1 << "th" << endl;
		f(l[i]);
	}
	return 0;
}