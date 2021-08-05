//
//  queue_.cpp
//  LinkQueue
//
//  Created by ljpc on 2018/5/30.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include "queue_.h"

void creatLinkQueue(LinkQueue* que)
//  创建一个循环队列指针que
{
    que->front = (Node*)malloc(sizeof(Node));
    que->rear = que->front;
    que->rear->next = NULL;
}

bool isEmpty(LinkQueue* que)
//  判断队列que是否为空
//  若空返回 true 并在一行打印 The queue is Empty 末尾换行！！！
//  否则返回 false
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(que->front==que->rear){printf("The queue is Empty\n");}
    return que->front==que->rear;

    /********** End **********/
}

void enQueue(LinkQueue* que, int item)
//  实现入队操作：将元素item加入队列que尾部
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    Node* lq=(Node*)malloc(sizeof(Node));
    que->rear->next=lq;
    lq->data=item;
    que->rear=lq;
    /********** End **********/
}

int deQueue(LinkQueue* que)
//  实现出队操作：移除队列que首部元素，并返回元素值
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(isEmpty(que)){
        return -1;
    }
    if(que->front->next==que->rear){
        que->rear=que->front;
    }
    Node*t=que->front->next;
    int re=t->data;
    que->front->next=t->next;
    free(t);
    return re;
    /********** End **********/
}

void printQueue(LinkQueue* que)
//  打印队列
{
    while (isEmpty(que)==false) {
        int item = deQueue(que);
        printf("%d ", item);
    }
}




