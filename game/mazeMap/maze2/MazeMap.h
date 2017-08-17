
#include <iostream>
using namespace std;

/************************************************************************/
/* 迷宫类                                                                     */
/************************************************************************/
class MazeMap
{
public:
    MazeMap(const string WALL="*", const string ROAD=" ");
	~MazeMap();
	// 设置迷宫模型
	void setMazeArr(int* mazeArr, int row, int column);
	// 绘制迷宫
	void draw();
	// 该坐标点是否是墙
	bool isWall(int x, int y);
	// 行
	int getRow();
	// 列
	int getColumn();
private:
	const string WALL;
	const string ROAD;
	int row;
	int column ;
	int* mazeArr;
};
  

