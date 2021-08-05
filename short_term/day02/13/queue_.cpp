//
//  queue_.cpp
//  Cycle
//
//  Created by ljpc on 2018/5/30.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include "queue_.h"


void creatCycleQueue(CycleQueue* que)
//  创建一个循环队列指针que
{
    que->size_ = 0;
    que->rear = NULL;
}

bool isEmpty(CycleQueue* que)
//  判断队列que是否为空
//  若空返回 true 并在一行打印 The queue is Empty 末尾换行！！！
//  否则返回 false
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    bool is=que->size_==0;
    if(is){
        printf("The queue is Empty\n");
    }
    return is;

    /********** End **********/

}

void enQueue(CycleQueue* que, int item)
//  实现入队操作：将元素item加入队列que尾部
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=item;
    if(!que->rear){
        que->rear=n;
        n->next=n;
    }else{
        n->next=que->rear->next;
        que->rear->next=n;
        que->rear=n;
    }
    que->size_++;
    /********** End **********/

}

int deQueue(CycleQueue* que)
//  实现出队操作：移除队列que首部元素，并返回元素值
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(isEmpty(que)){
        return -1;
    }
    int re;
    if(que->rear->next==que->rear){
        re=que->rear->data;
        free(que->rear);
        que->rear=nullptr;
    }else{
        re=que->rear->next->data;
        Node* t=que->rear->next;
        que->rear->next=que->rear->next->next;
        free(t);
    }
    que->size_--;
    return re;
    /********** End **********/

}

void printQueue(CycleQueue* que)
//  打印队列
{
    while (isEmpty(que)==false) {
        int item = deQueue(que);
        printf("%d ", item);
    }
}
