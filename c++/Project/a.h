#pragma once
#include<vector>
#include<iostream>
#include<list>
#include<iomanip>
using namespace std;
template<class Iterator, class T>
Iterator Find(Iterator first, Iterator last, const T& x)
{
    while (first != last && *first != x)
    {
        ++first;
    }
    return first;
}
template<class T>
class HashTable
{
private:
    int nt;
    vector<list<T> >ht;
    int size;
    int (*hf)(const T& x);
public:
    explicit HashTable(int n, int (*hash)(const T& x)) :nt(n), hf(hash), size(0) { ht.resize(n); }
    bool Insert(const T& x);
    bool Remove(const T& x);
    bool Find(const T& x)const;
    int Size()const { return size; }
    int Empty()const { return size == 0; }
    int NumberOfBucket()const { return nt; }
    template<class S>
    friend ostream& operator<<(ostream& ostr, const HashTable<S>& ht);
};
template<class T>
bool HashTable<T>::Insert(const T& x)
{
    list<T>& L = ht[hf(x)];
    if (::Find(L.begin(), L.end(), x) != L.end())
        return 0;
    L.push_back(x);
    size++;
    return 1;
}
template<class T>
bool HashTable<T>::Remove(const T& x)
{
    list<T>& L = ht[hf(x)];
    typename list<T>::iterator itr = ::Find(L.begin(), L.end(), x);
    if (itr == L.end())
        return 0;
    L.erase(itr);
    size--;
    return 1;
}
template<class T>
bool HashTable<T>::Find(const T& x)const
{
    const list<T>& L = ht[hf(x)];
    if (::Find(L.begin(), L.end(), x) != L.end())
    {
        return 1;
    }
    return 0;
}
template<class T>
ostream& operator<<(ostream& ostr, const HashTable<T>& ht)
{
    int n = ht.NumberOfBucket();
    typename list<T>::const_iterator first, last;
    for (int i = 0; i < n; ++i)
    {
        first = ht.ht[i].begin(), last = ht.ht[i].end();
        for (; first != last; ++first)
        {
            cout << setw(4) << *first << ' ';
        }
        cout << endl;
    }
    return ostr;
}
