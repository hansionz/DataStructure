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
//����ջ�ṹ
typedef struct Stack
{
	DataType *_a;
	int _top;//ջ��
	int _capacity;//����
}Stack;

//��ʼ��ջ
void StackInit(Stack* ps);
//����ջ
void StackDestroy(Stack* ps);
//��ջ
void StackPush(Stack* ps, DataType x);
//��ջ
void StackPop(Stack* ps);
//ȡջ��Ԫ��
DataType StackTop(Stack* ps);
//�ж�ջ�Ƿ�Ϊ�գ��շ���0���ǿշ���1
int StackEmpty(Stack* ps);
//��ջ�Ĵ�С
int StackSize(Stack* ps);
//ͨ·���ڻ�����һ�ֱ�Ƿ�ʽ��ҲҪ��һ�ּ���Ƿ��ͨ�ķ�ʽ
int CheckAccess(Pos cur, Pos next);
//����һ���յ㣬ȷ����һ������Ƿ��ͨ
int CheckAccess_E(Pos cur);
//ͨ·֮�����
void GetMazePath_C(Pos entry);
//һ����ڣ�������ڣ���һ�����ͨ·
void GetMazePath_M(Pos entry);
//һ����ڣ�һ�����ڣ���һ��ͨ·(����1��ͨ·������0û��ͨ·)
int GetMazePath_E(Pos entry, Pos exit);
//�ݹ�汾
int GetMazePath_R(Pos entry);
//��ӡ�Թ�
void PrintMaze(int maze[N][N]);


#endif //__MAZE_H__