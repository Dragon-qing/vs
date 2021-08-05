/*************************************************************
    date: 
    copyright: Zhu En
    DO NOT distribute this code without my permission.
**************************************************************/
//字符串 实现文件
//////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "kmp.h"
/////////////////////////////////////////////////////

void KmpGenNext(char* p, int* next)
//生成p的next数组, next数组长度大于等于字符串p的长度加1
{
    // 请在此添加代码，补全函数KmpGenNext
    /********** Begin *********/
    int q,k;//q:模版字符串下标；k:最大前后缀长度

    int m=0 ;
    while(p[m]!=0){m++;}
    next[0] = -1;
    for (q = 1,k = 0; q < m; ++q)//for循环，从第二个字符开始，依次计算每一个字符对应的next值
    {
        while(k > 0 && p[q] != p[k])
            k = next[k-1];         
        if (p[q] == p[k])//如果相等，那么最大相同前后缀长度加1
        {
            k++;
        }
        next[q] = k;
    }

    for(int i=0;i<m;i++){
        printf("%d ",next[i]);
    }

    /********** End   *********/
}


int KmpFindSubWithNext(char* t, char* p, int* next)
//从t中查找子串p的第一次出现的位置
//若找到，返回出现的位置，否则返回-1
{
	int i=0, j=0;
	while(p[i]!=0 && t[j]!=0)	{
		if(p[i]==t[j]) 	{ 
			i++;  
			j++; 
		}
		else  if (next[i]>=0) {
			i = next[i];
		}
		else  { 
			i=0;  
			j++; 
		}
	}
	if(p[i]==0)  return j-i; //found
	else  return -1;  //not found
}

