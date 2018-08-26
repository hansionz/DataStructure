#ifndef __MAZE_H__
#define __MAZE_H__//防止头文件被多次引入

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#pragma warning(disable:4996)

#define MAZEROW 10//迷宫行数
#define MAZECOL 10//迷宫列数
#define MAXSIZE 100//最大元素数

//迷宫中的坐标位置
typedef struct Position
{
	int x;//行号
	int y;//列号
}PosType, *PPosType;
//栈元素类型
typedef struct
{
	PosType seat;//坐标位置
	int dir;//dir = 1,2,3,4分别表示东、南、西、北四个方向
}SElemType;
//顺序栈类型
typedef struct Stack
{
	SElemType data[MAXSIZE];
	int top;//栈顶
}MazeStack, *pMazeStack;

//初始化栈
void InitMazeStack(pMazeStack sm);
//入栈
void PushStack(pMazeStack sm, SElemType data);
//出栈，并将出栈元素保存
void PopStack(pMazeStack sm, SElemType *tmp);
//判断栈是否为空，为空返回1，非空返回0
int EmptyStack(pMazeStack sm);
//走过的地方做标记
void FootPrint(PosType curpos, char maze[MAZEROW][MAZECOL]);
//走不通的地方做标记
void MarkPrint(PosType curpos, char maze[MAZEROW][MAZECOL]);
//找下一个位置作为当前位置，顺时针开始
PosType NextPos(PosType curpos, int dir);
//判断当前位置是否可以通过(没墙)
int IsPass(PosType curpos,char maze[MAZEROW][MAZECOL]);
//求一条从入口到出口的位置
int MazePath(char maze[MAZEROW][MAZECOL], PosType start, PosType end);
//打印迷宫当前的状态
void PrintMaze(char maze[MAZEROW][MAZECOL]);
//打印路径
void PrintPath(char maze[MAZEROW][MAZECOL]);
//打印坐标
void PrintSeat(char maze[MAZEROW][MAZECOL]);
//探索路径
void Exploration(char maze[MAZEROW][MAZECOL], PosType start, PosType end);

#endif //__MAZE_H__