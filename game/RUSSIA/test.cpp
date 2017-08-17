#include <stdio.h>
#include <iostream>
#include <time.h>
#include "russia.cpp"
#include "TerminalControl.cpp"
using namespace std;


int main()
{
   Russia russia;
 while(1)
 {
   while(!russia.inBottom())
   {
     russia.moveDown();
     if(russia.Over()) break;
   } 
     if(russia.Over()) break; 
   russia.DrawWill();
   
 }
   draw(1,30,"GAME OVER!");
   return 0;
}





