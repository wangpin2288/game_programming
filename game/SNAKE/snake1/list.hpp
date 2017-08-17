#ifndef LIST_HPP
#define LIST_HPP

#include <stdlib.h>
#include <iostream>
#include "coordinate.hpp"
using namespace std;

//定义链表节点类
class list_node{
public:
   list_node():pos(0,0),next(NULL){};
   list_node(int x,int y):pos(x,y),next(NULL){};
   list_node(Coordinate& coor):pos(coor),next(NULL){};
public:
   Coordinate pos;
   list_node* next;
};


//定义链表类
class list{
public:
   list(){
     head=new list_node(0,0);
     tail=head;
     length=0;
   };
  
   list(int x,int y){
     head=new list_node(x,y);
     tail=head;
     length=0;
   };

   ~list(){
     while(tail!=NULL) pop();
   };

   bool push(Coordinate coor){
     list_node* temp=head;
     head=new list_node(coor);
     temp->next=head;
     length++;
     return 1;
   };//向坐标coor前进一步
   
   bool push(int x,int y){
     list_node* temp=head;
     head=new list_node(x,y);
     temp->next=head;
     length++;
     return 1;
   };//向坐标(x,y)前进一步

   bool pop(){
      list_node* temp;
      temp=tail->next;
      delete tail;   
      tail=temp;
      length--;
      return 1;
   };//删除链表尾部数据
  

   Coordinate& readHead(){
      return head->pos;
   };
   
   Coordinate& readTail(){
     if(tail -> next != NULL)
        return (tail -> next) -> pos;
     else
        return tail -> pos;
   };
  
   int len(){return length;};

   bool checkIn(Coordinate& coor){
     list_node* cur=tail;
     while(cur!=NULL){
      if(cur->pos==coor) return 1;
      cur=cur->next;
    }
    
     return 0;
   };//检查coor是否在链表上
   

public:
   list_node* head;
   list_node* tail;
   int length;
};



#endif
