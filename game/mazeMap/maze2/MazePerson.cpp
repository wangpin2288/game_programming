#include "MazePerson.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

MazePerson::MazePerson(string person, direction direct, int x, int y)
{
    this->person = person;
	this->direct = direct;
	this->cX = x;
	this->cY = y;
}

void MazePerson::walk(int x, int y)
{
	printf("\x1b[%d;%df",x+2,y);
	cout << person;
}

void MazePerson::record()
{
	this->lX = cX;
	this->lY = cY;
}

void MazePerson::up()
{
	if (this->direct != UP) {
		this->direct = UP;
	}
	record();
	this->cY--;
	this->walk(cX, cY);
}
void MazePerson::down()
{
	if (this->direct != DOWN) {
		this->direct = DOWN;
	}
	this->cY++;
	record();
	this->walk(cX, cY);
}
void MazePerson::left()
{
	if (this->direct != LEFT) {
		this->direct = LEFT;
	}
	record();
	this->cX--;
	this->walk(cX, cY);
}
void MazePerson::right()
{
	if (this->direct != RIGHT) {
		this->direct = RIGHT;
	}
	this->cX++;
	record();
	this->walk(cX, cY);
}
// 调整方向
void MazePerson::turn(MazeMap* map)
{
	bool t2 = false;
	bool t4 = false;
	bool t1 = false;
	bool t3 = false;
	t1 = map->isWall(cX - 1, cY);
	t3 = map->isWall(cX + 1, cY);
	t2 = map->isWall(cX, cY - 1);
	t4 = map->isWall(cX, cY + 1);

	switch (this->direct) {
	case UP:
		if (!t1) {
			this->direct = LEFT;
		}
		else if (!t2) {
			this->direct = UP;
		}
		else if (!t3) {
			this->direct = RIGHT;
		}
		else {
			this->direct = DOWN;
		}
		break;
	case RIGHT:
		if (!t2) {
			this->direct = UP;
		}
		else if (!t3) {
			this->direct = RIGHT;
		}
		else if(!t4){
			this->direct = DOWN;
		}
		else  {
			this->direct = LEFT;
		}
		break;
	case DOWN:
		if (!t3) {
			this->direct = RIGHT;
		}
		else if (!t4) {
			this->direct = DOWN;
		} 
		else if (!t1) {
			this->direct = LEFT;
		}
		else {
			this->direct = UP;
		}
		break;
	case LEFT:
		if (!t4) {
			this->direct = DOWN;
		}
		else if (!t1) {
			this->direct = LEFT;
		}
		else if(!t2){
			this->direct = UP;
		}else {
			this->direct = RIGHT;
		}
		break;
	}
}
void MazePerson::start(MazeMap* map, Speed _speed)
{
	int speed = 100;
	switch (_speed) {
	case FAST:
		speed = 100;
		break;
	case MIDDLE:
		speed = 500;
		break;
	case SLOW:
		speed = 1000;
		break;
	}
	// 闯关准备，站到入口
	this->walk(cX, cY);
	// 计步器
	int count = 0;
	// 越界则停止
	while (this->cY > 0 && this->cY < map->getRow() && this->cX < map->getColumn() && this->cX>0) {
		// 休眠，用于控制游戏速度
		Sleep(speed);
		// 每次看一下哪有路，调整符合算法的方向
		turn(map);
		// 刷新地图
		map->draw();
		// 根据面向的方向向前走一步
		switch (this->direct)
		{
		case UP:
			up();
			break;
		case DOWN:
			down();
			break;
		case LEFT:
			left();
			break;
		case RIGHT:
			right();
			break;
		default:
			break;
		}

		//　打印游戏进度信息
		COORD cd;
		cd.X = 0;
		cd.Y = map->getRow()+1;
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(handle, cd);
		cout << "已经走了：" << ++count << "步" << endl;
		cout << "当前坐标：(" << cX << "," << cY << ")" << endl;
	}

	cout << "终于走出来啦" << endl;
}

