#pragma once
#ifndef _STRING_H_
#define _STRING_H_
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

	int Size() const { return size; }         //�����ַ������ַ��ĸ���

	String& operator=(const String& s);       //���Ƹ�ֵ��������أ�String�������ַ���֮�丳ֵ
	String& operator=(const char* c);         //ת����ֵ��������أ���C�ַ���ΪString�������ַ�����ֵ

	//�Ƚ��ַ����Ƿ���ͬ������ֵΪ������
	bool operator==(const String& s) const;    //String���ַ���֮��ıȽϣ���String�മ == String�മ
	bool operator==(const char* c) const;      //String���ַ�����C�ַ���֮��ıȽϣ���String�മ == C�ַ��� 
	friend bool operator==(const char* c, const String& s);//C�ַ�����String���ַ���֮��ıȽϣ���C�ַ��� == String�മ

	//�Ƚ��ַ����Ĵ�С������ֵΪ������
	bool operator<(const String& s) const;    //String���ַ���֮��ıȽϣ���String�മ <= String�മ
	bool operator<(const char* c) const;      //String���ַ�����C�ַ���֮��ıȽϣ���String�മ <= C�ַ��� 
	friend bool operator<(const char* c, const String& s);//C�ַ�����String���ַ���֮��ıȽϣ���C�ַ��� <= String�മ

	//�ַ���������
	String operator+(const String& s);    //String�മ + String�മ
	String operator+(const char* c);      //String�മ + C�ַ���
	friend String operator+(const char* c, const String& s);    //C�ַ���+String�മ

	String& operator+=(const String& s);    //String�മ += String�മ
	String& operator+=(const char* c);      //String�മ += C�ַ���

	//��id��ʼ�����ַ��״γ��ֵ�λ�ã�����ҵ��������±꣬���ڷ���-1
	int Find_First_Of(const char c, int id) const;

	//���ַ����±�Ϊid������String���͵��ַ���s
	String& Insert(int id, const String& s);
	//���ַ����±�Ϊid������C�ַ���c
	String& Insert(int id, const char* c);

	//���±�id��ʼ����ɾ��num���ַ���
	String& Erase(int id, int num);

	//���ַ����±�Ϊid����ʼ����ȡnum���ַ���������ַ�������
	String SubStr(int id, int num) const;

	//Type-cast operator, ��String����ת��Ϊchar*���͡�
	explicit operator char* ();
	//Type-cast operator, ��String����ת��Ϊconst char*���͡�
	explicit operator const char* () const;

	//�±������[]������
	char& operator[](int id) { return str[id]; }
	const char& operator[](int id)const { return str[id]; }

	//�������
	friend ostream& operator<<(ostream& ostr, const String& s);
	friend istream& operator>>(istream& istr, String& s);
};
#endif
