#include<iostream>
using namespace std;
struct list{
	int date;
	list* next;
};
list* gethead()
{
	list* head;
	head = new list;
	head->date = 0;
	head->next = NULL;
}
int main()
{

	return 0;
}