#ifndef PEO_H_
#define PEO_H_

#include<string>
#include<iostream>
using namespace std;

class People
{
public:
	string Name;
	void PrintName();
};

void People::PrintName()
{
	cout << "ÐÕÃû£º" << Name << endl;
}
#endif