#pragma once
#ifndef __BASE_H__
#define __BASE_H__
#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<string>
#include<time.h>
enum block_dir_t { up = 0, down = 1, left =2, right = 3 };
enum { mapsize = 20 };
class Base
{
protected:
    int score;   //����
    int map[22][12] ;
    int index;  //��ǰͼ�����
    int nextindex;//��һ��ͼ�����
    int dir; //����
    int level;
   public:
       Base();
       virtual void show();
       void Showscore();
      
};

#endif
