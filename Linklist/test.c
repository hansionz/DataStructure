#include"LinkList.h"

void TestReverselist()
{
	pNode pos = NULL;
	pLinkList list;
	InitLinkList(&list);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PrintLinkList(&list);
	Reverselist(&list);
	PrintLinkList(&list);
}
void TestInsertNodeNotHead()
{
	pNode pos = NULL;
	pLinkList list;
	InitLinkList(&list);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PrintLinkList(&list);
	pos = Find(list, 3);
	InsertNodeNotHead(&list, 5, pos);
	PrintLinkList(&list);
}
void TestRmoveNodeNotTail()
{
	pNode pos = NULL;
	pLinkList list;
	InitLinkList(&list);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PrintLinkList(&list);
	pos = Find(list, 1);
	RmoveNodeNotTail(&list, pos);
	PrintLinkList(&list);
}
void TestPushFront()
{
	pLinkList list;
	pNode pos = NULL;
	InitLinkList(&list);
	PushFront(&list, 1);
	PushFront(&list, 2);
	PushFront(&list, 3);
	PushFront(&list, 4);
	PrintLinkList(&list);
}
void TestPopFront()
{
	pLinkList list;
	pNode pos = NULL;
	InitLinkList(&list);
	PushFront(&list, 1);
	PushFront(&list, 2);
	PushFront(&list, 3);
	PushFront(&list, 4);
	PrintLinkList(&list);
	PopFront(&list);
	PrintLinkList(&list);
	PopFront(&list);
	PrintLinkList(&list);
	PopFront(&list);
	PrintLinkList(&list);
	PopFront(&list);
	PrintLinkList(&list);
}
void TestPopBack()
{
	pLinkList list;
	pNode pos = NULL;
	InitLinkList(&list);
	PushBack(&list, 1);
	/*PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);*/ 
	PrintLinkList(&list);
	PopBack(&list);
	PrintLinkList(&list);
}
void TestInsert()
{
	pLinkList list;
	pNode pos = NULL;
	InitLinkList(&list);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PrintLinkList(&list);
	pos = Find(list, 2);
	Insert(&list, pos, 5);
	PrintLinkList(&list);
}
void TestRemove()
{
	pLinkList list;
	pNode pos = NULL;
	InitLinkList(&list);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PushBack(&list, 2);
	PushBack(&list, 2);
	PushBack(&list, 1);
	PrintLinkList(&list);
	Remove(&list, 1);
	PrintLinkList(&list);
}
void TestRemoveAll()
{
	pLinkList list;
	pNode pos = NULL;
	InitLinkList(&list);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PushBack(&list, 2);
	PushBack(&list, 2);
	PushBack(&list, 1);
	PrintLinkList(&list);
	RemoveAll(&list, 1);
	PrintLinkList(&list);
}
void TestJosephCircle()
{
	pLinkList list;
	pNode pos = NULL;
	InitLinkList(&list);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PushBack(&list, 5);
	PrintLinkList(&list);
	JosephCircle(&list, 3);
}
void TestGetListLength()
{
	pLinkList list;
	pNode pos = NULL;
	InitLinkList(&list);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PushBack(&list, 2);
	PushBack(&list, 2);
	PushBack(&list, 1);
	PrintLinkList(&list);
	printf("len=%d\n", GetListLength(list));
}
void TestErase()
{
	pLinkList list;
	pNode pos = NULL;
	InitLinkList(&list);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PrintLinkList(&list);
	pos = Find(list, 1);
	Erase(&list, pos);
	PrintLinkList(&list);
}
//void TestFind()
//{
//	pLinkList list;
//	pNode pos = NULL;
//	stack* s;
//	InitStack(s);
//	InitLinkList(&list);
//	PushBack(&list, 1);
//	PushBack(&list, 2);
//	PushBack(&list, 3);
//	PushBack(&list, 4);
//	PrintLinkList(&list);
//	PrintLinkTailToHead(list, s);
	/*pos = Find(list, 3);
	if (pos != NULL)
	{
		printf("%d\n", pos->data);
	}*/
	/*PrintLinkTailToHead(list);*/
//}

void test()
{
	pLinkList list;
	InitLinkList(&list);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PrintLinkList(&list);
	PrintLinkTailToHead(list);
	printf("over\n");
}
void TestBubbleSort()
{
	pLinkList list;
	InitLinkList(&list);
	PushBack(&list, 1);
	PushBack(&list, 5);
	PushBack(&list, 3);
	PushBack(&list, 2);
	PushBack(&list, 6);
	PushBack(&list, 4);
	PrintLinkList(&list);
	BubbleSort(&list);
	PrintLinkList(&list);
}
void TestMerge()
{
	pLinkList list1;
	pLinkList list2;
	pLinkList list;
	InitLinkList(&list1);
	InitLinkList(&list2);
	PushBack(&list1, 1);
	PushBack(&list1, 3);
	PushBack(&list1, 5);
	PushBack(&list2, 2);
	PushBack(&list2, 4);
	PushBack(&list2, 6);
	PrintLinkList(&list1);
	PrintLinkList(&list2);
	list = Merge_R(list1, list2);
	PrintLinkList(&list);
}
void TestFindMidNode()
{
	pNode mid = NULL;
	pLinkList list;
	InitLinkList(&list);
	PushBack(&list, 1);
	PushBack(&list, 3);
	PushBack(&list, 5);
	PrintLinkList(&list);
	mid = FindMidNode(list);
	printf("中间节点为%d\n", mid->data);
}
void TestFindLastKNode()
{
	pLinkList list;
	int k = 3;
	InitLinkList(&list);
	for (int i = 0; i < 10; i++)
	{
		PushBack(&list, i);
	}
	pNode tmp = FindLastKNode(list, k);
	if (tmp != NULL)
	{
		printf("倒数第K个结点为：%d\n", tmp->data);
	}
}
void TestIsCircle()
{
	pLinkList list;
	InitLinkList(&list);
	for (int i = 1; i <= 5; i++)
	{
		PushBack(&list, i);
	}
	Find(list, 5)->next = Find(list, 3);
	pNode pos = IsCircle(list);
	if (pos != NULL)
	{
		printf("相遇点为%d\n", pos->data);
		printf("环的长度为%d\n", GetCircleLength(pos));
		printf("环的入口点为%d\n", GetCircleEntryNode(list, pos)->data);
	}
	else
	{
		printf("没有相遇点\n");
	}
}
void TestIsCross()
{
	pLinkList list1;
	pLinkList list2;
	InitLinkList(&list1);
	InitLinkList(&list2);
	PushBack(&list1, 1);
	PushBack(&list1, 3);
	PushBack(&list1, 5);
	PushBack(&list1, 4);
	PrintLinkList(&list1);
	PushBack(&list2, 2);
	PushBack(&list2, 6);
	PushBack(&list2, 8);
	PushBack(&list2, 7);
	PrintLinkList(&list2);
	Find(list1, 5)->next = Find(list2, 8);
	int ret = IsCross(list1, list2);
	if (0 == ret)
	{
		printf("不相交\n");
	}
	else
	{
		printf("相交\n");
		printf("交点是%d\n", GetMeetNode(list1, list2)->data);
	}
}
void TestUnionSet()
{
	pLinkList list1;
	pLinkList list2;
	InitLinkList(&list1);
	InitLinkList(&list2);
	PushBack(&list1, 1);
	PushBack(&list1, 3);
	PushBack(&list1, 5);
	PushBack(&list1, 6);
	PrintLinkList(&list1);
	PushBack(&list2, 1);
	PushBack(&list2, 3);
	PushBack(&list2, 4);
	PushBack(&list2, 6);
	PrintLinkList(&list2);
	UnionSet(list1, list2);
}
void TestCopyComplexList()
{
	pComplexNode plist = NULL;
	pComplexNode newlist = NULL;
	pComplexNode p1 = BuyComplexNode(5);
	pComplexNode p2 = BuyComplexNode(4);
	pComplexNode p3 = BuyComplexNode(3);
	pComplexNode p4 = BuyComplexNode(2);
	pComplexNode p5 = BuyComplexNode(1);
	plist = p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = NULL;

	p1->random = p3;
	p2->random = p1;
	p3->random = NULL;
	p4->random = p2;
	p5->random = p4;

	PrintComplexList(plist);
	newlist = CopyComplexList(plist);
	PrintComplexList(newlist);
}
void TestListNode()
{
	List lt;
	ListInit(&lt);
	/*ListPushBack(&lt, 1);
	ListPushBack(&lt, 2);
	ListPushBack(&lt, 3);
	ListPushBack(&lt, 4);*/
	printf("%d\n", ListEmpty(&lt));
	ListPushFront(&lt, 1);
	ListPushFront(&lt, 2);
	ListPushFront(&lt, 3);
	ListPushFront(&lt, 4);
	ListNode* cur = FindListNode(&lt, 2);
	ListInsert(cur, 5);
	printf("%d\n", ListSize(&lt));
	printf("%d\n", ListEmpty(&lt));
	/*ListErase(cur);*/
	/*ListPopBack(&lt);
	ListPopFront(&lt);*/
	ListPrint(&lt);
	ListDestory(&lt);
}
int main()
{
	/*test();*/
	/*TestFind();*/
	/*TestRmoveNodeNotTail();*/
	/*TestInsertNodeNotHead();*/
	/*TestReverselist();*/
	/*TestPopBack();*/
	/*TestPushFront();*/
	/*TestPopFront();*/
	/*TestInsert();*/
	/*TestErase();*/
	/*TestRemove();*/
	//TestRemoveAll();
	/*TestGetListLength();*/
	/*TestJosephCircle();*/
	/*TestFind();*/
	/*TestBubbleSort();*/
	/*TestMerge();*/
	/*TestFindMidNode();*/
	/*TestFindLastKNode();*/
	/*TestIsCircle();*/
	/*TestIsCross();*/
	/*TestUnionSet();*/
	/*TestCopyComplexList();*/
	TestListNode();
	return 0;
}