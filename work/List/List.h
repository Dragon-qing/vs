#pragma once
#ifndef LIST_H
#define LIST_H
#include<stdlib.h>


template<class T>
class List
{
	struct node
	{
		T data;
		node* prv;
		node* next;
		node(const T& d = T(), node* p = NULL, node* n = NULL) :data(d), prv(p), next(n) {}
	};
	int size;
	node *Head;
	node *Tail;
	void Init() { size = 0; Head = new node; Tail = new node; Head->next = Tail; Tail->prv = Head; }
public:
	class const_iterator
	{
	protected:
		node* current;
		T& retrieve()const { return(current->data); }
		const_iterator(node*p):current(p){}
		friend class List<T>;
	public:
		
		const_iterator() :current(NULL) {}
		const T& operator*()const { return retrieve(); }
		const_iterator& operator++()
		{
			current = current->next;
			return *this;
		}
		const_iterator operator++(int)
		{
			const_iterator old = *this;
			++(*this);
			return old;
		}
		const_iterator& operator--()
		{
			current = current->prv;
			return *this;
		}
		const_iterator operator--(int)
		{
			const_iterator old=*this;
			--(*this);
			return old;
		}
		bool operator==(const const_iterator&rhs)
		{
			return (current == rhs.current);
		}
		bool operator!=(const const_iterator& rhs)
		{
			return (current != rhs.current);
		}
	};
	class iterator :public const_iterator
	{
	protected:
		iterator(node* p) : const_iterator(p) {}
		friend class List<T>;
	public:
		iterator():const_iterator(NULL) {}
		T& operator*() { return const_iterator::retrieve(); }
		const T& operator*()const { return const_iterator::operator*(); }
		iterator& operator++()
		{
			this->current = this->current->next;
			return (*this);
		}
		iterator operator++(int)
		{
			iterator old;
			old = *this;
			++(* this);
			return(old);
		}
		iterator& operator--()
		{
			this->current = this->current->prv;
			return(*this);
		}
		iterator operator--(int)
		{
			iterator old = *this;
			--(*this);
			return old;
		}
	};
	List() { Init(); }
	List(const List<T>& l) {Init(); operator=(l); }
	~List() { clear(); delete Head; delete Tail; }
	const List& operator=(const List& l);
	int Size()const { return size; }
	bool Empty()const { return size == 0; }
	void clear() { while (!Empty())Pop_front(); }
	iterator begin() { return iterator(Head->next); }
	const_iterator begin()const { return (const_iterator(Head->next)); }
	iterator End() { return(iterator(Tail)); }
	const_iterator End()const { return const_iterator(Tail); }
	T& Front() { return(*begin()); }
	const T& Front()const { return *begin(); }
	T& Back() { return *--End(); }
	const T& Back()const { return *--End(); }
	void Push_front(const T& item) { Insert(begin(), item); }
	void Push_back(const T& item) { Insert(End(), item); }
	void Pop_front() { Erase(begin()); }
	void Pop_back() { Erase(--End()); }
	iterator Erase(iterator itr);
	iterator Insert(iterator itr, const T& item);
};
template<class T>
const List<T>& List<T>::operator=(const List<T>& l)
{
	clear();
	for (iterator p = l.begin(); p != l.End(); p++)
	{
		Push_back(*p);
	}
	return *this;
}
template<class T>
typename List<T>::iterator List <T>::Erase(iterator itr)
{
	node* p = itr.current;
	iterator re(p->next);
	p->prv->next = p->next;
	p->next->prv = p->prv;
	delete p;
	size--;
	return re;
}
template<class T>
typename List<T>::iterator List<T>::Insert(iterator itr, const T& item)
{
	node* p = itr.current;
	p->prv->next = new node(item, p->prv, p);
	p->prv = p->prv->next;
	size++;
	iterator re(p->prv);
	return re;
}

#endif
