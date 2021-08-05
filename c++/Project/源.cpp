#include"a.h"

int hf(const int& key)
{
    return key % 7;
}
int main()
{
    HashTable<int>HT(7, hf);
    for (int i = 0; i <= 27; ++i)
        HT.Insert(i);
    cout << HT;
    cout << "after removing:" << endl;
    if (HT.Find(20))
        HT.Remove(20);
    cout << HT << endl;
    system("pause");
    return 0;
}