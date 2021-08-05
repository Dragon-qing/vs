#include<stdio.h>
#include<string.h>

int output[120];   //第一位为1，方便计算
int m;
//num是去掉小数点后的十进制数字,比如95.23变为9523
//因为我们要乘的数是固定的，所以可以都去掉小数点计算，最后如果有小数点加上去就行了
void cal( int num)
{
    int i;
    for (i = 0; i < m; i++)
    {
        output[i] = output[i] * num;       //因为最大的数可能为99999,99999*9不会超出int范围的,所以先乘好，然后再考虑进位
    }
    for (i = 0; i < m - 1; i++)
    {
        if (output[i] >= 10)
        {
            output[i + 1] += output[i] / 10;
            output[i] %= 10;
        }
    }
    int t = output[m - 1];
    int p = m - 1;
    if (t >= 10)   //把最后一个数字比如45，存储到字符数组中
    {
        while (t > 0)
        {
            output[p++] = t % 10;
            t /= 10;
        }
    }
    m = p;
    return;
}

int main()
{
    char str[6];
    int n;
    while (scanf("%s%d", str, &n) != EOF)
    {

        int sum = 0, Pointsum = 0;
        int length = strlen(str), i;
        for (i = 0; i < length; i++)
        {
            if (str[i] == '.')
            {
                Pointsum = (length - (i + 1)) * n;   //记录有多少位小数
            }
            else
            {
                sum = sum * 10 + str[i] - '0';       //迭代增加求完整的十进制数
            }
        }
        if (sum == 0)
        {
            printf("0\n");
            continue;
        }
        memset(output, 0, sizeof(output));
        output[0] = 1;
        m = 1;
        for (i = 0; i < n; i++)
            cal( sum);

        int temp = 0;
        for (i = 0; i < m; i++)  //先去掉后缀零
        {
            if (output[i] != 0)
            {
                temp = i;         //第一位不为零的数字
                break;
            }
        }
        if (Pointsum - temp <= 0)   //没有小数点
            for (i = m - 1; i >= Pointsum; i--)    //temp也是非零的
                printf("%d", output[i]);
        else      //有小数点
        {
            if (Pointsum > m)
                m = Pointsum;
            for (i = m - 1; i >= Pointsum; i--)
                printf("%d", output[i]);
            printf(".");
            for (; i >= temp; i--)
                printf("%d", output[i]);
        }
        printf("\n");

    }
    return 0;
}