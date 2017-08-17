#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#include "russia.cpp"
#include "TerminalControl.cpp"


bool Exit=false;
Russia russia;

void* listen_key(void* arg)
{
 static char key='\0';
 while(1){
   key=getch();
   switch(key){
    case 's': russia.moveDown();break;
    case 'a': russia.moveLeft();break;
    case 'd': russia.moveRight();break;
    case 'w': russia.Turn();break;
    case '\27': Exit=true;break;
   }
  usleep(SPEED);
  if(Exit) break;
 }

 pthread_exit(0);
}


void Draw()
{
   for(int i=0;i<LENGTH;i++){
      draw(max_H,i+1,'~');
    }
   draw(1,LENGTH+3,"Position: ");cout<<russia.pos.X<<","<<russia.pos.Y;
   draw(2,LENGTH+3,"Score: ");cout<<russia.Score;
}


int main()
{
   pthread_t tid;
   pthread_create(&tid,NULL,listen_key,NULL);
   Draw();
 while(1){

    while(!russia.inBottom()){
      russia.moveDown();
      Draw();
      if(russia.Over()){
        draw(20,30,"GAME OVER!");
        draw(21,30,"Final Score: ");cout<<russia.Score;
        draw(22,30,"Any key to exit!");
         Exit=true;
         pthread_join(tid, NULL);
         draw(22,40,"Game Over!", true); cout << endl;  
         return 0;
       }
    }

    for(int i=HEIGHT-2;i>0;i--){
       if(russia.LineFull(i)) russia.DeleteLine(i);
     }
    russia.DrawWill();
    russia.Score+=10;
  }
}


























