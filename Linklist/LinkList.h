#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef int DataType;
#define MAXSIZE 100

typedef struct stack
{
	DataType data[MAXSIZE];
	int top;//指向栈顶的指针
}stack;

typedef struct Node
{
	DataType data;
	struct Node *next;
}Node,*pNode,LinkList,*pLinkList;

typedef struct ComplexNode
{
	DataType data;//数据域
	struct ComplexNode* next;//指向下一个结点
	struct ComplexNode* random;//指向链表中的随机结点或者为空
}ComNode,*pComplexNode;

//初始化链表
void InitLinkList(pLinkList *ppl);
//尾插
void PushBack(pLinkList *ppl, DataType data);
//尾删
void PopBack(pLinkList* ppl);
//打印链表
void PrintLinkList(pLinkList *ppl);
//寻找某一节点
pNode Find(pLinkList plist, DataType data);
//在指定位置前插入结点
void InsertNodeNotHead(pLinkList *ppl, DataType data, pNode pos);
//头插
void PushFront(pLinkList * ppl, DataType data);
//头删
void PopFront(pLinkList* ppl);
//在指定位置前插入结点
void Insert(pLinkList* ppl, pNode pos, DataType data);
//在指定位置删除结点
void Erase(pLinkList* ppl, pNode pos);
//删除指定数据的第一个结点
void Remove(pLinkList* ppl, DataType data);
//删除指定数据的所有结点
void RemoveAll(pLinkList* ppl, DataType data);
//求链表的长度
int GetListLength(pLinkList pl);
//销毁链表
void DestoryList(pLinkList *ppl);
//从尾到头打印链表
void PrintLinkTailToHead(pLinkList pl);
//删除一个无头单链表的非尾结点
void RmoveNodeNotTail(pLinkList *ppl, pNode pos);
//用链表实现约瑟夫环
void JosephCircle(pLinkList *ppl, int sz);
//链表的逆置
pNode Reverselist_op(pLinkList *ppl);
//链表的冒泡排序
void BubbleSort(pLinkList *ppl);
//合并两个有序的链表，合并后依然有序
pNode Merge(pLinkList list1, pLinkList list2);
//合并两个有序的链表(递归版本)
pNode Merge_R(pLinkList list1, pLinkList list2);
//求单链表中间结点
pNode FindMidNode(pLinkList plist);
//求单链表倒数第K个结点
pNode FindLastKNode(pLinkList plist, int k);
//判断链表是否带环，带环返回相遇点，不带环返回NULL
pNode IsCircle(pLinkList plist);
//求环的长度
int GetCircleLength(pNode meet);
//求环的入口点
pNode GetCircleEntryNode(pLinkList plist, pNode meet);
//判断链表是否相交(假设链表不带环)，相交返回1，不想交返回0
int IsCross(pLinkList plist1, pLinkList plist2);
//求两个链表的交点
pNode GetMeetNode(pLinkList plist1, pLinkList plist2);
//求两个链表中相同的数据(交集)
void UnionSet(pLinkList plist1, pLinkList plist2);
//删除无序链表中的第二大结点，不能排序
int FindSecondNode(pLinkList plist);
void DeleteNode(pLinkList plist, int max2);
/********************************************************/
/*LeetCode*/
//链表的隔断插入
void ListInsertConstant(pLinkList pl);
/********************************************************/
/*复杂链表的复制*/
//复杂链表的复制
pComplexNode CopyComplexList(pComplexNode plist);
//开辟一个数据域为d的复杂结点
pComplexNode BuyComplexNode(DataType d);
//打印复杂链表
void PrintComplexList(pComplexNode plist);
/************************************************************/
/*双向带头循环链表*/
typedef int CLDataType;
//结点类型
typedef struct ListNode
{
	CLDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
//链表的头
typedef struct List
{
	ListNode* _head;
}List;
//初始化双向循环带头链表
void ListInit(List* pcl);
//销毁双向循环带头链表
void ListDestory(List* pcl);
//尾插
void ListPushBack(List* pcl, CLDataType x);
//头插
void ListPushFront(List* pcl, CLDataType x);
//指定位置插入结点 
void ListInsert(ListNode* pos, CLDataType x);
//尾删
void ListPopBack(List* pcl);
//头删
void ListPopFront(List* pcl);
//指定位置删除(不能是头结点)
void ListErase(List* pcl, ListNode* pos);
//遍历打印链表
void ListPrint(List* pcl);
//链表的长度
int ListSize(List* pcl);
//判断链表是否为空(为空返回0，非空返回1)
int ListEmpty(List* pcl);
//寻找指定数据的结点(找到返回地址，找不到返回NULL)
ListNode* FindListNode(List* pcl, CLDataType x);
//创建一个双向循环链表结点
ListNode* BuyListNode(CLDataType x);

#endif //__LINKLIST_H__