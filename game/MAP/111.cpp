#include <stdlib.h>
#include <iostream>
#include <string>
#define ROW 10
#define COL 10
#define TRUE 1
#define FALSE 0
using namespace std;


void gotoxy(int x,int y)//光标定位函数
{
   printf("\x1b[%d;%df",x+1,y+1);
}


drawPic()//实现人物前进的动画
{
   gotoxy(preX,preY);
   cout<<" ";
   sleep(0.1);
   gotoxy(positionX,positionY);
   cout<<'T';
}
