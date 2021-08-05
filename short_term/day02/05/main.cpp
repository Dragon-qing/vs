#include <stdio.h>
#include <stdlib.h>
#include "kmp.h"
//#include "Special.h"
//////////////////////////////////////////////////////
#pragma warning(disable:4996)
/////////////////////////////////////////////////////


int main()
{
	
	//to test finding the first son string
	//将对朴素的匹配算法进行对比，确认你是否在使用Kmp
	char t[100]; //mother string
	char p[100]; //son string
	scanf("%[^\n]", t);
	scanf("%s", p);
	int m=0;
	while(p[m]!=0) m++;
	int* next=(int*)malloc((m+1)*sizeof(int));
	KmpGenNext(p, next);
	int i;
	int k;


	//unsigned __int64 tick1=GetCycleCount();
	//for (k=0;k<100;k++) 
    i=KmpFindSubWithNext(t,p,next);
	//tick1=GetCycleCount()-tick1;
	///printf("count1:%d\n",tick1);
	free(next);

	//unsigned __int64 tick2=GetCycleCount();
	//for (k=0;k<100;k++) i=FindSubStr(t,p);
	//tick2=GetCycleCount()-tick2;
	///printf("count2:%d\n",tick2);

	//int more = tick2-tick1;
	
	//if (tick2-tick1<50000) printf("You are not using KMP.\n");
	
	printf("Location: ");
	if(i==-1) printf("not found!");
	else printf("%d",i);
	system("pause");
}


/*
特别说明：KMP算法应比第1关的朴素的匹配算法高效，
系统将你实现的算法与标准的朴素的匹配算法的效率进行对比，以验证你的算法确实更高效，
如果你的算法的效率与朴素的匹配算法的效率相当，甚至更差，测试程序将输出“You are not using KMP.”。

输入格式：
输入一个长字符串。
然后输入一个短字符串。
输出格式：
输出短字符串在长字符串中的位置。

样例输入
stringabcedf1stringabcdef2stringabcdef3stringabcdef4stringabcdef5stringabcdef6stringabcdef7
stringabcdef7
样例输出
Location: 78

*/