//
//  binary_tree.cpp
//  BinaryTreeApp
//
//  Created by ljpc on 2018/5/3.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include "binary_tree.h"


BiTreeNode* CreatBiTree(char* s, int &i, int len)
// 利用先序遍历创建二叉树
// 参数：先序遍历字符串s，字符串初始下标i=0，字符串长度len。
// 返回：二叉树
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(i>=len||s[i]=='#'){
        return nullptr;
    }
    BiTreeNode* node=(BiTreeNode*)malloc(sizeof(BiTreeNode));
    node->data=s[i];
    node->left=CreatBiTree(s,i+=1,len);
    if(s[i]=='#')
    node->right=CreatBiTree(s,i+=1,len);
    return node;
    /********** End **********/
}

void InOrder(BiTreeNode* root)
// 二叉树的中序遍历
// 参数：二叉树根节点root
// 输出：中间没有空格，末尾不换行。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(root==nullptr){
        return;
    }
    InOrder(root->left);
    printf("%c",root->data);
    InOrder(root->right);
    
    /********** End **********/

}
