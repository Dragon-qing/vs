#pragma once
#ifndef _PASSWORD_H_
#define _PASSWORD_H_
#define max 20
class arr 
{
private:char* Arr; int size;
public:
	arr();
	void copy(const char*s);
	void ex();
	~arr();
};
typedef struct inf
{
	arr web;
	arr id;
	arr pass;
}inf;
typedef struct node
{
	inf* data;
	node* prev;
	node* next;
}node;
typedef struct list
{
	node* head;
	node* tail;
	int size;
}list;
class password
{
private:list l;
public:
	void menu();//²Ëµ¥
	password();

};
#endif