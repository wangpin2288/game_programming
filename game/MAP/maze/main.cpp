
#include "Vector.hpp"
#include "MazeMap.hpp"
#include "MazePlayer.hpp"
#include "TerminalControl.hpp"

const char filename[] = "maze001.txt";

int main(int argc, char** argv)
{
	clean();
	MazeMap map(filename);
	if(!map.isMapExist()) 
		return -1;
	MazeMap &m = map;
	MazePlayer player("Yang", m, MODE_AUTO);

//	player.userControl();
	player.autoMove();
	return 0;
}
