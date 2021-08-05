/*************************************************************
    date: April 2009
    copyright: Zhu En
    DO NOT distribute this code.
**************************************************************/
#include<stdio.h>
int FindSubStr(char* t, char* p)
/*
从字符串t查找子字符串p。
字符串以数值结尾，例如p="str",那么p[0]='s',p[1]='t',p[2]='r',p[3]=0。
采用朴素的匹配算法。
返回子字符串第一次出现的位置,例如t="string ring",p="ring"，则返回2。
若没有找到，则返回-1。
*/
{
    // 请在此添加代码，补全函数FindSubStr
    /********** Begin *********/
    int t_len=0;
    int p_len=0;
    for(int i=0;i<100;i++){
        if(t[i]!=0) t_len++;
        else{break;}
    }
    for(int i=0;i<100;i++){
        if(p[i]!=0) p_len++;
        else{break;}
    }
    //printf("%d %d",t_len,p_len);
    for(int i=0;i<t_len-p_len+1;i++){
        if(t[i]==p[0]){
            for(int j=0;j<p_len;j++){
                if((j+1)==p_len&&t[i+j]==p[j]){
                    return i;
                }else if(t[i+j]!=p[j]){
                    break;
                }
                
            }
        }
    }
    return -1;

    /********** End **********/
}
