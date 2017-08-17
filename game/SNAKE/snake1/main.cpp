#include <iostream>

#include <pthread.h>

#define LENGTH	50
#define HEIGHT	30
#define SPEED	500

#include "snake.hpp"
#include "coordinate.hpp"
#include "TerminalControl.hpp"

static long long int step = 0;

//static pthread_mutex_t Mutex= PTHREAD_MUTEX_INITIALIZER;
Snake m;
food f(m);
bool Exit = false;

void* listen_key(void* arg)
{
	static char key = '\0';
	while( 1 ){
		key = getch();
//		pthread_mutex_lock(&Mutex);
		switch (key){
		  case 'w': 	m.changePose(UP);	break;
		  case 'd':	m.changePose(RIGHT);	break;
		  case 's': 	m.changePose(DOWN); 	break;
		  case 'a': 	m.changePose(LEFT); 	break;
		  case '\27':	Exit = true;		break;
		}
		usleep(700);
//		pthread_mutex_unlock (&Mutex);
		if(Exit) break;
	}
	pthread_exit(0);
}



void panel(){
	static bool first = true;
	if( first ){
		for( int x = 1; x <= LENGTH; x++ ){
			draw(1,x, '#');
		}
		for( int y = 2; y < HEIGHT; y++ ){
			draw(y,1, '#'); draw(y,LENGTH, '#');
		}
		for( int x = 1; x <= LENGTH; x++ ){
			draw(HEIGHT,x, '#');
		}
		draw(1,60, "Food at: ");
		draw(2,60, "Head at: ");
		draw(4,60, "It's lenth: ");
		draw(HEIGHT,60 ,"step: ");
		first = false;
	}
	draw( 1,70, f.pos.X); cout<<" , "; draw(1,75, f.pos.Y);
	draw(2,70, m.head().X); cout<<" , "; draw(2,80, m.head().Y);
	draw(4,75, m.length());
	draw(HEIGHT,75, step);
}




int main(){
  pthread_t tid; 
  pthread_create(&tid, NULL, listen_key, NULL);

  panel();
  while( 1 ){
//	pthread_mutex_lock(&Mutex);
	if( f.willBeEaten() ){
		f.another();
		m.grow();	
	}
	else m.step();
	if( !m.Alive() ){
		draw(60, 10, "Your snake is dead!");
		draw(60, 11, "Any Key to Exit!");
		Exit = true;
	}
//	pthread_mutex_unlock(&Mutex);
	if(Exit) break;
	panel(); usleep(SPEED); step++;
  }  
  pthread_join(tid, NULL);
  getch();
  draw(30,10,"Game Over!", true); cout << endl;
  return 0;
}

