#include"stackBy2Queue.h"

//��ʼ������
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->front = NULL;
	pq->rear = NULL;
}
//���ٶ���
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
//�����µĽ��
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
//��Ӳ���(��β)
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
//���Ӳ���(��ͷ)
void QueuePop(Queue* pq)
{
	assert(pq);
	QueueNode* next = pq->front->_next;
	free(pq->front);
	pq->front = next;
}
//ȡ��ͷԪ��
DataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->front->_data;
}
//�ж϶��Ƿ�Ϊ�գ��շ���0���ǿշ���1
int QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->front == NULL ? 0 : 1;
}
//����еĴ�С
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
//��ʼ��ջ
void StackInit(StackBy2Queue* ps)
{
	assert(ps);
	QueueInit(&ps->queue1);
	QueueInit(&ps->queue2);
	ps->size = 0;
}
//����ջ
void StackDestroy(StackBy2Queue* ps)
{
	assert(ps);
	QueueDestroy(&ps->queue1);
	QueueDestroy(&ps->queue2);
	ps->size = 0;
}
//��ջ����
void StackPush(StackBy2Queue* ps, DataType x)
{
	assert(ps);
	//�������ж�Ϊ�գ�������һ�����У���һ�����в�Ϊ�գ��Ͳ����Ǹ�����
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
//��ջ����
void StackPop(StackBy2Queue* ps)
{
	assert(ps);
	//��ջ
	if (ps->size == 0)
	{
		return;
	}
	//ȷ���Ǹ�����Ϊ�գ��Ǹ���Ϊ��
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
	//��Ϊ�յĶ��б���һ��Ԫ�أ������Ӽ��ǳ�ջ
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
//ȡջ��Ԫ��
DataType StackGetTop(StackBy2Queue* ps)
{
	assert(ps);
	//��ջ
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