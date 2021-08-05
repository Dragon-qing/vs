#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PrintTree.h"
#pragma warning(disable:4996)

int main()
{
	char layers[100];
	scanf("%s",layers);
	int n=0; while(layers[n]) n++;//用来保存序列长度

	TNode *r;//用来保存二叉树的根
	r= LayersToTree(layers, n);

	printf("\nPrint (Root Left)：\n");
	PrintTreeRootLeft(r,1);

	DeleteTree(r);
    return 0;
}