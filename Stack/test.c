#include"Stack.h"

void TestStack()
{
	Stack s;
	StackInit(&s);

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);

	while (StackEmpty(&s))
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}
	StackDestroy(&s);
}
void TestCheckLegal()
{
	int num_in[] = { 1, 2, 3, 4, 5 };
	int num_out[] = { 4, 5, 2, 3, 1 };
	int len_in = sizeof(num_in) / sizeof(num_in[0]);
	int len_out = sizeof(num_out) / sizeof(num_out[0]);
	int ret = CheckLegal(num_in, num_out, len_in, len_out);
	if (ret == 1)
	{
		printf("合法\n");
	}
	else
	{
		printf("不合法\n");

	}
}
void TestGetMinValue()
{
	Stack s;
	StackInit(&s);
	Stack_O1Push(&s, 4);
	Stack_O1Push(&s, 3);
	Stack_O1Push(&s, 2);
	Stack_O1Push(&s, 1);
	/*Stack_O1Pop(&s);*/
	printf("%d ", GetMinValue(&s));
	StackDestroy(&s);
}
void TestStackShare()
{
	StackShare s;
	int ret;
	StackShareInit(&s);

	StackSharePush(&s, 1, 'R');
	StackSharePush(&s, 2, 'R');
	StackSharePush(&s, 3, 'R');
	StackSharePush(&s, 4, 'R');
	/*printf("%d ", StackShareTop(&s, 'L'));
	printf("%d ", StackShareTop(&s, 'L'));*/
	while (ret=StackShareEmpty(&s, 'R'))
	{
		printf("%d ", StackShareTop(&s, 'R'));
		StackSharePop(&s, 'R');
	}
	StackShareDestroy(&s);
}
void TestSareStack()
{
	ShareStack ssk;
	ShareStackInit(&ssk);
	ShareStackPush(&ssk, 1, 'L');
	ShareStackPush(&ssk, 2, 'L');
	ShareStackPush(&ssk, 3, 'L');
	ShareStackPush(&ssk, 4, 'L');
	ShareStackPop(&ssk, 'L');
	int ret=ShareStackTop(&ssk, 'L');
	printf("%d\n", ShareStackSize(&ssk, 'L'));
	while (ShareStackEmpty(&ssk, 'L'))
	{
		int ret = ShareStackTop(&ssk, 'L');
		printf("%d ", ret);
		ShareStackPop(&ssk, 'L');
	}
	printf("%d\n", ShareStackSize(&ssk, 'L'));
	/*printf("%d ", ret);
	ShareStackPush(&ssk, 1, 'R');
	ShareStackPush(&ssk, 2, 'R');
	ShareStackPush(&ssk, 3, 'R');
	ShareStackPush(&ssk, 4, 'R');
	printf("%d\n", ShareStackSize(&ssk, 'R'));
	while (ShareStackEmpty(&ssk, 'R'))
	{
		int ret = ShareStackTop(&ssk, 'R');
		printf("%d ", ret);
		ShareStackPop(&ssk, 'R');
	}
	printf("%d\n", ShareStackSize(&ssk, 'R'));*/
	ShareStackDestroy(&ssk, 'R');

}
int main()
{
	/*TestCheckLegal();*/
	/*TestGetMinValue();*/
	TestStackShare();
	/*TestSareStack();*/
	return 0;
}