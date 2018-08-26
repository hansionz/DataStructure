#ifndef __MAZE_H__
#define __MAZE_H__//��ֹͷ�ļ����������

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#pragma warning(disable:4996)

#define MAZEROW 10//�Թ�����
#define MAZECOL 10//�Թ�����
#define MAXSIZE 100//���Ԫ����

//�Թ��е�����λ��
typedef struct Position
{
	int x;//�к�
	int y;//�к�
}PosType, *PPosType;
//ջԪ������
typedef struct
{
	PosType seat;//����λ��
	int dir;//dir = 1,2,3,4�ֱ��ʾ�����ϡ��������ĸ�����
}SElemType;
//˳��ջ����
typedef struct Stack
{
	SElemType data[MAXSIZE];
	int top;//ջ��
}MazeStack, *pMazeStack;

//��ʼ��ջ
void InitMazeStack(pMazeStack sm);
//��ջ
void PushStack(pMazeStack sm, SElemType data);
//��ջ��������ջԪ�ر���
void PopStack(pMazeStack sm, SElemType *tmp);
//�ж�ջ�Ƿ�Ϊ�գ�Ϊ�շ���1���ǿշ���0
int EmptyStack(pMazeStack sm);
//�߹��ĵط������
void FootPrint(PosType curpos, char maze[MAZEROW][MAZECOL]);
//�߲�ͨ�ĵط������
void MarkPrint(PosType curpos, char maze[MAZEROW][MAZECOL]);
//����һ��λ����Ϊ��ǰλ�ã�˳ʱ�뿪ʼ
PosType NextPos(PosType curpos, int dir);
//�жϵ�ǰλ���Ƿ����ͨ��(ûǽ)
int IsPass(PosType curpos,char maze[MAZEROW][MAZECOL]);
//��һ������ڵ����ڵ�λ��
int MazePath(char maze[MAZEROW][MAZECOL], PosType start, PosType end);
//��ӡ�Թ���ǰ��״̬
void PrintMaze(char maze[MAZEROW][MAZECOL]);
//��ӡ·��
void PrintPath(char maze[MAZEROW][MAZECOL]);
//��ӡ����
void PrintSeat(char maze[MAZEROW][MAZECOL]);
//̽��·��
void Exploration(char maze[MAZEROW][MAZECOL], PosType start, PosType end);

#endif //__MAZE_H__