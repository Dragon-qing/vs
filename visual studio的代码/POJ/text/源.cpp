#include<stdio.h>
#include<string.h>

int output[120];   //��һλΪ1���������
int m;
//num��ȥ��С������ʮ��������,����95.23��Ϊ9523
//��Ϊ����Ҫ�˵����ǹ̶��ģ����Կ��Զ�ȥ��С������㣬��������С�������ȥ������
void cal( int num)
{
    int i;
    for (i = 0; i < m; i++)
    {
        output[i] = output[i] * num;       //��Ϊ����������Ϊ99999,99999*9���ᳬ��int��Χ��,�����ȳ˺ã�Ȼ���ٿ��ǽ�λ
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
    if (t >= 10)   //�����һ�����ֱ���45���洢���ַ�������
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
                Pointsum = (length - (i + 1)) * n;   //��¼�ж���λС��
            }
            else
            {
                sum = sum * 10 + str[i] - '0';       //����������������ʮ������
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
        for (i = 0; i < m; i++)  //��ȥ����׺��
        {
            if (output[i] != 0)
            {
                temp = i;         //��һλ��Ϊ�������
                break;
            }
        }
        if (Pointsum - temp <= 0)   //û��С����
            for (i = m - 1; i >= Pointsum; i--)    //tempҲ�Ƿ����
                printf("%d", output[i]);
        else      //��С����
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