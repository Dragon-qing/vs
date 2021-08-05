//
//  main.cpp
//  Queue
//
//  Created by ljpc on 2018/5/29.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include "queue_.h"

int main(int argc, const char * argv[]) {
    // insert code here...

    int n, m, item;
    char str[20];
    scanf("%d %d",&n ,&m);

    Queue que;
    creatQueue(&que, n);
    
    for (int i=0; i<m; i++) {
        scanf("%s", str);
        if(str[0]=='e'){
            scanf("%d", &item);
            enQueue(&que, item);
        }
        else{
            deQueue(&que);
        }
    }
    
    printQueue(&que);
    
    destroyQueue(&que);
    
    return 0;
}
