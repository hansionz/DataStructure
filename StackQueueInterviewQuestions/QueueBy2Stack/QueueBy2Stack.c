#include"QueueBy2Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);

	ps->_a = (DataType*)malloc(sizeof(DataType)* 3);
	ps->_top = 0;
	ps->_capacity = 3;
}

void StackDestroy(Stack* ps)
{
	assert(ps);

	free(ps->_a);
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}

void StackPush(Stack* ps, DataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		DataType* tmp = realloc(ps->_a, sizeof(DataType)*(ps->_capacity * 2));
		if (tmp != NULL)
		{
			ps->_a = tmp;
		}
		ps->_capacity = 2 * ps->_capacity;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}

void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->_top > 0);

	ps->_top--;
}
DataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->_top > 0);

	return ps->_a[ps->_top - 1];
}

//¿Õ·µ»Ø0£¬·Ç¿Õ·µ»Ø1
int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0 ? 0 : 1;
}

int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}
void QueueInit(QueueBy2Stack* pq)
{
	assert(pq);
	StackInit(&pq->input);
	StackInit(&pq->output);
	pq->size = 0;
}
void QueueDestroy(QueueBy2Stack* pq)
{
	assert(pq);
	StackDestroy(&pq->input);
	StackDestroy(&pq->output);
	pq->size = 0;
}
void QueuePush(QueueBy2Stack* pq, DataType x)
{
	assert(pq);
	while (StackEmpty(&pq->output))
	{
		DataType tmp;
		tmp = StackTop(&pq->output);
		StackPop(&pq->output);
		StackPush(&pq->input, tmp);
	}
	StackPush(&pq->input, x);
	pq->size++;
}
void QueuePop(QueueBy2Stack* pq)
{
	assert(pq);
	while (StackEmpty(&pq->input))
	{
		DataType tmp;
		tmp = StackTop(&pq->input);
		StackPop(&pq->input);
		StackPush(&pq->output, tmp);
	}
	StackPop(&pq->output);
	pq->size--;
}
DataType QueueFront(QueueBy2Stack*pq)
{
	assert(pq);
	while (StackEmpty(&pq->input))
	{
		DataType tmp;
		tmp = StackTop(&pq->input);
		StackPop(&pq->input);
		StackPush(&pq->output, tmp);
	}
	return StackTop(&pq->output);
}