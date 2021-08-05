#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ConstructTree.h"
#pragma warning(disable:4996)

int main()
{
	char pre[100], in[100];
	int n; //用来保存序列长度
	TNode *t;//用来保存二叉树的根
	scanf("%s", pre);
	scanf("%s", in);
	n=0; while(pre[n]) n++;
	t= InPreToTree(pre, in, 0, n-1, 0, n-1);
	printf("Post Travel Result:");
	PrintPostTravel(t);
	printf("\n");
	DeleteTree(t);
    return 0;
}
