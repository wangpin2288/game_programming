
#include <iostream>
#include "mazeMap.cpp"
#include "mazePerson.cpp"

#define screenWidth 10
#define screenHeight 10
using namespace std;

void clean(void){
   cout << "\x1b[2J" << flush;
   cout << "\x1b[1;1f"<<flush;
}


int main(void)
{
   clean();
   mazeMap map;
   map.drawMap();
   mazePerson person('T', 10, 2, NORTH, &map);
   person.start();

   return 0;
}

