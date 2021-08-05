//
//  main.cpp
//  Cycle
//
//  Created by ljpc on 2018/5/30.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include "queue_.h"

int main(int argc, const char * argv[]) {
    // insert code here...

    int m, item;
    char str[20];
    scanf("%d",&m);

    CycleQueue que;
    creatCycleQueue(&que);
    
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
    system("pause");
    
    return 0;
}
