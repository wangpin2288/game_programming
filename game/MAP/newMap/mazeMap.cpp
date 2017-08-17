#include <stdlib.h>
#include <string>
#include <iostream>
#include <cstdio>
#define TRUE 1
#define FALSE 0
using namespace std;
#include "mazeMap.h"


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
/*
反正我服气了。
 for(int i = 0; i < 10; i++)
	 for(int j = 0; j < 10; j++)
		mapArray[i][j] = Array[i][j];
*/
}


void mazeMap::setMap(int* map,int row,int col)//自定义地图,*map指向给定的二维数组的首地址
{

   mapRow=row;
   mapCol=col;
   for(int i=0;i<row;i++)
     {
       for(int j=0;j<col;j++)
        {
//反正我是服了你这犀利的操作，我是真的想哭了。
//你这样随便摆弄指针会出事的。
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
         if(mapArray[i][j]==0)  cout<<' ';
         if(mapArray[i][j]==1)  cout<<'#';
       };
       cout<<endl;
   };
}

bool mazeMap::checkDoor(int x,int y)//检查是否是迷宫的出口
{
/*
//这样检查开始的位置不就是门么。。

if((x*y==0||x==mapCol-1||y==mapRow-1)&&mapArray[x - 1][y - 1]==0)
/////////////////////////////////

//   if((x*y==0||x==mapCol-1||y==mapRow-1)&&mapArray[y][x]==0)
     return TRUE;
   else 
     return FALSE;
*/
//目前我只能这样检查。我的也是固定了出口
	if( x == 1 && y == 10) return true;
	if( checkWall(x,y) ) return false;
}

bool mazeMap::checkWall(int x,int y)
{

//////////////////////////
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

