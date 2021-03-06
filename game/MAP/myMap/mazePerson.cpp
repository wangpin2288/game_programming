//#ifndef MAZEPERSON_CPP
//#define MAZEPERSON_CPP
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
   preY=3;
   personForward=NORTH;

 if(getMap()->checkWall(positionX,positionY))
     cout<<"初始位置设置错误，请重新设定！"<<endl;
     gotoxy(1,15);
     cout<<"The person at "<<positionX<<","<<positionY<<endl;
}
*/
mazePerson::mazePerson(char pic,int x,int y,Directions forward,mazeMap *m)
{
   personPic=pic;
   positionX=x;
   positionY=y;
   personForward=forward;
   preX=10;
   preY=3;
   map=m;

 if(getMap()->checkWall(positionX,positionY))
     cout<<"初始位置设置错误，请重新设定！"<<endl;
   gotoxy(1,15);
   cout<<"The person at "<<positionX<<","<<positionY<<endl;
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


int mazePerson::getInfrontX()
{
 if(0<positionX<9&&0<positionY<9)
 {   switch(personForward){
      case NORTH:
         return positionX-1;
         break;
      case SOUTH:
         return positionX+1;
         break;
      case WEST: 
         return positionX;
         break;
      case EAST: 
         return positionX;
         break;}
      //default: cout<<"方向错误！"<<endl;break;}
  }
 else cout<<"SUCCESS!"<<endl;
}


int mazePerson::getInfrontY()
{
if(0<positionX<9&&0<positionY<9)
 {   switch(personForward){
      case NORTH:
         return positionY;
         break;
      case SOUTH:
         return positionY;
         break;
      case WEST: 
         return positionY-1;
         break;
      case EAST: 
         return positionY+1;
         break;}
      //default: cout<<"方向错误！"<<endl;break;}
}
else cout<<"SUCCESS!"<<endl;
}



void mazePerson::setDirections(Directions forward)
{
   personForward=forward;
}


Directions mazePerson::getDirections()
{
   return personForward;
}


void mazePerson::turnRight()
{
   switch(personForward){
      case NORTH: personForward=EAST;break;
      case SOUTH: personForward=WEST;break;
      case WEST: personForward=NORTH;break;
      case EAST: personForward=SOUTH;break;
      //default: cout<<"方向错误！"<<endl;break;
   };    
}


void mazePerson::turnLeft()
{
   switch(personForward){
      case NORTH: personForward=WEST;break;
      case SOUTH: personForward=EAST;break;
      case WEST: personForward=SOUTH;break;
      case EAST: personForward=NORTH;break;
      //default: cout<<"方向错误！"<<endl;break;
   };    
}


void mazePerson::drawPic()//实现人物前进的动画
{
   static int count=0;
   gotoxy(3,15);
   cout<<"count of drawPic: "<<count<<endl;
   if(count==0){
     gotoxy(positionX,positionY);
     cout<<"T"<<endl;
     count++;
    }
   else{
     count++;
     gotoxy(preX,preY);
     cout<<' ';
     gotoxy(positionX,positionY);
     cout<<"T";
     sleep(2);}
}

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
      //default: cout<<"方向错误！"<<endl;break;
   };   
}


void mazePerson::goAhead()//进行主观判断并进行一步
{  
   turnRight();
   if(!getMap()->checkWall(getInfrontX(),getInfrontY()))
     {moveAhead();}
   else 
     {
        turnLeft();
        if(!getMap()->checkWall(getInfrontX(),getInfrontY()))
          {
            moveAhead();
          }
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


bool mazePerson::checkOut()//检查是否走出迷宫
{
   if(positionX==0&&getMap()->checkDoor(positionX,positionY)) return TRUE;
   else return FALSE;
}

void mazePerson::gotoxy(int x,int y)//光标定位函数
{
   printf("\x1b[%d;%df",x,y);
}

//#endif
