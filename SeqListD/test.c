#include"SeqListD.h"

void test()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
	DestorySeqList(&seq);
}
int main()
{
	test();
	return 0;
}