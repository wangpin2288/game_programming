#include <stdlib.h>
#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;
#ifndef Public_H_
#define Public_H_
#define screenHeight 25
#define screenWidth 80
#define bool int
#define TRUE 1
#define FALSE 0
#define YES 1
#define NO 0
#endif
#include <stdio.h>

enum objectiveDirections
{
   SOUTH,NORTH,WEST,EAST
};

/*
构造迷宫类
*/


class MazeMap
{
public:
   MazeMap(int *mazeMap,int row,int column);//*mazeMap地图二位数组首地址,row行
   void setMazeMap(int *mazeMap,int row,int column);
   void setMazeWall(char wall);
   void setMazeRoad(char road);
   void defaultMode();  //设置迷宫的默认地图
   void drawMap() const;  //声明绘制迷宫地图的函数
   char getRoadChar();
   bool checkWallOrNot(int mazeX,int mazeY);
//检查是否遇到墙壁的函数
   bool checkMazeDoor(int mazeX,int mazeY);
                                    //检查是否遇到迷宫出口/入口的函数
private:
   char mazeWall;  //声明迷宫表示墙壁的字符
   char mazeRoad;   //声明迷宫表示通路堆字符
   int mazeWidth;   //声明迷宫宽度
   int mazeHeight;   //声明迷宫高度
   int mazeMapArray[screenHeight][screenWidth]; 
//声明迷宫的地图数组
};

MazeMap::MazeMap(int *mazeMap,int row,int column)
{  
   mazeWidth=column;
   mazeHeight=row;
   for(int i=0;i<row;i++)
   {
      for(int j=0;j<column;j++)
         {
             mazeMapArray[i][j]=*mazeMap;
             mazeMap++;
         };
   };
}

void::MazeMap::setMazeMap(int *mazeMap,int row,int column)
{
   mazeWidth=column;
   mazeHeight=row;
   for(int i=0;i<row;i++)
{
   for(int j=0;j<column;j++)
{
   mazeMapArray[i][j]=*mazeMap;
   mazeMap++;
};
};

}

void MazeMap::setMazeWall(char wall)
{
   mazeWall=wall;
}

void MazeMap::setMazeRoad(char road)
{
   mazeRoad=road;
}

void MazeMap::defaultMode()
{
    int mazeMap[6][6]={
             {1,1,1,1,1,1},
             {1,1,1,1,0,0},
             {1,1,1,1,0,1},
             {1,0,0,0,0,1},
             {1,0,1,1,0,1},
             {1,0,1,1,1,1}}; 
   setMazeMap(&mazeMap[0][0],6,6);
}

void MazeMap::drawMap() const
{
   for(int i=0;i<mazeHeight;i++)
   {
     for(int j=0;j<mazeWidth;j++)
     {
        if(mazeMapArray[i][j]==1) cout<<mazeWall;
        else cout<<mazeRoad;
     };
     cout<<endl;
   };
}

char MazeMap::getRoadChar()
{
    return mazeRoad;
}

bool MazeMap::checkWallOrNot(int mazeX,int mazeY)
{
    if(mazeMapArray[mazeY][mazeX]==1) return TRUE;
    else return FALSE;
}

bool MazeMap::checkMazeDoor(int mazeX,int mazeY)
{
   if((mazeX==0||mazeX==mazeWidth-1)&&mazeMapArray[mazeY][mazeX]==0)
      return TRUE;
   else if((mazeY==0||mazeY==mazeHeight-1)&&mazeMapArray[mazeY][mazeX]==0)
      return TRUE;
      else return FALSE;
}











/*
构造走迷宫的人的类
*/


class MazePerson
{
public:
   MazePerson(int currentX,int currentY,objectiveDirections myForward);
   void setPersonPos(int coordX,int coordY);
   void setPersonPic(char personChar);
   void setPersonForwardDirection(objectiveDirections myForward);
   void setPersonSpeed(long speed);
   void setPersonSpeed(int speed);
   void start();//声明人开始运动的方法
   MazeMap getMap();
private:
   int preX;  //声明前一个横坐标
   int preY;
   int positionX;  //声明当前横坐标
   int positionY;
   int personSpeed;
   char personPic;
   bool outOrNot;
   objectiveDirections forward;  //声明逻辑的前方
   MazeMap *map;
   void savePrePosition();
   void moveSouth();
   void moveNorth();
   void moveWest();
   void moveEast();
   void moveAhead(); //沿着当前方向向前走的方法
   void turnLeft();
   void turnRight();
   bool moveForward();//可以进行主观判断如何前进的方法
   void gotoxy(int x,int y)//光标定位函数
      {
         printf("%c[%d;%df",0x1B,y,x);
       };
   void drawPerson();//绘制走迷宫者的行走动画的方法   
};

MazePerson::MazePerson(int currentX,int currentY,objectiveDirections myForward)
{
   positionX=currentX;
   positionY=currentY;
   forward=myForward;
}

void MazePerson::setPersonPos(int coordX,int coordY)
{
   positionX=coordX;
   positionY=coordY;
}

void MazePerson::setPersonPic(char personChar)
{
   personPic=personChar;
}

void MazePerson::setPersonForwardDirection(objectiveDirections myForward)
{
   forward=myForward;
}

void MazePerson::setPersonSpeed(long speed)
{
   personSpeed=speed;
}

void MazePerson::setPersonSpeed(int speed)
{
   personSpeed=speed;
}


MazeMap MazePerson::getMap()
{
   return *map;
}

   void MazePerson::savePrePosition()
   {
      preX=positionX;
      preY=positionY;
   }


   void MazePerson::moveSouth()
   {
      positionX=positionX;
      positionY=positionY+1;
   }   


   void MazePerson::moveNorth()
   {
      positionX=positionX;
      positionY=positionY-1;
   }

   
   void MazePerson::moveWest()
   {
       positionY=positionY;
       positionX=positionX-1;

   }

   void MazePerson::moveEast()
   {
       positionY=positionY;
       positionX=positionX+1;

   }

   void MazePerson::moveAhead()//沿着当前方向向前走的方法
   {
       switch(forward){
          case NORTH:
            positionX=positionX;
            positionY=positionY-1;
            break;
          case WEST:
            positionY=positionY;
            positionX=positionX-1;
            break;
          case SOUTH:
            positionX=positionX;
            positionY=positionY+1;
            break;
          case EAST:
            positionY=positionY;
            positionX=positionX+1;
            break;
          default:
            cout<<"方向错误"<<endl;
          };

      drawPerson();
      if(getMap().checkMazeDoor(positionX,positionY))
     {
        gotoxy(0,22);
        cout<<"哈哈，终于出来啦！"<<endl;
        outOrNot=TRUE;
      };

   }




   void MazePerson::turnLeft()
   {
       switch(forward){
          case NORTH:
               forward=WEST;
               break;
          case WEST:
               forward=SOUTH;
               break;
          case SOUTH:
               forward=EAST;
               break;
          case EAST:
               forward=NORTH;
               break;
          default:
            cout<<"方向错误"<<endl;
          };

   }

   void MazePerson::turnRight()

   {
       switch(forward){
          case NORTH:
               forward=EAST;
               break;
          case WEST:
               forward=NORTH;
               break;
          case SOUTH:
               forward=WEST;
               break;
          case EAST:
               forward=SOUTH;
               break;
          default:
            cout<<"方向错误"<<endl;
          };

   }

   bool MazePerson::moveForward()//可以进行主观判断如何前进的方法
   {

 //检查当前位置是否合法
      if(getMap().checkWallOrNot(positionX,positionY))
      {
         //检测到当前位置是墙，提示用户设计非法并返回
         gotoxy(0,5);
         cout<<"检测到当前设定的起始位置是墙壁，请重新设定"<<endl;
         outOrNot=true;
         return NO;
        }

//判断如果前一个位置的坐标是10000，则直接在当前位置绘制人

if(preX==10000||preY==10000)
{
   gotoxy(positionX,positionY);
   cout<<personPic;
   sleep(3);
}

/*
检查右侧是否是墙，如果是墙，检查前方是否是墙，如果不是墙则前进，前进后检查是否是出口
*/
int rightX;
int rightY;

int forwardX;
int forwardY;

switch(forward)
{
  case NORTH:rightX=positionX+1;rightY=positionY;
             forwardX=positionX;forwardY=positionY-1;break;
  case SOUTH:rightX=positionX-1;rightY=positionY;
             forwardX=positionX;forwardY=positionY+1;break;
  case WEST:rightX=positionX;rightY=positionY-1;
             forwardX=positionX-1;forwardY=positionY;break;
  case EAST:rightX=positionX;rightY=positionY+1;
             forwardX=positionX+1;forwardY=positionY;break;
}

if(getMap().checkWallOrNot(rightX,rightY))
{
//检查到右方是墙壁
//检查到前方也是墙壁
    if(getMap().checkWallOrNot(forwardX,forwardY))
    {
       turnLeft();
       return NO;  
    }
 
    else
    {
        moveAhead();
        return YES;
     }
}

else
{
   sleep(3);
   turnRight();
   moveAhead();
   return YES;
}
}

   void MazePerson::drawPerson()//绘制走迷宫者的行走动画的方法
   {    
        //在当前位置上绘制人
        char mazeRoad=getMap().getRoadChar();
        gotoxy(preX,preY);
        cout<<mazeRoad;
        gotoxy(positionX,positionY);
        cout<<personPic;
        //为制作动画效果使用时间延迟
        sleep(personSpeed/1000);
    }




  void MazePerson::start()
{
   int i=0;
   while(!outOrNot)
  {
      gotoxy(1,5);
      cout<<i;
      i++;
      moveForward();
   }
}



//主函数部分
int main(void)
{
    int mapArray[6][6]={
             {1,1,1,1,1,1},
             {1,1,1,1,0,0},
             {1,1,1,1,0,1},
             {1,0,0,0,0,1},
             {1,0,1,1,0,1},
             {1,0,1,1,1,1}};    

     int *mazeMap=&mapArray[0][0];
     MazeMap map(mazeMap,6,6);
     map.setMazeWall('#');
     map.setMazeRoad(' ');
     map.drawMap();

     MazePerson person(1,5,NORTH);
     person.setPersonPic('T');
     person.setPersonSpeed(1);
     person.start();
     
     return 0;
}







   



































