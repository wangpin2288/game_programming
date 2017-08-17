#ifndef TERMINNAL_CONTROL_HPP
#define TERMINNAL_CONTROL_HPP

#define true 1
#define false 0

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



void gotoxy(int x, int y){
	printf("\x1b[%d;%df", x, y);
}

void gotoxy(Coordinate& p){
	printf("\x1b[%d;%df",p.X,p.Y);
}

void clean(void){
	printf("\x1b[2J");
	gotoxy(0,0);
}

void usleep(){
	long long int umstime = 100000;
	while( umstime-- ) ;
}

void usleep(int utime){
	while(utime--) usleep();
}

template <typename T>
void draw( int x, int y, T c, bool cl = false){
	if(cl) clean();
	gotoxy( x, y ); cout << c << flush; 
}

template <typename T>
void draw(Coordinate r, T c, bool cl = false){
	if(cl) clean();
	gotoxy( r.X, r.Y ); cout << c << flush;
}

#endif
