//
//  queue_.h
//  Queue
//
//  Created by ljpc on 2018/5/29.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#ifndef queue__h
#define queue__h

#include <iostream>

struct Queue{
    int maxSize;    //  队列最大长度
    int *data;      //  数据指针
    int front;      //  头指针索引
    int rear;       //  尾指针索引
    Queue(){data=NULL;}
};

void creatQueue(Queue* que, int maxSize);
//  创建一个循环队列指针que，队列最大长度为maxSize

void destroyQueue(Queue* que);
//  释放队列内存空间

bool isFull(Queue* que);
//  判断队列que是否为满
//  若满返回 true 并在一行打印 The queue is Full 末尾换行！！！
//  否则返回 false

bool isEmpty(Queue* que);
//  判断队列que是否为空
//  若空返回 true 并在一行打印 The queue is Empty 末尾换行！！！
//  否则返回 false

int enQueue(Queue* que, int item);
//  实现入队操作：将元素item加入队列que尾部
//  若队列没满，编写加入操作，返回 1
//  若队列满了，不做任何操作，返回 -1

int deQueue(Queue* que);
//  实现出队操作：移除队列que首部元素，并返回元素值

void printQueue(Queue* que);
//  打印队列

#endif /* queue__h */
