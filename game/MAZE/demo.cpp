#include <stdlib.h>
#include <iostream>
#include <string>

#include "mazeMap.cpp"
#include "mazePerson.cpp"

#define screenWidth 10
#define screenHeight 10
using namespace std;

void clear(void){
	cout << "\x1b[2J" << flush;
}

void gotoxy(int x,int y)//光标定位函数
{
   cout << "\x1b["<< x << ";" << y << "f" << flush;
}

int main( int argc, char **argv )
{
	clear();
	gotoxy(1,1);
   mazeMap map;
   map.drawMap();

  mazePerson person('T',1,10,NORTH);
  person.start();
//	clear();
	return 0;
}

