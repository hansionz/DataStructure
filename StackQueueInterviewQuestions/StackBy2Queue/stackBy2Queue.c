#include"stackBy2Queue.h"

//初始化队列
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->front = NULL;
	pq->rear = NULL;
}
//销毁队列
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
//开辟新的结点
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
//入队操作(队尾)
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
//出队操作(队头)
void QueuePop(Queue* pq)
{
	assert(pq);
	QueueNode* next = pq->front->_next;
	free(pq->front);
	pq->front = next;
}
//取队头元素
DataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->front->_data;
}
//判断队是否为空，空返回0，非空返回1
int QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->front == NULL ? 0 : 1;
}
//求队列的大小
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
//初始化栈
void StackInit(StackBy2Queue* ps)
{
	assert(ps);
	QueueInit(&ps->queue1);
	QueueInit(&ps->queue2);
	ps->size = 0;
}
//销毁栈
void StackDestroy(StackBy2Queue* ps)
{
	assert(ps);
	QueueDestroy(&ps->queue1);
	QueueDestroy(&ps->queue2);
	ps->size = 0;
}
//入栈操作
void StackPush(StackBy2Queue* ps, DataType x)
{
	assert(ps);
	//两个队列都为空，插入哪一个都行，有一个队列不为空，就插入那个队列
	if (QueueSize(&ps->queue1) != 0)
	{
		QueuePush(&ps->queue1, x);
	}
	else
	{
		QueuePush(&ps->queue2, x);
	}
	ps->size++;
}
//出栈操作
void StackPop(StackBy2Queue* ps)
{
	assert(ps);
	//空栈
	if (ps->size == 0)
	{
		return;
	}
	//确定那个队列为空，那个不为空
	Queue* _Have = NULL;
	Queue* _NoHave = NULL;
	if (QueueSize(&ps->queue1) != 0)
	{
		_Have = &ps->queue1;
		_NoHave = &ps->queue2;
	}
	else
	{
		_Have = &ps->queue2;
		_NoHave = &ps->queue1;
	}
	//不为空的队列保留一个元素，最后出队既是出栈
	while (QueueSize(_Have)!=1)
	{
		DataType tmp;
		tmp = QueueFront(_Have);
		QueuePop(_Have);
		QueuePush(_NoHave, tmp);
	}
	QueuePop(_Have);
	ps->size--;
}
//取栈顶元素
DataType StackGetTop(StackBy2Queue* ps)
{
	assert(ps);
	//空栈
	if (ps->size == 0)
	{
		return;
	}
	//
	Queue* _Have = NULL;
	Queue* _NoHave = NULL;
	if (QueueSize(&ps->queue1) != 0)
	{
		_Have = &ps->queue1;
		_NoHave = &ps->queue2;
	}
	else
	{
		_Have = &ps->queue2;
		_NoHave = &ps->queue1;
	}
	while (QueueSize(_Have) != 1)
	{
		DataType tmp;
		tmp = QueueFront(_Have);
		QueuePop(_Have);
		QueuePush(_NoHave, tmp);
	}
	DataType cur = QueueFront(_Have);
	QueuePop(_Have);
	QueuePush(_NoHave, cur);
	return cur;
}