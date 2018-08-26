#ifndef __MAZE_H__
#define __MAZE_H__

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#define N 6

typedef struct Pos
{
	int _row;
	int _col;
}Pos;

typedef Pos DataType;
//定义栈结构
typedef struct Stack
{
	DataType *_a;
	int _top;//栈顶
	int _capacity;//容量
}Stack;

//初始化栈
void StackInit(Stack* ps);
//销毁栈
void StackDestroy(Stack* ps);
//入栈
void StackPush(Stack* ps, DataType x);
//出栈
void StackPop(Stack* ps);
//取栈顶元素
DataType StackTop(Stack* ps);
//判断栈是否为空，空返回0，非空返回1
int StackEmpty(Stack* ps);
//求栈的大小
int StackSize(Stack* ps);
//通路存在环，换一种标记方式，也要换一种检查是否可通的方式
int CheckAccess(Pos cur, Pos next);
//给定一个终点，确定下一个结点是否可通
int CheckAccess_E(Pos cur);
//通路之间带环
void GetMazePath_C(Pos entry);
//一个入口，多个出口，求一条最短通路
void GetMazePath_M(Pos entry);
//一个入口，一个出口，求一条通路(返回1有通路，返回0没有通路)
int GetMazePath_E(Pos entry, Pos exit);
//递归版本
int GetMazePath_R(Pos entry);
//打印迷宫
void PrintMaze(int maze[N][N]);


#endif //__MAZE_H__