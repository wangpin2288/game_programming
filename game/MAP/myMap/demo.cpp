#include <stdlib.h>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <string>
#include "mazeMap.cpp"
#include "mazePerson.cpp"
#define screenWidth 10
#define screenHeight 10
using namespace std;

void clean(void){
   cout << "\x1b[2J" << flush;
   cout<<"\x1b[1;1f"<<flush;
}


int main(void)
{
   clean();
   //gotoxy(1,1);
   mazeMap map;
   map.drawMap();
   mazePerson person('T',10,2,NORTH,&map);
   person.start();

   return 0;
}

