//
//  main.cpp
//  Stack_Bracket_Match
//
//  Created by ljpc on 2018/4/18.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include <iostream>
#include <cstring>
#include "stack_.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    // std::cout << "Hello, World!\n";
    int len;
    T* str;
    scanf("%d", &len);
    str = (T*)malloc(sizeof(T)*len);
    scanf("%s", str);
    Bracket_Match(str, len);
    system("pause");
    return 0;
}
