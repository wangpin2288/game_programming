#ifndef TERMINNAL_CONTROL_HPP
#define TERMINNAL_CONTROL_HPP

#include <termios.h>
#include <stdio.h>

static struct termios old, pro;

/* Initialize new terminal i/o settings */
void initTermios(int echo) {
  tcgetattr(0, &old); /* grab new terminal i/o settings */
  pro = old; /* make new settings same as old settings */
  pro.c_lflag &= ~ICANON; /* disable buffered i/o */
  pro.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &pro); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) {
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) {
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) 
{
  return getch_(1);
}

void clean(void){
	printf("\x1b[2J");
}

void gotoxy(int x, int y){
	printf("\x1b[%d;%df",x, y );
}

void gotoxy(Vector2i p){
	printf("\x1b[%d;%df",p.X,p.Y);
}

void usleep(){
	for(int sleep_i = 0; sleep_i < 10000; sleep_i++)
		for(int sleep_j = 0; sleep_j < 10000; sleep_j++)
			;
}

#endif
