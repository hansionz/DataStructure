#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;
//定义栈结构
typedef struct Stack
{
	DataType *_a;
	int _top;//栈顶
	int _capacity;//容量
}Stack;

typedef struct QueueBy2Stack
{
	Stack input;//实现入队的栈
	Stack output;//实现出队的栈
	int size; //队列的有效元素个数
}QueueBy2Stack;

//初始化函数
void QueueInit(QueueBy2Stack* pq);
//销毁函数
void QueueDestroy(QueueBy2Stack* pq);
//入队函数
void QueuePush(QueueBy2Stack* pq, DataType x);
//出队函数
void QueuePop(QueueBy2Stack* pq);
//取队头元素函数
DataType QueueFront(QueueBy2Stack*pq);