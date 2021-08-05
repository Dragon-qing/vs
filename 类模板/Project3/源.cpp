#include<iostream>
using namespace std;

int MaxEle(int a[3][2], int* r, int* c)
{
    /********* Begin *********/
    //返回最大元素和它所在的行、列号
    int i, j;
    int max = a[0][0];
        for (i = 0, j = 0; i < 3; i++)
        {
            for (j; j < 2; j++)
            {
                if (a[i][j] > max) { max = a[i][j]; *r = i; *c = j; }
            }
            if (j == 2)j = 0;
        }

    return max;
    /********* End *********/
}

int main()
{
    int a[3][2] = { {1,2},{50,4},{5,6} };
    int r, c;
    cout << MaxEle(a, &r, &c)<<endl;
    cout << r << ";" << c << endl;
    return 0;
}