//
//  binary_tree.cpp
//  BinaryTreeApp
//
//  Created by ljpc on 2018/5/3.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include "binary_tree.h"

void HierarchyOrder(BiTreeNode* root)
// 二叉树的层次遍历（队列实现）
// 参数：二叉树根节点root
// 输出：二叉树的层次遍历，中间没有空格，末尾不换行。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(root==nullptr){
        return ;
    }
    queue<BiTreeNode*> bq;
    bq.push(root);
    while(!bq.empty()){
        BiTreeNode*p=bq.front();
        bq.pop();
        printf("%c",p->data);
        if(p->left)bq.push(p->left);
        if(p->right)bq.push(p->right);
    }

    /********** End **********/

}
