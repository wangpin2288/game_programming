/*
定义一个走迷宫的人的类
*/
#ifndef MAZEPERSON_H
#define MAZEPERSON_H

#include "mazeMap.h"

#include <stdlib.h>

enum Directions
{NORTH = 0,EAST = 1,SOUTH = 2, WEST = 3};

class mazePerson
{
public:
   mazePerson(char pic,int x,int y,Directions forward, mazeMap *m);
   void setPic(char pic);
   char getPic();
   void setPositionX(int x);
   int getPositionX();
   void setPositionY(int y);
   int getPositionY();
   int getInfrontX();
   int getInfrontY();
   void setDirections(Directions forward);
   Directions getDirections();
   void turnRight();
   void turnLeft();
   void drawPic();//实现人物前进的动画
   void moveAhead();//向前走一步
   void goAhead();//进行主观判断并向前走一步
   
   mazeMap* getMap(){return map;};

   void start();//开始走迷宫
   bool checkOut();//检查是否走出迷宫
   void gotoxy(int x,int y);//光标定位函数
   
private:
   char personPic;//表示人的字符
   int positionX;//当前横坐标
   int positionY;//当前纵坐标
   int preX;//上一刻的横坐标
   int preY;//上一刻的纵坐标
   int infrontX;//所在方向前方的横坐标
   int infrontY;//所在方向前方的纵坐标
   Directions personForward;//当前的方向
   mazeMap *map;
};

#endif

