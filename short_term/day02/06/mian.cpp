//
//  main.cpp
//  BinaryTreeApp
//
//  Created by ljpc on 2018/5/3.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include <iostream>
#include "binary_tree.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    char str[200];
    scanf("%s", str);
    
    int i = 0;
    int len = int(strlen(str));
    BiTreeNode* root = CreatBiTree(str, i, len);

    InOrder(root);
    
    return 0;
}
