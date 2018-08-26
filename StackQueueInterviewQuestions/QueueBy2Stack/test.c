#include"QueueBy2Stack.h"

void TestQueueBy2Stack()
{
	QueueBy2Stack q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePop(&q);
	int ret=QueueFront(&q);
	printf("%d ", ret);
	QueueDestroy(&q);	
}
int main()
{
	TestQueueBy2Stack();
	return 0;
}