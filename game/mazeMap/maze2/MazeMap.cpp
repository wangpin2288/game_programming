#include "MazeMap.h"
#include <string>
#include <windows.h>
#include <iostream>
#include <stdlib.h>
using namespace std;


MazeMap::MazeMap(const string WALL, const string ROAD):WALL(WALL),ROAD(ROAD)
{
    cout << "欢迎勇士们前来闯迷宫！" << endl;
}
MazeMap::~MazeMap()
{
}

int MazeMap::getRow() {
	return row;
}
int MazeMap::getColumn() {
	return column;
}
bool MazeMap::isWall(int x, int y) 
{
	if (this->mazeArr[x+y*column] == 1)
	{
		return true;
	}
	return false;
}

void MazeMap::setMazeArr(int* mazeArr, int row, int column)
{
	this->mazeArr = mazeArr;
	this->row = row;
	this->column = column;
}

void MazeMap::draw()
{
	system("cls");
	int len = row*column;
	for (int i = 0; i < len; i++) {
		if (i > 0 && i%column == 0)
			cout << endl;
		if (mazeArr[i] == 0) 
		{
			cout << ROAD;
		}
		else 
		{
			cout << WALL;
		}
	}
	cout << endl;
}

