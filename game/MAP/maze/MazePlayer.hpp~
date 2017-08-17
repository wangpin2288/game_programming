#ifndef MazePlayer_HPP
#define MazePlayer_HPP

#include <iostream>
#include <fstream>
#include <string>

#include "Vector.hpp"
#include "TerminalControl.hpp"

using namespace std;

#define POSE_UP		0
#define POSE_RIGHT	1
#define POSE_DOWN	2
#define POSE_LEFT	3

#define MODE_AUTO	1
#define MODE_CONTROL	0

//#define Sleep()		for(int sleep_i = 0; sleep_i < 1000000; sleep_i++)

char POSE_NAME[][10] = {"up","right","down","left"};

class MazePlayer{
  public:
	MazePlayer( string n, MazeMap& m, int mo): 
		name(n) , maz(m), pos(m.getBegin()), pose(POSE_UP), mode(mo){};

	bool isOut(){ 
		if( pos == maz.getEnd() ) return true;
		 else return false;
	};

	bool stepUp()    {return step( -1,  0);};
	bool stepRight() {return step(  0, +1);};
	bool stepDown()  {return step( +1,  0);};
	bool stepLeft()  {return step(  0, -1);};

	void erase(){ gotoxy(pos);cout << ' ' << flush; };
	void draw(){
		gotoxy(pos);
		cout << 'o' << flush;
		gotoxy( maz.getHeight() + 1 , 20 );
		cout << "Player at " << pos.X << ',' << pos.Y << "  " << flush;
		if( mode == MODE_AUTO ) {
			gotoxy( maz.getHeight() + 2 , 20 );
			cout << "POSE: " << POSE_NAME[pose] << "    " << flush;
		}
	};

	bool autoMove();
	void userControl();
  private:
	bool step( int x, int y ){
		if( maz.isWall( pos.X + x, pos.Y + y ) ) 
			return false;
		erase(); pos += Vector2i(x, y); draw();
		if( mode == MODE_AUTO ) 
			usleep();
		return true;
	}
	
	bool stepUsePose( void ){
		switch(pose)
		{
			case POSE_UP:		return ( stepUp() 	);
			case POSE_RIGHT:	return ( stepRight() 	);
			case POSE_DOWN:		return ( stepDown() 	);
			case POSE_LEFT:		return ( stepLeft()	);
		}
	}
	
	void turnLeft(){ pose = ( pose + 3 ) % 4;};
	void turnRight(){ pose = ( pose + 1 ) % 4;};
	string name;
	MazeMap &maz;
	Vector2i pos;
	int pose;
	int mode;
};

void MazePlayer::userControl()
{
	clean(); maz.draw(); draw();
	char key;
	while( !isOut() )
	{
		key = getch();
		if( key == '\x1b' ) break;
		switch ( key )
		{
			case 'w': stepUp();	break;
			case 's': stepDown();	break;
			case 'a': stepLeft();	break;
			case 'd': stepRight();	break;
		}
	}
	gotoxy(maz.getHeight() + 3, 20);
	cout << "Yeah!" << endl;
}

bool MazePlayer::autoMove()
{
	clean(); maz.draw(); draw();
	while( !isOut() )
	{
		turnRight();
		if( stepUsePose( ) ) continue;
		turnLeft();
		if( stepUsePose( ) ) continue;
		turnLeft();
	}
	gotoxy(maz.getHeight() + 3, 20);
	cout << "Yeah!" << endl;
}

#endif
