#include <stdio.h>

typedef int(*Point)[2];//用typedef重新定义一个数组指针（为了方便）
Point Two_Array(void)
{
    static int a[2][2] = { 1,2,3,4 };
    return a;
}

int main(void)
{
    int i, j = 0;
    Point p;
    p = Two_Array();
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d", p[i][j]);
        }
        printf("\n");
    }
}
