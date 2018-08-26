#include"Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->front = NULL;
	pq->rear = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->front;
	while (cur)
	{
		QueueNode* tmp = cur->_next;
		free(cur);
		cur = tmp;
	}
	pq->front = pq->rear = NULL;
}

QueueNode* BuyQueueNode(DataType x)
{
	QueueNode* tmp = (QueueNode*)malloc(sizeof(QueueNode));
	if (tmp == NULL)
	{
		perror("use malloc");
	}
	tmp->_next = NULL;
	tmp->_data = x;
	return tmp;
}
void QueuePush(Queue* pq, DataType x)
{
	assert(pq);
	if (pq->front == NULL)
	{
		QueueNode *next = BuyQueueNode(x);
		pq->rear = next;
		pq->front = next;
	}
	else
	{
		QueueNode *next = BuyQueueNode(x);
		pq->rear->_next = next;
		pq->rear = next;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	QueueNode* next = pq->front->_next;
	free(pq->front);
	pq->front = next;
}
DataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->front->_data;
}
//¿Õ·µ»Ø0£¬·Ç¿Õ·µ»Ø1
int QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->front == NULL ? 0 : 1;
}
int QueueSize(Queue* pq)
{
	int size = 0;
	assert(pq);
	QueueNode* cur = pq->front;
	while (cur)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}