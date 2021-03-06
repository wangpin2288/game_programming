#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "list.hpp"
#include "Vector.hpp"
#include "TerminalControl.hpp"
#define MAX_X	50
#define MAX_Y	30
#define UP	0
#define RIGHT	1
#define DOWN	2
#define LEFT	3

using namespace std;

static Vector2i slide[4] = {	Vector2i(0, -1),
				Vector2i(1, 0),
				Vector2i(0, 1),
				Vector2i(-1, 0)
                           };

class snake{
  public:
	snake(): pose(RIGHT), s(), alive(true){
		s.push( Vector2i(5,5) ); 
		draw( Vector2i(5,5), '@', true );
		grow();grow();grow();grow();
	}//初始化

	bool grow(){
		Vector2i hh( Head() );
		hh += slide[pose];
		if( goDead(hh) ) return false;
		draw(Head(),'o'); draw( hh, '@' ); 
		s.push( hh );
		return true;
	}//蛇头移动一步

	bool step(){
		if( !grow() ) return false;
		draw( Tail() , ' '); 
		s.pop();
		return true;
	}//蛇尾移动一步

	bool changePose(int dir){
		if( dir == (pose + 1) % 4 ) pose = dir;
		else if( dir == (pose + 3) % 4 ) pose = dir;
		else return false;
		return true;
	}//改变运动方向

	bool isBodyPart(const Vector2i& r ){
		return s.check(r);
	}//判断坐标是否在蛇身上

	int Len(){ return s.len(); }
	bool Alive(){ return alive; }
	Vector2i Head(){ return s.readHead(); }
	Vector2i Tail(){ return s.readTail(); }
	Vector2i Front(){ 
		Vector2i tmp(Head());
		return tmp+=slide[pose];
	}

  private:
	bool goDead(const Vector2i r){
		if( r.X <= 1 || r.X >= MAX_X ||
			r.Y <= 1 || r.Y >= MAX_Y ||
				isBodyPart(r)){
			alive = false;
			return true;
		}
		return false;
	}
	int pose;
	list s;
	bool alive;
};


class food{
  public:
	Vector2i pos;
	snake& s;

	food(snake& r): pos( 30, 5 ), s(r){draw(pos, '*');}
	
	void another(void){
		srand(time(NULL));
		pos.X = rand() % ( MAX_X - 3 ) + 2;
		pos.Y = rand() % ( MAX_Y - 3 ) + 2;
       //产生一个在围墙内部的随机数坐标
		if( s.isBodyPart( pos )) another();
      //判断产生的坐标不与蛇身体的坐标重合
		else draw(pos, '*');
	}

	bool isWillBeEat(){
		if( s.Front() == pos ) return true;
		else return false;
	}
};



#endif
