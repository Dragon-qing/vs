#pragma once
#ifndef _DATE_H_
#define _DATE_H_
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
	friend ostream& operator<<(ostream& ostr, const Date& dt);	//���ز������������
	friend istream& operator >> (istream& istr, Date& dt);        //������ȡ�����������
};
ostream& operator<<(ostream& ostr, const Date& dt)
{
	ostr << dt.yr << "/" << dt.mo << "/" << dt.day << endl;
	return ostr;
}
#endif