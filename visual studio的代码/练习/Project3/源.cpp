#include<iostream>
using namespace std;
class String
{
private:
	char* str;          //String���Ƕ�C�ַ����ķ�װ���ײ��������ַ����͵��������ַ�
	int size;           //�ַ������ַ��ĸ���������'\0'
public:
	explicit String(const char* c = "");      //����ת�����캯����ֻ������ʽת��
	String(const String& s);                  //���ƹ��캯��

	~String() { delete[] str; size = 0; }                //��������
	String& operator=(const char* c);
	String& operator=(const String& s);
	friend ostream& operator<<(ostream& ostr, const String& s);
	friend istream& operator>>(istream& istr, String& s);
};

class Date
{
private:
	int yr, mo, day;								//���ݳ�Ա���꣬�£���
	static const int dys[];				//��̬��Ա���ݣ���Ӧƽ����ÿ�µ�����
	bool Leapyear(int y) const;					//�����ж���������������

public:
	//���캯������������
	Date();           		    //Ĭ�Ϲ��캯�� 
	Date(int y, int m, int d);          //���캯�� 
	Date(const Date& dt);			//���ƹ��캯��
	Date(long ndays);				//����ת�����캯����ʵ��long���͵�Date���͵�ת��
	~Date() {}					//��������
//���ظ�ֵ�����
	Date& operator=(const Date& dt);			//���Ƹ�ֵ�����Date�����֮��ĸ�ֵ
	Date& operator=(long ndays);			//ת����ֵ�����long���͵����ݸ������ֵ
//�����ж�	
	bool Leapyear() const;
	//ת������
	operator long() const; 					//ʵ��Date���͵�long���͵�ת��
//�����Լ������
	Date& operator++();                   //Date d; ++d;
	Date operator++(int);                  //Date d; d++;
	Date& operator--();                    //Date d; --d;
	Date operator--(int);				    //Date d; d--;
	Date& operator+=(int n);               //Date d; d+=n;
	Date& operator-=(int n);               //Date d; d-=n;
//���ݳ�Աȡֵ�͸�ֵ	
	int Get_year() const;               //��ȡ���
	int Get_month() const;             //��ȡ�·�
	int Get_day() const;               //��ȡ����
	void Set_year(int y);               //�������
	void Set_month(int m);            //�����·�
	void Set_day(int d);					//��������

//�������
	friend istream& operator >> (istream& istr, Date& dt);	//���ز������������
	friend ostream& operator<<(ostream& ostr, const Date& dt);        //������ȡ�����������
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
private:   //˽��
	T* itr;
	int size;
	int max;
public:	//����
//���캯������������
	explicit SeqList(int n = 100);     	//ȱʡ���죬����ת�����캯��
	SeqList(const SeqList& l);	       //���ƹ��캯��
	~SeqList() { delete[] itr; } 	   //����

//�����޸ĵĵĳ�Ա����
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

	//���
	for (int i = 0; i < l.size; i++)
	{
		itr[i] = l.itr[i];
	}
	size = l.size;
	max = l.max;
}

//��ֵ��������أ�ʵ��˳���֮��Ŀ���
template <typename T>
SeqList<T>& SeqList<T>::operator=(const SeqList<T>& l)
{
	if (this == &l) return *this;              //����Ƿ����Ҹ�ֵ

	if (max != l.max)							//�������������ͬ
	{
		delete[] itr;                          //ע���ͷ�ԭ���Ŀռ�
		itr = new T[l.max];
	}

	for (int i = 0; i < l.size; i++)
		itr[i] = l.itr[i];
	size = l.size;
	max = l.max;

	return *this;               //����ֵ�����������ã���˷��ضԵ�ǰ���������
}

template <typename T>
T& SeqList<T>::operator[](int id)	           //�±����������
{
	if (id<0 || id>size - 1)
	{
		cout << "id illegal!";
		exit(1);
	}
	return itr[id];
}

template <typename T>
const T& SeqList<T>::operator[](int id)const//�������±����������
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
		cout << "InsertRear: list is full��\n";//����������ʾ
		exit(1);        				//ֹͣ��������
	}
	itr[size] = item;
	size++;
}

template <typename T>
void SeqList<T>::Insert(int id, const T& item)
{
	if (id<0 || id>size || size == max)
	{
		cout << "Insert: id is illegal or list is full��\n";//����������ʾ
		exit(1);        				//ֹͣ��������
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
		cout << "Erase: id is illegal or list is empty��\n"; //����������ʾ
		exit(1);        						//ֹͣ��������
	}

	for (int i = id + 1; i < size; i++)
		itr[i - 1] = itr[i];
	size--;
}

//����ָ���Insert��Erase
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

//���������ֱ�Ϊid1��id2������Ԫ��
template <typename T>
void SeqList<T>::Swap(int id1, int id2) {
	T temp = itr[id1];
	itr[id1] = itr[id2];
	itr[id2] = temp;
}

//��Ԫ��item�滻����Ϊid��Ԫ��
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
	teacher t1("������", "��", 1978, 8, 6, "19960053", "��ʦ", 4000);
	teacher t2("����", "Ů", 1965, 1, 23, "19900025", "����", 5000);
	student s1("Lee", "��", 2002, 5, 3, "20190098", "һ�꼶", "�����", 580);
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