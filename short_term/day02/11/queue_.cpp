//
//  queue_.cpp
//  Queue
//
//  Created by ljpc on 2018/5/29.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include "queue_.h"


void creatQueue(Queue* que, int maxSize)
//  创建一个循环队列指针que，队列最大长度为maxSize
{
    que->maxSize = maxSize;
    que->data = (int*)malloc(maxSize * sizeof(int));
    que->front = que->rear = 0;
}

void destroyQueue(Queue* que)
//  释放队列内存空间
{
    free(que->data);
}

bool isFull(Queue* que)
//  判断队列que是否为满
//  若满返回 true 并在一行打印 The queue is Full 末尾换行！！！
//  否则返回 false

{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(((que->rear+1)%que->maxSize)==que->front){
        printf("The queue is Full\n");
    }
    return ((que->rear+1)%que->maxSize)==que->front;

    /********** End **********/
}

bool isEmpty(Queue* que)
//  判断队列que是否为空
//  若空返回 true 并在一行打印 The queue is Empty 末尾换行！！！
//  否则返回 false
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(que->front==que->rear){
        printf("The queue is Empty\n");
    }
    return que->front==que->rear;

    /********** End **********/
}

int enQueue(Queue* que, int item)
//  实现入队操作：将元素item加入队列que尾部
//  若队列没满，编写加入操作，返回 1
//  若队列满了，不做任何操作，返回 -1
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(isFull(que)){
        return -1;
    }
    que->data[que->rear]=item;
    que->rear++;
    que->rear%=que->maxSize;
    return 1;
    /********** End **********/
}

int deQueue(Queue* que)
//  实现出队操作：移除队列que首部元素，并返回元素值
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(isEmpty(que)){
        return -1;
    }
    int re=que->data[que->front];
    que->front++;
    que->front%=que->maxSize;
    return re;

    /********** End **********/
}

void printQueue(Queue* que)
//  打印队列
{
    while (isEmpty(que)==false) {
        int item = deQueue(que);
        printf("%d ", item);
    }
}
