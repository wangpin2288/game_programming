#include <stdlib.h>
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class mazeMap
{
public:
   mazeMap();
   void drawMap();
private:
   char mapWall;
   char mapRoad;
   int mapRow;
   int mapCol;
   int mapArray[10][10];
};

mazeMap::mazeMap()  //地图的构造函数，初始化地图
{
   //mapWall='#';
   //mapRoad=' ';
   //mapRow=10;
   //mapCol=10;
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
                     {0,0,1,1,1,1,1,1,1,1}
                     };
   
}

void mazeMap::drawMap()//根据地图数组绘制地图
{
   for(int i=0;i<10;i++)
   {
      for(int j=0;j<10;j++)
      {
         if(mapArray[i][j]==0)  cout<<" ";
         else cout<<"#";
       };
       cout<<endl;
   };
}

void gotoxy(int x,int y)//光标定位函数
{
   printf("\x1b[%d;%df",x+3,y+1);
}


void drawPic(int preX,int preY)//实现人物前进的动画
{
   gotoxy(preX,preY);
   cout<<"O";
   sleep(1);
   gotoxy(preX-1,preY);
   cout<<'T';
}

int main(void)
{
   mazeMap map;
   map.drawMap();
   drawPic(10,4);
   return 0;
}
