#include<iostream>
using namespace std;
int w[] = { 2,2,6,5,4 };
int v[] = { 6,3,5,4,6 };
int N[] = { 2,3,2,1,3 };
int solve(int index, int C) {
    int result = 0;
    if (index < 0 || C == 0) {
        result = 0;
    }
    else if (w[index] > C) {
        // 装不下该种宝物
        result = solve(index - 1, C);
    }
    else {
        // 可以装下
        for (int k = 0; k <= N[index] && k * w[index] <= C; k++) {
            int tmp2 = solve(index - 1, C - w[index] * k) + v[index] * k;
            if (tmp2 > result) {
                result = tmp2;
            }
        }
    }
    return result;
}
int main()
{
    int sum = solve(4, 10);
    cout << sum;
    return 0;
}