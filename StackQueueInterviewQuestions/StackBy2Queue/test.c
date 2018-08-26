#include"stackBy2Queue.h"

void TestStackBy2Queue()
{
	StackBy2Queue s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPop(&s);
	DataType ret = StackGetTop(&s);
	printf("%d ", ret);
	StackDestroy(&s);
}
int main()
{
	TestStackBy2Queue();
	return 0;
}