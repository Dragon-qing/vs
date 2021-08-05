///////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ConstructTree.h"
/////////////////////////////////////////////////////////////


/*
InPreToTree(): 由前序遍历序列和中序遍历序列构造二叉树
前序序列为pa[p1:p2]
中序序列为ia[i1:i2]
返回所构造的二叉树的根指针
*/
TNode* InPreToTree(char *pa, char *ia, int p1, int p2, int i1, int i2)
{
    /*请在BEGIN和END之间实现你的代码*/
    /*****BEGIN*****/
    if(p1>p2||i1>i2){
        return nullptr;
    }
    TNode * node=new TNode;
    node->data=pa[p1];
    for(int i=i1;i<=i2;i++){
        if(pa[p1]==ia[i]){
        node->right=InPreToTree(pa,ia,i-i1+p1+1,p2,i+1,i2);
        node->left=InPreToTree(pa,ia,p1+1,p1+i-i1,i1,i-1);    
        }
    }
    return node;
    /******END******/
    /*请不要修改[BEGIN,END]区域外的代码*/
} 

void PrintPostTravel(TNode* t)
{
	if(t==NULL) return;
	if(t->left) PrintPostTravel(t->left);
	if(t->right) PrintPostTravel(t->right);
	printf("%c", t->data);
}

void DeleteTree(TNode* t)
{
	if(t==NULL) return;
	if(t->left) DeleteTree(t->left);
	if(t->right) DeleteTree(t->right);
	delete t;
}