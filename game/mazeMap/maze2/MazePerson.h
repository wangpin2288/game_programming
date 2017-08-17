#include <iostream>
#include "MazeMap.h"
using namespace std;
// 面向的方向（上下左右)
enum direction{UP, DOWN, LEFT, RIGHT};
// 游戏速度（快/中/慢）
enum Speed { FAST, MIDDLE, SLOW};
class MazePerson
{
public:
    // 构造函数，人物标记/面向方向/入口坐标
	MazePerson(string person, direction direct, int x, int y);
	void walk(int x, int y);
	// 向上走
	void up();
	// 向下走
	void down();
	// 向左走
	void left();
	// 向右走
	void right();
	// 转向方法（仅转向）
	void turn(MazeMap* map);
	// 开始闯关
	void start(MazeMap *map,Speed _speed);
private:
	string person;
	direction direct;
	int cX;
	int cY;
	int lX;
	int lY;
	int speed;
private :
	// 用来记录上一步的坐标（不过逻辑中没用到）
	void record();
};

