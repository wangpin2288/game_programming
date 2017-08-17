//主函数部分
int main(void)
{
    int mapArray[6][6]={
             {1,1,1,1,1,1},
             {1,1,1,1,0,0},
             {1,1,1,1,0,1},
             {1,0,0,0,0,1},
             {1,0,1,1,0,1},
             {1,0,1,1,1,1}
      };    

     int *mazeMap=&mapArray[0][0];
     MazeMap map(mazeMap,6,6);
     map.setMazeWall('#');
     map.setMazeRoad(' ');
     map.drawMap();

     MazePerson person(1,5,EAST);
     person.setPersonPic('T');
     person.setPersonSpeed(5000);
     person.start();
     
     return 0;
}






















}
