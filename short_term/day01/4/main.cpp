#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
#pragma warning(disable:4996)
int main()
{
    //创建一个线性表
    LinkList* llist=LL_Create();
    //向线性表中插入a个数据元素
    int i;
    int x;
    int a;
    scanf("%d", &a);
    for(i=0; i<a; i++) {
        scanf("%d",&x);
        LL_InsAfter(llist,x);
    }
    LL_Print(llist); 
    //设置线性表当前位置为0
    LL_SetPosition(llist, 0);
    //在线性表表头顺序插入a个元素
    scanf("%d", &a);
    for(i=0; i<a; i++) {
        scanf("%d", &x);
        LL_SetPosition(llist,0);
        LL_InsAfter(llist,x);
    }
    //删除线性表中第一个值为x的元素节点
    LL_Print(llist);
    scanf("%d", &x);
    LL_DelValue(llist, x);
    //设置当前位置为i，并删除该位置的元素节点
    scanf("%d", &i);
    LL_SetPosition(llist, i);
    LL_DelAt(llist);
    //打印整个线性表然后释放线性表空间
    LL_Print(llist);
    system("PAUSE");
    LL_Free(llist);
}