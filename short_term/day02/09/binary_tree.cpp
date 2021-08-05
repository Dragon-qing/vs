//
//  binary_tree.cpp
//  BinaryTreeApp
//
//  Created by ljpc on 2018/5/3.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include "binary_tree.h"


BiTreeNode* BiTreeChangeStack(BiTreeNode* root)
// 实现二叉树左右子树的交换（栈实现）
// 参数：二叉树根节点root
// 返回：二叉树
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(root==nullptr){
        return nullptr;
    }
    stack<BiTreeNode*> bstack;
    bstack.push(root);
    while(!bstack.empty()){
        BiTreeNode*p;
        p=bstack.top();
        bstack.pop();
        BiTreeNode* t=p->left;
        p->left=p->right;
        p->right=t;
        if(p->left){bstack.push(p->left);}
        if(p->right){bstack.push(p->right);}
    }
    return root;
    /********** End **********/
}


void PostOrder(BiTreeNode* root)
// 二叉树的后序遍历
// 参数：二叉树根节点root
// 输出：二叉树的后序遍历，中间没有空格，末尾不换行。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(root==nullptr){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%c",root->data);

    
    /********** End **********/
}
