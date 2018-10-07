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
	int top;//ָ��ջ����ָ��
}stack;

typedef struct Node
{
	DataType data;
	struct Node *next;
}Node,*pNode,LinkList,*pLinkList;

typedef struct ComplexNode
{
	DataType data;//������
	struct ComplexNode* next;//ָ����һ�����
	struct ComplexNode* random;//ָ�������е����������Ϊ��
}ComNode,*pComplexNode;

//��ʼ������
void InitLinkList(pLinkList *ppl);
//β��
void PushBack(pLinkList *ppl, DataType data);
//βɾ
void PopBack(pLinkList* ppl);
//��ӡ����
void PrintLinkList(pLinkList *ppl);
//Ѱ��ĳһ�ڵ�
pNode Find(pLinkList plist, DataType data);
//��ָ��λ��ǰ������
void InsertNodeNotHead(pLinkList *ppl, DataType data, pNode pos);
//ͷ��
void PushFront(pLinkList * ppl, DataType data);
//ͷɾ
void PopFront(pLinkList* ppl);
//��ָ��λ��ǰ������
void Insert(pLinkList* ppl, pNode pos, DataType data);
//��ָ��λ��ɾ�����
void Erase(pLinkList* ppl, pNode pos);
//ɾ��ָ�����ݵĵ�һ�����
void Remove(pLinkList* ppl, DataType data);
//ɾ��ָ�����ݵ����н��
void RemoveAll(pLinkList* ppl, DataType data);
//������ĳ���
int GetListLength(pLinkList pl);
//��������
void DestoryList(pLinkList *ppl);
//��β��ͷ��ӡ����
void PrintLinkTailToHead(pLinkList pl);
//ɾ��һ����ͷ������ķ�β���
void RmoveNodeNotTail(pLinkList *ppl, pNode pos);
//������ʵ��Լɪ��
void JosephCircle(pLinkList *ppl, int sz);
//���������
pNode Reverselist_op(pLinkList *ppl);
//�����ð������
void BubbleSort(pLinkList *ppl);
//�ϲ���������������ϲ�����Ȼ����
pNode Merge(pLinkList list1, pLinkList list2);
//�ϲ��������������(�ݹ�汾)
pNode Merge_R(pLinkList list1, pLinkList list2);
//�������м���
pNode FindMidNode(pLinkList plist);
//����������K�����
pNode FindLastKNode(pLinkList plist, int k);
//�ж������Ƿ�������������������㣬����������NULL
pNode IsCircle(pLinkList plist);
//�󻷵ĳ���
int GetCircleLength(pNode meet);
//�󻷵���ڵ�
pNode GetCircleEntryNode(pLinkList plist, pNode meet);
//�ж������Ƿ��ཻ(������������)���ཻ����1�����뽻����0
int IsCross(pLinkList plist1, pLinkList plist2);
//����������Ľ���
pNode GetMeetNode(pLinkList plist1, pLinkList plist2);
//��������������ͬ������(����)
void UnionSet(pLinkList plist1, pLinkList plist2);
//ɾ�����������еĵڶ����㣬��������
int FindSecondNode(pLinkList plist);
void DeleteNode(pLinkList plist, int max2);
/********************************************************/
/*LeetCode*/
//����ĸ��ϲ���
void ListInsertConstant(pLinkList pl);
/********************************************************/
/*��������ĸ���*/
//��������ĸ���
pComplexNode CopyComplexList(pComplexNode plist);
//����һ��������Ϊd�ĸ��ӽ��
pComplexNode BuyComplexNode(DataType d);
//��ӡ��������
void PrintComplexList(pComplexNode plist);
/************************************************************/
/*˫���ͷѭ������*/
typedef int CLDataType;
//�������
typedef struct ListNode
{
	CLDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
//�����ͷ
typedef struct List
{
	ListNode* _head;
}List;
//��ʼ��˫��ѭ����ͷ����
void ListInit(List* pcl);
//����˫��ѭ����ͷ����
void ListDestory(List* pcl);
//β��
void ListPushBack(List* pcl, CLDataType x);
//ͷ��
void ListPushFront(List* pcl, CLDataType x);
//ָ��λ�ò����� 
void ListInsert(ListNode* pos, CLDataType x);
//βɾ
void ListPopBack(List* pcl);
//ͷɾ
void ListPopFront(List* pcl);
//ָ��λ��ɾ��(������ͷ���)
void ListErase(List* pcl, ListNode* pos);
//������ӡ����
void ListPrint(List* pcl);
//����ĳ���
int ListSize(List* pcl);
//�ж������Ƿ�Ϊ��(Ϊ�շ���0���ǿշ���1)
int ListEmpty(List* pcl);
//Ѱ��ָ�����ݵĽ��(�ҵ����ص�ַ���Ҳ�������NULL)
ListNode* FindListNode(List* pcl, CLDataType x);
//����һ��˫��ѭ��������
ListNode* BuyListNode(CLDataType x);

#endif //__LINKLIST_H__