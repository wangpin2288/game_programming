#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "MazePerson.h"

#define SUCESS 0
using namespace std;

/************************************************************************/
/* 测试类                                                                     */
/************************************************************************/
int main(void) 
{
    MazeMap *mazeMap = new MazeMap();
	// 迷宫数组
	int MAZEMAP[][30] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,0,0,0,1,0,1,1,1,1,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1 },
		{ 1,1,1,1,0,1,0,1,0,0,0,0,1,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1 },
		{ 1,0,0,0,0,1,0,0,0,1,1,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1,0,0,0,1 },
		{ 1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1 },
		{ 1,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,1,0,1,1 },
		{ 1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,0,1,1,1,1,0,1,0,1,1 },
		{ 1,1,0,0,0,0,1,0,1,1,1,1,0,0,0,0,1,0,0,0,1,1,0,0,0,0,1,0,1,1 },
		{ 1,0,0,1,0,0,0,0,1,1,1,0,0,1,0,0,0,0,1,1,1,0,0,1,0,0,0,0,1,1 },
		{ 1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1 }
	 };
	//　初始化迷宫
	mazeMap->setMazeArr(&MAZEMAP[0][0], 10, 30);
	sleep(3);
	mazeMap->draw();

	// 初始化闯关者
	MazePerson mp("T", UP, 1, 9);
	// 开始闯关
	mp.start(mazeMap, FAST);
	cout << endl;
	system("pause");
	if(mazeMap!=NULL){
		delete mazeMap;
		mazeMap = NULL;
	}
	return SUCESS;
}
