/*
定义一个迷宫地图的类
*/
#ifndef MAZEMAP_H
#define MAZEMAP_H
#include <stdlib.h>
#define ROW 10
#define COL 10

class mazeMap
{
public:
   mazeMap();
   void setWall(char wall);
   char getWall();
   void setRoad(char road);
   char getRoad();
   void setRow(int row);
   int getRow();
   void setCol(int col);
   int getCol();
   void setMap(int* map,int row,int col);
   void drawMap();
   bool checkDoor(int x,int y);
   bool checkWall(int x,int y);
private:
   char mapWall;
   char mapRoad;
   int mapRow;
   int mapCol;
   int mapArray[ROW][COL];
};

#endif
