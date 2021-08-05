#include<iostream>
using namespace std;
int n;
int w[] = { 2,2,2,2,2,6,6,5,4,4,4 };
int v[] = { 6,6,3,3,3,5,5,4,6,6,6 };
int solve2( int c) {
    if (n == 0) {
        return 0;
    }
    int(*dp)[100] = new int[n][100];
    for (int i = 0; i <=c; ++i) {
        if (i < w[0]) {
            dp[0][i] = 0;
        }
        else {
            dp[0][i] = v[0];
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= c; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    return dp[n - 1][c];
}
int main()
{
    n = sizeof(w) / sizeof(w[0]);
    int sum = solve2(15);
    cout << sum;
    return 0;
}
