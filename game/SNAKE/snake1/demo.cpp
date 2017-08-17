#include <iostream>
#include <string>
#include <stdio.h>
#include <pthread.h>
#include "snake.hpp"
#include "TerminalControl.hpp"

using namespace std;


int SPEED=700;
static long long int step=0;
bool Exit=false;
Snake snake1;
food f(snake1);


void* listen_key(void* arg)
{
   static char key='\0';
   while(1){
       key=getch();
       switch(key){
          case 'w': snake1.changePose(UP);   break;
          case 'd': snake1.changePose(RIGHT);break;
          case 's': snake1.changePose(DOWN); break;
          case 'a': snake1.changePose(LEFT); break;
          case '\27':Exit=true;              break;
      }
      usleep(SPEED);
      if(Exit) break;
   }

   pthread_exit(0);
}


void drawMap()
{
 static bool first=true;
 if(first){ 
  for(int i=1;i<=LENGTH;i++)
  {
     draw(1,i,'#');
     draw(HEIGHT,i,'#');
  }

  for(int j=2;j<HEIGHT;j++)
  {
     draw(j,1,'#');
     draw(j,LENGTH,'#');
  }
  draw(1,85,"food at: ");
  draw(2,85,"head at: ");
  draw(3,85,"length is: ");
  draw(10,85,"step: ");
  first=false;
 }

  draw(1,95,f.pos.X);cout<<",";draw(1,100,f.pos.Y);
  draw(2,95,snake1.head().Y);cout<<",";draw(2,100,snake1.head().Y);
  draw(3,100,snake1.length());
  draw(10,100,step);
}

int main()
{
  pthread_t tid;
  pthread_create(&tid,NULL,listen_key,NULL);

  drawMap();
   while(1){
     if(f.willBeEaten()){
      snake1.grow();
      f.another();
     }
      
     else snake1.step();

     if(!snake1.Alive()){
        draw(20,90,"your snake is dead!");
        draw(21,90,"any key to exit!");
        Exit=true;
        break;
     }

     drawMap();
     usleep(SPEED);
     step++; 
   } 

  pthread_join(tid, NULL);
  getch();
  draw(22,90,"Game Over!", true); cout << endl;  
  return 0;
}




















