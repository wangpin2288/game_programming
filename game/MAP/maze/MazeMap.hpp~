#ifndef MazeMap_HPP
#define MazeMap_HPP

#include <iostream>
#include <fstream>
#include <string>

#include "Vector.hpp"
#include "TerminalControl.hpp"

using namespace std;

class MazeMap{
  public:
	MazeMap(const char filename[] );
	int getWidth(){ return size.Y; };
	int getHeight(){ return size.X; };
	int getSize(){ return size.X * size.Y; };
	bool isMapExist(){ return ok; };
	Vector2i getEnd(){ return end; };
	Vector2i getBegin(){ return begin; };

	bool inWall( int x, int y){ 
		if( x <= 0 || x >= size.X ) return false;
		else if( y <= 0 || y >= size.Y) return false;
		else return true;
	};
	bool inWall( const Vector2i & p){return inWall(p.X,p.Y);};

	bool isWall( int x, int y){
		Vector2i p( x - 1, y - 1 );
		if(!inWall(p)) return true;
		else if(map[p.X][p.Y] == ' ') return false;
		else return true;
	};
	bool isWall(Vector2i pos){return isWall(pos.X, pos.Y);};
	void draw(void){
		gotoxy(1,1);
		for(int i = 0; i < size.X; i++ ){
			cout << map[i]<< endl;
	}
}
  private:
	bool ok;
	Vector2i size;
	Vector2i begin;
	Vector2i end;
	char map[101][101];
};

MazeMap::MazeMap(const char filename[] ){
	cout << "HELLO" << endl;
	ifstream mapInput( filename );
	if( !mapInput.is_open() )
	{
		cerr << "Map File Open Failed!!!" << endl;
		ok = false ;
		return ;
	}

	mapInput >> size.X  >> size.Y;
	mapInput >> begin.X >> begin.Y;
	mapInput >> end.X   >> end.Y;

	mapInput.ignore();
	for(int i = 0; i < size.X; i++ )
		mapInput.getline( map[i], size.Y + 1 );
	
	mapInput.close();
	ok = true;
}

#endif
