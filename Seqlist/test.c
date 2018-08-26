#include"seqlist.h"

void TestErase()
{
	int pos = 0;
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PrintSeqList(&seq);
	pos = Find(&seq, 2);
	if (pos != -1)
	{
		Erase(&seq, pos);
	}
	PrintSeqList(&seq);
}
void TestInsert()
{
	int pos = 0;
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PrintSeqList(&seq);
	pos = Find(&seq, 2);
	if (pos != -1)
	{
		Insert(&seq, 5, pos);
	}
	PrintSeqList(&seq);

}
void TestRemove()
{
	int pos = 0;
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3); 
	PushBack(&seq, 4);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PrintSeqList(&seq);
	Remove(&seq, 3);
	PrintSeqList(&seq);
}
void TestFind()
{
	int pos = 0;
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PrintSeqList(&seq);
	pos = Find(&seq, 5);
	if (pos != -1)
	{
		printf("找到了，下标是%d\n", pos);
	}
	else
	{
		printf("找不到\n");
	}
	
}
void TestRemoveAll()
{
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 1);
	PushFront(&seq, 1);
	PushFront(&seq, 4);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 2);
	if (!Empty(&seq))
	{
		printf("顺序表大小为：%d\n", Size(&seq));
	}
	PrintSeqList(&seq);
	RemoveAll(&seq, 1);
	PrintSeqList(&seq);
}
void TestBubbleSort()
{
	int i = 0;
	SeqList seq;
	InitSeqList(&seq);
	PrintSeqList(&seq);

	for (i = 10; i > 0; i--)
	{
		PushBack(&seq, i);
	}
	PrintSeqList(&seq);
	BubbleSort(&seq);
	PrintSeqList(&seq);
}
void TestSelectSort_op()
{
	int i = 0;
	SeqList seq;
	InitSeqList(&seq);
	for (i = 10; i > 0; i--)
	{
		PushBack(&seq, i);
	}
	PrintSeqList(&seq);
	SelectSort_op(&seq);
	PrintSeqList(&seq);
}
void TestBinarySearch()
{
	int i = 0;
	int pos = 0;
	SeqList seq;
	InitSeqList(&seq);
	for (i = 0; i <10; i++)
	{
		PushBack(&seq, i);
	}
	PrintSeqList(&seq);
	pos = BinarySearch(&seq, 0);
	if (pos != -1)
	{
		printf("找到了，下标是：%d\n", pos);
	}
	else
	{
		printf("找不到\n");
	}
}
int main()
{
	SeqList seq;
	InitSeqList(&seq);
	TestBinarySearch();

	/*TestFind();*/
	//尾插测试
	/*PushBack(&seq, 1);
	PushBack(&seq, 2);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);*/
	//头插测试
	/*PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);*/
	//find测试

	return 0;
}