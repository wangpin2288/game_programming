#include <stdlib.h>
#include <string>
#include <iostream>
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
   int mapArray[10][10]={
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

//cout<< "Wall: " << mapWall << "Road: " << mapRoad << "Row,Col: "<<mapRow <<',' << mapCol<<endl; 
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

void mazeMap::setMap(int *map,int row,int col)/*自定义地图,*map指向给定的二维数组的首地址*/
{
   mapRow=row;
   mapCol=col;
   for(int i=0;i<row;i++)
     {
       for(int j=0;j<col;j++)
        {
	if(i >= mapCol || j >= mapRow
	 	|| i < 0 || j < 0 )
		cerr << "HAHA" << endl;

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
	if(i >= mapCol || i >= mapRow
	 	|| i < 0 || j < 0 )
		cerr << "HAHA" << endl;

         if(mapArray[i][j]==0)  cout<<"#";
         else cout<<" ";
       };
       cout<<endl;
   };
}

bool mazeMap::checkDoor(int x,int y)//检查是否是迷宫的出口
{
	if(y >= mapCol || x >= mapRow
	 	|| x < 0 || y < 0 )
		cerr << "HAHA" << endl;

   if((x*y==0||y==mapCol-1||x==mapRow-1)&&mapArray[x][y]==0)
     return TRUE;
   else 
     return FALSE;
}

bool mazeMap::checkWall(int x,int y)
{
	if(y >= mapCol || x >= mapRow
	 	|| x < 0 || y < 0 )
		cerr << "HAHA" << endl;

   if(mapArray[x][y]==1) 
        return TRUE;
   else 
        return FALSE;

}
































