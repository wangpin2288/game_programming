#ifndef SNAKE_HPP
#define SNAKE_HPP
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "list.hpp"
#include "TerminalControl.hpp"
using namespace std;

#define HEIGHT 40
#define LENGTH 80
#define true 1
#define false 0

#define UP    0
#define RIGHT 1
#define DOWN  2
#define LEFT  3

Coordinate COOR1(-1,0);
Coordinate COOR2(0,1);
Coordinate COOR3(1,0);
Coordinate COOR4(0,-1);
static Coordinate slide[4]={COOR1,COOR2,COOR3,COOR4};

/***************************************************/
//定义蛇的类

class Snake
{
public:
   Snake();
   bool grow();//蛇头向前运动一步
   bool step();//蛇尾向前运动一步
   Coordinate& head();//蛇头位置坐标
   Coordinate& tail();//蛇尾位置坐标
   Coordinate front();//蛇运动的前方坐标
   bool goDead(Coordinate& coor);
   int length(){return s.len();};
   bool changePose(int n);
   bool inBody(Coordinate& coor);
   bool Alive(){return alive;};
private:
   list s;
   bool alive;
   int pose;
};

Snake::Snake():s(),alive(true),pose(RIGHT)
{
   s.push(5,5);
   draw(5,5,'@',true);
   grow();grow();grow();grow();
}
 
bool Snake::grow()
{   
   Coordinate hh(head());
   hh+=slide[pose];
   if(goDead(hh)) return false;
   draw(head(),'o');
   draw(hh,'@');
   s.push(hh);
   return true;
}

bool Snake::step()
{
   if(!grow()) return false;
   draw(tail(),' ');
   s.pop();
   return true;
}
 
Coordinate& Snake::head()
{
   return s.readHead();
}
   
Coordinate& Snake::tail()
{
   return s.readTail();
}
   
Coordinate Snake::front()
{
   Coordinate coor(head());
   coor+=slide[pose];
   return coor;
}

bool Snake::goDead(Coordinate& coor)
{
   if(coor.X<=1||coor.X>=HEIGHT||coor.Y<=1||coor.Y>=LENGTH||inBody(coor)) 
   {
      alive=false;
      return true;
   }    

   else 
   {
      alive=true;
      return false;
   }
}


bool Snake::changePose(int n)
{
   if(n==(pose+3)%4) {
     pose=n;
     return true;}
   if(n==(pose+1)%4){
     pose=n;
     return true;
   }
   else 
     return false;
}

bool Snake::inBody(Coordinate& coor)
{
   return s.checkIn(coor);
}





/*****************************************************/
//定义食物的类
class food{
 public:
   food(Snake& r):pos(5,20),s(r){draw(pos,'*');}
   void another(){
      srand(time(NULL));
      pos.X=rand()%(HEIGHT-3)+2;
      pos.Y=rand()%(LENGTH-3)+2;

      if(s.inBody(pos)) another();
      else draw(pos,'*'); 
   }
  
   bool willBeEaten(){
     if(s.front()==pos) return true;
     else return false;
   }
public:
   Coordinate pos;
   Snake& s;

};


#endif
