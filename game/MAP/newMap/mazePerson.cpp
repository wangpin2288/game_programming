
#include <fstream>
#include <cstdio>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "mazePerson.h"
using namespace std;

/*
mazePerson::mazePerson()
{
   personPic='T';
   positionX=10;
   positionY=3;
 preX=10;
  preY=1;
   personForward=NORTH;
//你不初始化你的map让我快要死了T.T
//这里没法默认初始化
//
 if(getMap()->checkWall(positionX,positionY))
     cout<<"初始位置设置错误，请重新设定！"<< flush;

}

*/
mazePerson::mazePerson(char pic,int x,int y,Directions forward, mazeMap* m)
{
   personPic=pic;
   positionX=x;
   positionY=y;
   personForward=forward;
 preX=10;
 preY=1;
//你不初始化你的map让我快要死了T.T
map = m;

 if(getMap()->checkWall(positionX,positionY))
     cout<<"初始位置设置错误，请重新设定！"<<endl;
}

/////////////////////////以上没问题了。。。/////////////////////////////////


void mazePerson::goAhead()//进行主观判断并进行一步
{  
   turnRight();
   if(!getMap()->checkWall(getInfrontX(),getInfrontY()))
	moveAhead();
   else{
        turnLeft();
        if(!getMap()->checkWall(getInfrontX(),getInfrontY()))
            moveAhead();
        else turnLeft();
   };
   
}

void mazePerson::start()//开始走迷宫
{
   drawPic();
   while(!map->checkDoor(positionX,positionY))
   {
   gotoxy(1,15);	cout<<"The person at "<<positionX<<","<<positionY<<" "<<flush;
   gotoxy(2,15);	cout<<"Last at       "<<preX<<","<<preY<<" "<<flush;
       goAhead();
//////////////////////////
      // drawPic();
/////////////////////////
   }
gotoxy(20,25);
   cout<<"success!!"<<endl;
   
}
/////////////////////////以上没问题了。。。/////////////////////////////////
void mazePerson::moveAhead()
{
    switch(personForward){
      case NORTH:
         preX=positionX;
         preY=positionY;
         positionX--;
         drawPic();
         break;
      case SOUTH:
         preX=positionX;
         preY=positionY;
         positionX++;
         drawPic();
         break;
      case WEST: 
         preX=positionX;
         preY=positionY;
         positionY--;
         drawPic();
         break;
      case EAST: 
         preX=positionX;
         preY=positionY;
         positionY++;
         drawPic();
         break;
   };  
}

void mazePerson::drawPic()//实现人物前进的动画
{
   static bool is_first = true;
   if( is_first ){
     gotoxy(positionX,positionY);	cout<<"T";
     is_first = false;
    }
   else{
     gotoxy(preX,preY);			cout<<' ';
     gotoxy(positionX,positionY);	cout<<"T";
   }

   sleep(1);
}

///////////////////////下面没问题了。。。//////////////////////////////////////////////
int mazePerson::getInfrontX()
{
   switch(personForward){
      case NORTH: return positionX-1;
      case SOUTH: return positionX+1;
      case WEST:  return positionX;
      case EAST:  return positionX;
   }
}


int mazePerson::getInfrontY()
{
   switch(personForward){
      case NORTH: return positionY;
      case SOUTH: return positionY;
      case WEST:  return positionY-1;
      case EAST:  return positionY+1;
   }
}

void mazePerson::turnRight()
{
   switch(personForward){
      case NORTH: personForward=EAST;break;
      case SOUTH: personForward=WEST;break;
      case WEST: personForward=NORTH;break;
      case EAST: personForward=SOUTH;break;
   };
}


void mazePerson::turnLeft()
{
   switch(personForward){
      case NORTH: personForward=WEST;break;
      case SOUTH: personForward=EAST;break;
      case WEST: personForward=SOUTH;break;
      case EAST: personForward=NORTH;break;
   };
}

void mazePerson::setDirections(Directions forward)
{
   personForward=forward;
}


Directions mazePerson::getDirections()
{
   return personForward;
}

bool mazePerson::checkOut()//检查是否走出迷宫
{
///////////////////
///你这个错误让我缩短了一年的寿命。
////////////
//实际上你的检查出口程序也没有什么用
//   if(positionX=0&&getMap()->checkDoor(positionX,positionY)) return true;
if(positionX==0 &&
	getMap()->checkDoor(positionX, positionY) )

		return true;
   else return false;
}

void mazePerson::gotoxy(int x,int y)//光标定位函数
{
   printf("\x1b[%d;%df",x,y);
}

void mazePerson::setPic(char pic)
{
    personPic=pic;
}

char mazePerson::getPic()
{
   return personPic;
}

void mazePerson::setPositionX(int x)
{
   positionX=x;
}

int mazePerson::getPositionX()
{
   return positionX;
}

void mazePerson::setPositionY(int y)
{
   positionY=y;
}

int mazePerson::getPositionY()
{
   return positionY;
}
