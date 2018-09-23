#include"Sort.h"
#include"Stack.h"
//打印数组，方便测试
void PrintNum(int *num, int len)
{
	assert(num);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");
}

void TestInertSort()
{
	int num[] = { 1, 3, 5, 2, 6, 10, 8, 7, 28, 92 };
	int len = sizeof(num) / sizeof(num[0]);
	//InsertSort(num, len);
	//PrintNum(num, len);
	InsertSort_op(num, len);
	PrintNum(num, len);

	//ShellSort(num, len);
	//PrintNum(num, len);
}
void TestSelectSort()
{

	int num[10000];
	srand((unsigned int)time(0));
	for (int i = 0; i < 10000; i++)
	{
		num[i] = rand();
	}
	int len = sizeof(num) / sizeof(num[0]);
	int start1 = clock();
	SelectSort(num, len);
	int end1 = clock();
	/*PrintNum(num, len);*/
	printf("%d\n", end1 - start1);

	int start2 = clock();
	SelectSort_op(num, len);
	int end2 = clock();
	/*PrintNum(num, len);*/
	printf("%d\n", end1 - start1);
}
void TestHeapSort()
{
	int num[] = { 1, 4, 2, 0, 7, 8, 9 };
	int len = sizeof(num) / sizeof(num[0]);
	HeapSort(num, len);
	PrintNum(num, len);
}
void TestBubbleSort()
{
	int num[] = { 1, 4, 2,0, 7, 8, 9 };
	int len = sizeof(num) / sizeof(num[0]);
	BubbleSort(num, len);
	PrintNum(num, len);
	BubbleSort_op1(num, len);
	PrintNum(num, len);
	BubbleSort_op2(num, len);
	PrintNum(num, len);
}
void TestQuickSort()
{
	//int num[] = { 1, 4, 2, 9, 7, 8, 5 };
	//int len = sizeof(num) / sizeof(num[0]);
	/*PrintNum(num1, len);*/
	const int len = 1000000;

	int* num1= (int*)malloc(sizeof(int)*len);
	int* num2 = (int*)malloc(sizeof(int)*len);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < len; i++)
	{
		num1[i] = rand();
		num2[i] = num1[i];
	}
	int start1 = clock();
	QuickSort(num1, 0, len - 1);
	int end1 = clock();

	int start2 = clock();
	QuickSort1(num2, 0, len - 1);
	int end2 = clock();

	printf("%d\n", end1 - start1);
	printf("%d\n", end2 - start2);
}

void TestQuickSortNonR()
{
	int num[] = { 1, 3, 2, 6, 4, 8, 5 };
	QuickSortNonR(num, 0, sizeof(num) / sizeof(num[0]) - 1);
	PrintNum(num, sizeof(num) / sizeof(num[0]));
}
void TestMergeSort()
{
	int num[] = { 1, 3, 2, 6, 4, 8, 5 };
	int len = sizeof(num) / sizeof(num[0]);
	MergeSort(num,len);
	PrintNum(num, len);
}
int main()
{
	//TestInertSort();
	//TestSelectSort();
	//TestHeapSort();
	//TestBubbleSort();
	//TestQuickSort();
	//TestQuickSortNonR();
	TestMergeSort();
	return 0;
}