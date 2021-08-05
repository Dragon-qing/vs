//
//  binary_tree.cpp
//  BinaryTreeApp
//
//  Created by ljpc on 2018/5/3.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include "binary_tree.h"

int GetTreeDepth(BiTreeNode* root)
// 计算该二叉树的深度
// 参数：二叉树根节点root
// 返回：二叉树的深度
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(root==nullptr){
        return 0;
    }
    int re=1;
    return max(re+GetTreeDepth(root->left),re+GetTreeDepth(root->right));

    /********** End **********/
}

int GetNodeNumber(BiTreeNode* root)
// 计算该二叉树的总节点个数
// 参数：二叉树根节点root
// 返回：二叉树的总节点个数
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(root==nullptr){
        return 0;
    }
    int sum=1;
    return sum+GetNodeNumber(root->left)+GetNodeNumber(root->right);
    
    /********** End **********/
}

int GetLeafNodeNumber(BiTreeNode* root)
// 计算该二叉树的叶子节点个数
// 参数：二叉树根节点root
// 返回：二叉树的叶子节点个数
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(root==nullptr){
        return 0;
    }
    if(root->left==nullptr&&root->right==nullptr){
        return 1;
    }
    return GetLeafNodeNumber(root->left)+GetLeafNodeNumber(root->right);
    
    /********** End **********/
}

