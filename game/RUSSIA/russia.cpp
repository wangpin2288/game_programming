#ifndef RUSSIA_CPP
#define RUSSIA_CPP

#include <stdio.h>
#include <iostream>
#include <time.h>
#include "coordinate.cpp"
#include "TerminalControl.cpp"
using namespace std;

#define SPEED 700
#define LENGTH 15
#define HEIGHT 20
#define true 1
#define false 0
#define max_H 5

#define DOWN 0
#define LEFT 1
#define RIGHT 2

Coordinate COOR1(1,0);
Coordinate COOR2(0,-1);
Coordinate COOR3(0,1);
const Coordinate slide[3]={COOR1,COOR2,COOR3};

class Russia{
public:
   Russia();
   virtual ~Russia(){};
   void DrawWill();//随机产生下一个方块
   bool LineFull(int n);//判断行满
   bool DeleteLine(int n);//删除行操作
   bool Move(int x,int y,int pose);//移动坐标操作
   bool moveDown();
   bool moveRight();
   bool moveLeft();
   void drawWall();
   void drawNow();//绘制当前方块
   void eraseNow();//擦除当前方块
   bool isWall(int x,int y);//判断是否遇到墙
   bool isWall();//判断当前方块是否碰到墙
   bool Turn();//顺时针旋转当前方块90度
   bool inBottom();//判断当前方块是否接触到下面的方块
   bool Over();//游戏结束
  
   int Will[4][4];//产生的下一个方块数组
   int After[4][4];//上一个方块数组
   int Now[4][4];//当前方块数组
   int All[30][30];//所有出现的方块数组

  
   int min_X();//当前方块的最小横坐标
   int min_Y();//当前方块的最小纵坐标
   int max_X();//当前方块的最大横坐标
   int max_Y();//当前方块的最大纵坐标
   int Pose;//控制方块运动的方向
   Coordinate pos;//当前方块的左上角位置的坐标

   int Score;

};

Russia::Russia():Pose(DOWN),pos(1,5),Score(0)//构造函数
{
   for(int i=0;i<4;i++)
      for(int j=0;j<4;j++)
      {
        Now[i][j]=0;
        Will[i][j]=0;
        After[i][j]=0;
      }
  
   for(int l=0;l<30;l++)
      for(int m=0;m<30;m++)
      {
        All[l][m]=0;
      }

   drawWall();
   DrawWill();
}


void Russia::DrawWill()//随机产生下一个方块
{  

   for(int i=0;i<4;i++)
     for(int j=0;j<4;j++)
     {
        Will[i][j]=0;
     } 
//产生一个0～6之间的随机数，用于选择方块的种类
   srand(time(NULL));
   int N=rand()%7;

//设定方块的7种类型
   switch(N){
    case 0:
         Will[0][0]=1;
         Will[0][1]=1;
         Will[1][0]=1;
         Will[1][1]=1;
         break;
    case 1:
         Will[0][0]=1;
         Will[0][1]=1;
         Will[0][2]=1;
         Will[1][1]=1;
         break;
    case 2:
         Will[0][0]=1;
         Will[0][1]=1;
         Will[0][2]=1;
         Will[1][0]=1;
         Will[2][0]=1;
         break;
    case 3:
         Will[0][1]=1;
         Will[1][0]=1;
         Will[1][1]=1;
         Will[1][2]=1;
         Will[2][0]=1;
         break;
    case 4:
         Will[0][1]=1;
         Will[1][0]=1;
         Will[1][1]=1;
         Will[1][2]=1;
         Will[2][1]=1;
         break;
    case 5:
         Will[0][2]=1;
         Will[1][0]=1;
         Will[1][1]=1;
         Will[1][2]=1;
         Will[2][0]=1;
         break;
    case 6:
         Will[0][1]=1;
         Will[1][1]=1;
         Will[2][1]=1;
         Will[3][1]=1;
         break;
    default:
         break;
  }

   pos.X=1;
   pos.Y=5;
   for(int i=0;i<4;i++)
     for(int j=0;j<4;j++)
     {
        Now[i][j]=Will[i][j];
        All[pos.X+i][pos.Y+j]=Now[i][j];
     } 
   
   drawNow();
}


bool Russia::LineFull(int n)//判断第n行是否积满（从第0行开始）
{
   for(int i=1;i<LENGTH-1;i++)
   {
      if(All[n][i]==0) return false;
      else continue;
   }
   return true;
}   

bool Russia::DeleteLine(int n)//删除行操作
{
   if(!LineFull(n)) return false;
   for(int i=1;i<LENGTH-1;i++){
      draw(n+1,i+1,' ');
      All[n][i]=0;
   }
 
   for(int i=n-1;i>0;i--)
    for(int j=1;j<LENGTH-1;j++)
    {
      if(All[i][j]==1&&Now[i-pos.X][j-pos.Y]==0){
         draw(i+2,j+1,'#');
         draw(i+1,j+1,' ');
         All[i+1][j]=1;
         All[i][j]=0;
      }
    }
   Score+=100;
   return true;

} 
 


void Russia::drawWall()
{
   clean();
   for(int i=0;i<LENGTH;i++){
       draw(1,i+1,'*');
       draw(HEIGHT,i+1,'*');
       All[0][i]=1;
       All[HEIGHT-1][i]=1;
    }

   for(int j=1;j<HEIGHT-1;j++){
       draw(j+1,1,'*');
       draw(j+1,LENGTH,'*');
       All[j][0]=1;
       All[j][LENGTH-1]=1;
   }

}
  

  

void Russia::drawNow()//绘制当前方块 
{
   for(int i=0;i<4;i++)
    for(int j=0;j<4;j++){
      if(Now[i][j]==1) draw(pos.X+i+1,pos.Y+j+1,'#');
   }
}


void Russia::eraseNow()
{
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++){
      if(Now[i][j]==1) draw(pos.X+i+1,pos.Y+j+1,' ');
   }

}


bool Russia::isWall(int x,int y)//判断是否遇到墙
{
   if(x<=0||x>=HEIGHT-1||y<=0||y>=LENGTH-1) return true;
   else return false;
}


bool Russia::isWall()//判断当前方块是否碰到墙
{
   if(min_X()<=0||min_Y()<=0||max_X()>=HEIGHT-1||max_Y()>=LENGTH-1)
       return true;
   else 
       return false;
}

   
bool Russia::Turn()//旋转
{  
   
    int temp[4][4];
    for(int i=0;i<4;i++)
     for(int j=0;j<4;j++){
         temp[i][j]=Now[i][j];
         Now[i][j]=0;    
    }
   
    for(int i=0;i<4;i++)
     for(int j=0;j<4;j++){
         Now[i][j]=temp[3-j][3-i]; 
         All[pos.X+i][pos.Y+j]=Now[i][j];  
    }

if(isWall())
{
    for(int i=0;i<4;i++)
     for(int j=0;j<4;j++){
         Now[i][j]=temp[i][j]; 
         All[pos.X+i][pos.Y+j]=Now[i][j];  
    }
    return false;
}

  for(int i=0;i<4;i++)
     for(int j=0;j<4;j++){
         Now[i][j]=temp[i][j]; 
         All[pos.X+i][pos.Y+j]=Now[i][j];  
    }
  eraseNow();

  for(int i=0;i<4;i++)
     for(int j=0;j<4;j++){
         Now[i][j]=temp[3-j][3-i]; 
         All[pos.X+i][pos.Y+j]=Now[i][j];  
    }
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      if(Now[i][j]==1) draw(pos.X+i+1,pos.Y+j+1,'#');
    }
  }
  return true;
}
 


bool Russia::inBottom()//判断当前方块是否接触到下面的方块
{
   if(max_X()==(HEIGHT-2)) return true;
   for(int i=0;i<4;i++)
     for(int j=0;j<4;j++){
      if(Now[i][j]==1&&Now[i+1][j]==0&&All[pos.X+i+1][pos.Y+j]==1) return true;
   }
   return false;
}
   
bool Russia::Over()//游戏结束
{
   for(int i=1;i<LENGTH-1;i++)
    {
       if(All[max_H-1][i]==1&&inBottom())
         {
           return true;
         }
    }
   return false;
}

 
int Russia::min_X()
{
   int l=4;
   for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    {
       if(Now[i][j]==1&&i<l) l=i;
    }
   l+=pos.X;
   return l;
}
   
int Russia::min_Y()
{
   int l=4;
   for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    {
       if(Now[i][j]==1&&j<l) l=j;
    }
   l+=pos.Y;
   return l;
}
   

int Russia::max_X()
{
   int l=0;
   for(int i=0;i<4;i++){
    for(int j=0;j<4;j++)
    {
       if(Now[i][j]==1&&i>l) l=i;
    }
   }

   l+=pos.X;
   return l;

}
   

int Russia::max_Y()
{
   int l=0;
   for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    {
       if(Now[i][j]==1&&j>l) l=j;
    }
   l+=pos.Y;
   return l;
}


bool Russia::Move(int x,int y,int pose)//移动坐标操作
{
   Coordinate coor(x,y);  
   coor+=slide[pose];
   if(Now[x-pos.X][y-pos.Y]==1)//只移动有填充的地方
   {
     if(All[coor.X][coor.Y]==1) return false;
     else{
       draw(coor.X+1,coor.Y+1,'#');
       draw(x+1,y+1,' ');
       All[coor.X][coor.Y]=1;
       All[x][y]=0;
        }
    }
   return true;
}

bool Russia::moveDown()
{
  for(int i=3;i>=0;i--)
    for(int j=0;j<4;j++){
      Move(pos.X+i,pos.Y+j,DOWN);
   }
   pos+=slide[DOWN];
   usleep(SPEED);
  return true;
}

bool Russia::moveRight()
{
  if(isWall()) return false;

   for(int i=3;i>=0;i--)
    for(int j=0;j<4;j++){
      Move(pos.X+j,pos.Y+i,RIGHT);
   }
   pos+=slide[RIGHT];
   usleep(SPEED);

   return true;
}

bool Russia::moveLeft()
{
  if(isWall()) return false;

   for(int i=0;i<4;i++)
    for(int j=0;j<4;j++){
      Move(pos.X+j,pos.Y+i,LEFT);
   }
  pos+=slide[LEFT];
  usleep(SPEED);

  return true;
}

#endif


