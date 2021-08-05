//
//  queue_.h
//  LinkQueue
//
//  Created by ljpc on 2018/5/30.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#ifndef queue__h
#define queue__h

#include <iostream>

struct Node             //  数据节点
{
    int data;           //  数据类型
    Node *next;         //  指向下一个节点的指针
};

struct LinkQueue    //  链表队列
{
    Node *front;    //  头指针
    Node *rear;     //  尾指针
};

void creatLinkQueue(LinkQueue* que);
//  创建一个循环队列指针que

bool isEmpty(LinkQueue* que);
//  判断队列que是否为空
//  若空返回 true 并在一行打印 The queue is Empty 末尾换行！！！
//  否则返回 false

void enQueue(LinkQueue* que, int item);
//  实现入队操作：将元素item加入队列que尾部

int deQueue(LinkQueue* que);
//  实现出队操作：移除队列que首部元素，并返回元素值

void printQueue(LinkQueue* que);
//  打印队列

#endif /* queue__h */
