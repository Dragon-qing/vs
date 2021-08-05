#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <iostream>
//#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define inf ((LL)1<<40)
#define lson k<<1, L, mid
#define rson k<<1|1, mid+1, R
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define mem(a, b) memset(a, b, sizeof(a))
#define FOPENIN(IN) freopen(IN, "r", stdin)
#define FOPENOUT(OUT) freopen(OUT, "w", stdout)
template<class T> T ABS(T a) { return a >= 0 ? a : -a; }
template<class T> T CMP_MIN(T a, T b) { return a < b; }
template<class T> T CMP_MAX(T a, T b) { return a > b; }
template<class T> T MAX(T a, T b) { return a > b ? a : b; }
template<class T> T MIN(T a, T b) { return a < b ? a : b; }
template<class T> T GCD(T a, T b) { return b ? GCD(b, a % b) : a; }
template<class T> T LCM(T a, T b) { return a / GCD(a, b) * b; }
template<class T> void SWAP(T& a, T& b) { T t = a; a = b; b = t; }

typedef __int64 LL;
//typedef long long LL;
const int MAXN = 10005;
const int MAXM = 110000;
const double eps = 1e-14;
const double PI = 4.0 * atan(1.0);




LL n, ans;
int t;




#define Times 10

//产生[0, n-1]的一个随机数
LL random(LL n)
{
    return ((double)rand() / RAND_MAX * n + 0.5);
}
//乘法，采用加法模拟，避免中间结果超出LL
LL multi(LL a, LL b, LL mod)
{
    LL ans = 0;
    while (b)
    {
        if (b & 1)
        {
            b--;
            ans = (ans + a) % mod;
        }
        else
        {
            b /= 2;
            a = (2 * a) % mod;
        }
    }
    return ans;
}

//快速幂，同样避免超出LL的做法
LL Pow(LL a, LL b, LL mod)
{
    LL ans = 1;
    while (b)
    {
        if (b & 1)
        {
            b--;
            ans = multi(ans, a, mod);
        }
        else
        {
            b /= 2;
            a = multi(a, a, mod);
        }
    }
    return ans;
}

//miller_rabin的一遍探测，返回false表示是合数
bool witness(LL a, LL n)
{
    LL d = n - 1;
    while (!(d & 1))
        d >>= 1;
    LL t = Pow(a, d, n);
    while (d != n - 1 && t != 1 && t != n - 1)
    {
        t = multi(t, t, n);
        d <<= 1;
    }
    return t == n - 1 || d & 1;
}

//miller_rabin算法，返回false表示是合数，否则是素数
//返回素数出错的概率(最高)为 1 / (4 ^ times)
bool miller_rabin(LL n)
{
    if (n == 2)
        return true;
    if (n < 2 || !(n & 1))
        return false;
    for (int i = 1; i <= Times; i++)
    {
        LL a = random(n - 2) + 1;
        if (!witness(a, n))
            return false;
    }
    return true;
}


//************************************************
//pollard_rho 算法进行质因数分解
//************************************************
LL factor[100];//质因数分解结果（刚返回时是无序的）
int tol;//质因数的个数。数组小标从0开始

LL gcd(LL a, LL b)
{
    if (a == 0)return 1;//???????
    if (a < 0) return gcd(-a, b);
    while (b)
    {
        LL t = a % b;
        a = b;
        b = t;
    }
    return a;
}

LL Pollard_rho(LL x, LL c)
{
    LL i = 1, k = 2;
    LL x0 = rand() % x;
    LL y = x0;
    while (1)
    {
        i++;
        x0 = (multi(x0, x0, x) + c) % x;
        LL d = gcd(y - x0, x);
        if (d != 1 && d != x) return d;
        if (y == x0) return x;
        if (i == k) { y = x0; k += k; }
    }
}

//对n进行素因子分解
void findfac(LL n)
{
    if (miller_rabin(n))//素数
    {
        factor[tol++] = n;
        ans = MIN(ans, n);
        return;
    }
    LL p = n;
    while (p >= n)
        p = Pollard_rho(p, rand() % (n - 1) + 1);
    findfac(p);
    findfac(n / p);
}



int main()
{
    //FOPENIN("in.txt");
    while (~scanf("%d", &t))while (t--)
    {
        ans = inf;
        scanf("%I64d", &n);
        findfac(n);
        if (miller_rabin(n))
            printf("Prime\n");
        else printf("%I64d\n", ans);
    }
    return 0;
}