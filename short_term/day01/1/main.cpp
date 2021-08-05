#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqStack.h"
#include<iostream>
using namespace std;
int main()
{
    int max;
    scanf("%d", &max);
    SeqStack* ss = SS_Create(max);
    char dowhat[100];
    while(true) {
        scanf("%s", dowhat);
        if (!strcmp(dowhat,"push")) {
            T x;
            scanf("%d", &x);
            SS_Push(ss,x);
        }else if (!strcmp(dowhat,"pop")) {
            T item;
            SS_Pop(ss, item);
        }
        else {
            break;
        }
    }
    int length = SS_Length(ss);
    printf("Stack length: %d\n", length);

    SS_Print(ss);
    getchar();
    SS_Free(ss);
    
}
