//
//  binary_tree.cpp
//  BinaryTreeApp
//
//  Created by ljpc on 2018/5/3.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include "binary_tree.h"


BiTreeNode* BiTreeChange(BiTreeNode* root)
// 实现二叉树左右子树的交换（递归法）
// 参数：二叉树根节点root
// 返回：二叉树
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(root==nullptr){
        return nullptr;
    }
    BiTreeNode* t=root->left;
    root->left=BiTreeChange(root->right);
    root->right=BiTreeChange(t);
    return root;
    /********** End **********/
}


void PreOrder(BiTreeNode* root)
// 二叉树的前序遍历
// 参数：二叉树根节点root
// 输出：二叉树的前序遍历，中间没有空格，末尾不换行。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(root==nullptr){
        return ;
    }
    printf("%c",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
    
    /********** End **********/
}

