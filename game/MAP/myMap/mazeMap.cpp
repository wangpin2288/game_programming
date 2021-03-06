//#ifndef MAZEMAP_CPP
//#define MAZEMAP_CPP
#include <stdlib.h>
#include <string>
#include <iostream>
#define TRUE 1
#define FALSE 0
using namespace std;
#include "mazeMap.h"


void gotoxy(int x,int y)//光标定位函数
{
   printf("\x1b[%d;%df",x,y);
}

mazeMap::mazeMap()  //地图的构造函数，初始化地图
{
   mapWall='#';
   mapRoad=' ';
   mapRow=10;
   mapCol=10;
   int Array[10][10]={
                     {1,0,0,1,1,0,0,1,1,0},
                     {0,0,0,0,1,1,1,1,0,0},
                     {0,1,1,1,0,1,1,0,0,1},
                     {1,1,1,1,1,0,0,0,0,1},
                     {1,1,1,0,1,0,1,1,1,1},
                     {0,1,1,1,0,0,0,1,1,1},
                     {1,1,1,1,0,1,1,1,1,1},
                     {0,1,1,0,0,1,1,1,1,1},
                     {0,0,0,0,1,1,1,1,1,1},
                     {0,0,1,1,1,1,1,1,1,1}};
   setMap(&Array[0][0],10,10);
}

void mazeMap::setWall(char wall)//设置地图中的墙壁字符
{
   mapWall=wall;
}

char mazeMap::getWall()
{
   return mapWall;
}

void mazeMap::setRoad(char road)//设置地图中的通路字符
{
   mapRoad=road;
}

char mazeMap::getRoad()
{
   return mapRoad;
}

void mazeMap::setRow(int row)
{
   mapRow=row;
}

int mazeMap::getRow()
{
   return mapRow;
}

void mazeMap::setCol(int col)
{
   mapCol=col;
}

int mazeMap::getCol()
{
   return mapCol;
}

void mazeMap::setMap(int* map,int row,int col)/*自定义地图,*map指向给定的二维数组的首地址*/
{
   mapRow=row;
   mapCol=col;
   for(int i=0;i<row;i++)
     {
       for(int j=0;j<col;j++)
        {
           mapArray[i][j]=*map;
           map++;
         };
      };
}

void mazeMap::drawMap()//根据地图数组绘制地图
{
   for(int i=0;i<getRow();i++)
   {
      for(int j=0;j<getCol();j++)
      {  
         //gotoxy(i+1,j+1);
         if(mapArray[i][j]==0)  cout<<' ';
         else cout<<'#';
       };
       cout<<endl;
   };
}

bool mazeMap::checkDoor(int x,int y)//检查是否是迷宫的出口
{
  if( x == 1 && y == 10) return true;
	if( checkWall(x,y) ) return false;
}

bool mazeMap::checkWall(int x,int y)
{
  x--; y--;
if (x<0||y<0||x>=10||y>=10)
	return TRUE;
if(mapArray[x][y]==1)

///////////////////////////////
//   if(mapArray[y][x]==1) 
        return TRUE;
   else 
        return FALSE;

}

//#endif































