//
//  main.cpp
//  BinaryTreeApp
//
//  Created by ljpc on 2018/5/3.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include <iostream>
#include "binary_tree.h"

BiTreeNode* CreatBiTree(char* s, int &i, int len)
// 利用先序遍历创建二叉树
// 参数：先序遍历字符串s，字符串初始下标i=0，字符串长度len。
// 返回：二叉树
{
    BiTreeNode* root;
    char item = s[i++];
    if(i>=len || item=='#')
    {
        root=NULL;
    }
    else
    {
        root = new BiTreeNode(item);
        root->left = CreatBiTree(s, i, len);
        root->right = CreatBiTree(s, i, len);
    }
    return root;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    char str[200];
    scanf("%s", str);
    
    int i = 0;
    int len = int(strlen(str));
    BiTreeNode* root = CreatBiTree(str, i, len);

    root = BiTreeChangeStack(root);

    PostOrder(root);
    
    return 0;
}
