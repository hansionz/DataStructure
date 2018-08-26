#ifndef __QUEUE_H__
#define __QUEUE_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct QueueNode
{
	struct QueueNode* _next;
	DataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* front;//∂”Õ∑
	QueueNode* rear;//∂”Œ≤
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

QueueNode* BuyQueueNode(DataType x);
void QueuePush(Queue* pq, DataType x);
void QueuePop(Queue* pq);
DataType QueueFront(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);

#endif //__QUEUE_H__