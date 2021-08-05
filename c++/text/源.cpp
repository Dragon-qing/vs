#include<iostream>
using namespace std;
int n;
int w[] = { 2,2,2,2,2,6,6,5,4,4,4 };
int v[] = { 6,6,3,3,3,5,5,4,6,6,6 };
int solve( int index, int C) {
    int res = 0;
    if (index >=n )
        return 0;
    if (w[index] > C) {
        res=solve(index + 1, C);
    }
    else {
        res = max(solve(index+1,C), v[index] + solve( index +1, C - w[index]));
    }
    return res;
}
int main()
{
    n = sizeof(w) / sizeof(w[0]);
    int sum=solve(0, 10);
    cout << sum;
	return 0;
}