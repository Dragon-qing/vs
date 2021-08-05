#include<iostream>
#include"password.h"
arr::arr()
{
	Arr = new char[max];
	if (Arr == NULL)exit(1);
	size = 20;
}
arr::~arr()
{
	delete[]Arr;
}
void arr::ex()
{
	delete[]Arr;
	Arr = new char[size * 2];
	size *= 2;
}
void arr::copy(const char* s)
{
	while (size - 1 < strlen(s)) { ex(); }
	for (int i = 0; i < strlen(s); i++)
	{
		Arr[i] = s[i];
	}
}