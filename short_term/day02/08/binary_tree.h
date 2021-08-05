//
//  binary_tree.h
//  BinaryTreeApp
//
//  Created by ljpc on 2018/5/3.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#ifndef binary_tree_h
#define binary_tree_h

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct BiTreeNode {
    char data;              //  树节点元素
    BiTreeNode* left;       //  左子树指针
    BiTreeNode* right;      //  右子树指针
    BiTreeNode(){           //  树节点初始化
        left=NULL;
        right=NULL;
    }
    BiTreeNode(char item){  //  用元素初始化树节点
        data=item;
        left=NULL;
        right=NULL;
    }
    ~BiTreeNode(){          //  释放树节点内存
        left=NULL;
        right=NULL;
    }
};

BiTreeNode* CreatBiTree(char* s, int &i, int len);
// 利用先序遍历创建二叉树
// 参数：先序遍历字符串s，字符串初始下标i=0，字符串长度len。
// 返回：二叉树

BiTreeNode* BiTreeChange(BiTreeNode* root);
// 实现二叉树左右子树的交换（递归法）
// 参数：二叉树根节点root
// 返回：二叉树

void PreOrder(BiTreeNode* root);
// 二叉树的前序遍历
// 参数：二叉树根节点root
// 输出：二叉树的前序遍历，中间没有空格，末尾不换行。

#endif /* binary_tree_h */
