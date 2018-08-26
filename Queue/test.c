#include"Queue.h"

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	/*printf("%d ", QueueFront(&q));*/
	int ret = QueueSize(&q);
	printf("size=%d\n", ret);
	while (QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}


	QueueDestroy(&q);
}

int main()
{
	TestQueue();
	return 0;
}