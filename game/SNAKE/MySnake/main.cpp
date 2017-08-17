#include <iostream>

#include <pthread.h>

#define MAX_X	50
#define MAX_Y	30
#define SPEED	500

#include "snake.hpp"
#include "Vector.hpp"
#include "TerminalControl.hpp"

static long long int step = 0;

//static pthread_mutex_t Mutex= PTHREAD_MUTEX_INITIALIZER;
snake m;
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
		for( int x = 1; x <= MAX_X; x++ ){
			draw(x, 1, '#');
		}
		for( int y = 2; y < MAX_Y; y++ ){
			draw(1, y, '#'); draw(MAX_X, y, '#');
		}
		for( int x = 1; x <= MAX_X; x++ ){
			draw(x, MAX_Y, '#');
		}
		draw(60, 1, "Food at: ");
		draw(60, 2, "Head at: ");
		draw(60, 4, "It's lenth: ");
		draw(60, MAX_Y, "step: ");
		first = false;
	}
	draw(70, 1, f.pos.X);	 cout<<" , "; draw(75, 1, f.pos.Y);
	draw(70, 2, m.Head().X); cout<<" , "; draw(75, 2, m.Head().Y);
	draw(75, 4, m.Len());
	draw(75, MAX_Y, step);
}

int main(){
  pthread_t tid; 
  pthread_create(&tid, NULL, listen_key, NULL);

  panel();
  while( 1 ){
//	pthread_mutex_lock(&Mutex);
	if( f.isWillBeEat() ){
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
