#include"String.h"
String::String(const char* c )
{
	if (c == NULL)
	{
		size = 0;
		str = new char[1];
		*str = '\0';
	}
	else
	{
		size = strlen(c);
		str = new char[size + 1];
		strcpy(str, c);
	}
}
String::String(const String& s)
{
	size = s.size;
	str = new char[size + 1];
	strcpy(str, s.str);
}
String& String::operator=(const String& s)
{
	if (s == *this)
		return *this;
	size = s.size;
	if(str)
	   delete[] str;
	str = new char[size + 1];
	strcpy(str, s.str);
	return *this;
}
String&String:: operator=(const char* c)
{
	size = strlen(c);
	if (str)
		delete[] str;
	str = new char[size + 1];
	strcpy(str, c);
	return *this;
}
bool String::operator==(const String& s) const
{
	if (size != s.size)
		return false;
	if (strcmp(str, s.str) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool String::operator==(const char* c) const
{
	if (strcmp(str, c) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator==(const char* c, const String& s)
{
	if (strcmp(c, s.str) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool String::operator<(const String& s) const
{
	if (strcmp(str, s.str) <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool String::operator<(const char* c) const
{
	if (strcmp(str, c) <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator<(const char* c, const String& s)
{
	if (strcmp(c, s.str) <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
String String::operator+(const String& s)
{
	String newString;
	newString.size = size + s.size;
	newString.str = new char[newString.size + 1];
	strcpy(newString.str, str);
	strcat(newString.str, s.str);
	return newString;
}
String String::operator+(const char* c)
{
	String newString;
	newString.size = size + strlen(c);
	newString.str = new char[newString.size + 1];
	strcpy(newString.str, str);
	strcat(newString.str, c);
	return newString;
}
String operator+(const char* c, const String& s)
{
	String temp;
	temp = c;
	return temp+s;
}
String& String::operator+=(const String& s)
{
	*this = str + s;
	return *this;
}
String& String::operator+=(const char* c)
{
	String temp(c);
	*this = str + temp;
	return *this;
}
int String::Find_First_Of(const char c, int id) const
{
	if (id > size - 1)exit(1);
	for (int i = id; i < size; i++)
	{
		if (str[i] == c) { return i; }
	}
	return -1;
}
String& String::Insert(int id, const String& s)
{
	int i,f;
	if (id > size - 1) { exit(1); }
	String temp;
	temp.size = s.size + size;
	temp.str = new char[temp.size+1];
	for (i = 0; i < id ; i++)
	{
		temp.str[i] = str[i];
	}
	for (i = id, f = 0;f <s.size&&i<temp.size; f++, i++)
	{
		temp.str[i] = s.str[f];
	}
	for (i, f = id; i <temp.size; i++, f++)
	{
		temp.str[i] = str[f];
	}
	temp.str[temp.size] = '\0';
	*this = temp;
	return *this;
}
String& String::Insert(int id, const char* c)
{
	String temp(c);
	Insert(id, temp);
	return *this;
}
String& String::Erase(int id, int num)
{
	int i = id;
	for (; str[i + num] != '\0'; i++)
	{
		str[i] = str[i + num];
	}
	size = size - num;
	str[i] = '\0';
	return *this;
}
String String::SubStr(int id, int num) const
{
	String temp;
	int j = 0;
	temp.size = num;
	temp.str = new char[temp.size + 1];
	for (int i = id; i < id + num; i++,j++)
	{
		temp.str[j] = str[i];
	}
	temp.str[temp.size] = '\0';
	return temp;
}
String::operator char* ()
{
	return str;
}
String::operator const char* () const
{
	const char* p = str;
	return p;
}
ostream& operator<<(ostream& ostr, const String& s)
{
	ostr << s.str;
	return ostr;
}
istream& operator>>(istream& istr, String& s)
{
	char tem[1000];  
	istr >> tem;
	s.size = strlen(tem);
	if(!s.str)
	delete[]s.str;
	s.str = new char[s.size + 1];
	strcpy(s.str, tem);
	return istr;
}