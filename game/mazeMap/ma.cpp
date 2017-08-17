
   void MazePerson::savePrePosition()
   {
      preX=positionX;
      preY=positionY;
   }


   void MazePerson::moveSouth()
   {
      positionX=positionX;
      positionY=positionY+1;
   }   


   void MazePerson::moveNorth()
   {
      positionX=positionX;
      positionY=positionY-1;
   }

   
   void MazePerson::moveWest()
   {
       positionY=positionY;
       positionX=positionX-1;

   }

   void MazePerson::moveEast()
   {
       positionY=positionY;
       positionX=positionX+1;

   }

   void MazePerson::moveAhead()//沿着当前方向向前走的方法
   {
       swith(forward){
          case NORTH:
            positionX=positionX;
            positionY=positionY-1;
            break;
          case WEST:
            positionY=positionY;
            positionX=positionX-1;
            break;
          case SOUTH:
            positionX=positionX;
            positionY=positionY+1;
            break;
          case EAST:
            positionY=positionY;
            positionX=positionX+1;
            break;
          default:
            cout<<"方向错误"<<endl;
          };

      drawPerson();
      if(MazeMap::checkMazeDoor(positionX,positionY))
     {
        gotoxy(0,22);
        cout<<"哈哈，终于出来啦！"<<endl;
        outOrNot=TRUE;
      }

   }




   void MazePerson::turnLeft()
   {
       swith(forward){
          case NORTH:
               forward=WEST;
               break;
          case WEST:
               forward=SOUTH;
               break;
          case SOUTH:
               forward=EAST;
               break;
          case EAST:
               forward=NORTH;
               break;
          default:
            cout<<"方向错误"<<endl;
          };

   }

   void MazePerson::turnRight()

   {
       swith(forward){
          case NORTH:
               forward=EAST;
               break;
          case WEST:
               forward=NORTH;
               break;
          case SOUTH:
               forward=WEST;
               break;
          case EAST:
               forward=SOUTH;
               break;
          default:
            cout<<"方向错误"<<endl;
          };

   }

   bool MazePerson::moveForward()//可以进行主观判断如何前进的方法
   {

 //检查当前位置是否合法
      if(MazeMap::checkWallOrNot(positionX,positionY))
      {
         //检测到当前位置是墙，提示用户设计非法并返回
         gotoxy(0,23);
         cout<<"检测到当前设定的起始位置是墙壁，请重新设定"<<endl;
         outOrNot=true;
         return NO;
        }

//判断如果前一个位置的坐标是10000，则直接在当前位置绘制人

if(preX=10000||preY=10000)
{
   gotoxy(positionX,positionY);
   cout<<personPic;
   Sleep(5000);
}

/*
检查右侧是否是墙，如果是墙，检查前方是否是墙，如果不是墙则前进，前进后检查是否是出口
*/
int rightX;
int rightY;

int forwardX;
int forwardY;

switch(forward)
{
  case NORTH:rightX=positionX+1;rightY=positionY;
             forwardX=positionX;forwardY=positionY-1;break;
  case SOUTH:rightX=positionX-1;rightY=positionY;
             forwardX=positionX;forwardY=positionY+1;break;
  case WEST:rightX=positionX;rightY=positionY-1;
             forwardX=positionX-1;forwardY=positionY;break;
  case EAST:rightX=positionX;rightY=positionY+1;
             forwardX=positionX+1;forwardY=positionY;break;
}

if(MazeMap::checkWallOrNot(rightX,rightY))
{
//检查到右方是墙壁
//检查到前方也是墙壁
    if(MazeMap::checkWallOrNot(forwardX,forwardY))
    {
       turn left();
       return NO;  
    }
 
    else
    {
        moveAhead();
        return YES;
     }
}

else
{
   Sleep(3000);
   turnRight();
   goAhead();
   return YES;
}
}



   void MazePerson::gotoxy(int x,int y);//设定输出位置的方法
   {  
       COORD cd;
       cd.X=x;
       cd.Y=y;
       SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cd);
   }

   void MazePerson::drawPerson();//绘制走迷宫者的行走动画的方法
   {    
        //在当前位置上绘制人
        char mazeRoad=MazeMap::getRoadChar();
        gotoxy(preX,preY);
        cout<<mazeRoad;
        gotoxy(positionX,positionY);
        cout<<personPic;
        //为制作动画效果使用时间延迟
        Sleep(personSpeed);
    }




  void MazePerson::start()
{
   int i=0;
   while(!outOrNot)
  {
      gotoxy(0,15);
      cout<<i;
      i++;
      moveForward();
   }
}







   
