#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;
//定义队列结点类型
typedef struct QueueNode
{
	struct QueueNode* _next;
	DataType _data;
}QueueNode;
//定义队列类型
typedef struct Queue
{
	QueueNode* front;//队头
	QueueNode* rear;//队尾
}Queue;

typedef struct StackBy2Queue
{
	Queue queue1;
	Queue queue2;
	int size;
}StackBy2Queue;

//初始化函数
void StackInit(StackBy2Queue* ps);
//销毁函数
void StackDestroy(StackBy2Queue* ps);
//入栈操作函数
void StackPush(StackBy2Queue* ps, DataType x);
//出栈操作函数
void StackPop(StackBy2Queue* ps);
//取栈顶元素函数
DataType StackGetTop(StackBy2Queue* ps);