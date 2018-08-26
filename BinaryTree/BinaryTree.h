#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//ջ
typedef struct BinaryTreeNode* DataType;
//����ջ�ṹ
typedef struct Stack
{
	DataType *_a;
	int _top;//ջ��
	int _capacity;//����
}Stack;
//����
typedef struct BinaryTreeNode* QDataType;
//������н������
typedef struct QueueNode
{
	struct QueueNode* _next;
	QDataType _data;
}QueueNode;

//�����������
typedef struct Queue
{
	QueueNode* front;//��ͷ
	QueueNode* rear;//��β
}Queue;
//������
typedef char BTDataType;	
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;
//����һ�����������
BTNode* BuyBTNode(BTDataType x);
//����һ�Ŷ�����
BTNode* BinaryTreeCreate(BTDataType* a, int n, int *pi);
//���ٶ�����
void BinaryTreeDestroy(BTNode** newnode);
//������������(�ݹ�汾)
int BinaryTreeSize(BTNode* root);
//������������(����ȫ�ֱ���������һ��������ۼ�)
void BinaryTreeSize_C(BTNode* root);
//Ҷ�ӽڵ����
int BinaryTreeLeafSzie(BTNode* root);
//Ҷ�ӽ�����(����ȫ�ֱ���������һ������������������ۼ�)
void BinaryTreeLeafSzie_C(BTNode* root);
//�ж�һ������Ƿ��ڶ����������ڷ���ָ�룬������ڷ���NULL
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
//�������ĸ߶�
int BinaryTreeHigh(BTNode* root);
//�ж϶������ǲ�����ȫ������(�Ƿ���1,���Ƿ���0)
int BinaryTreeIsCompleteTree(BTNode* root);
//���ؽ���˫�׽��
BTNode* BinaryTreeFindParent(BTNode* root, BTDataType x);
//��k����ĸ���
int BinaryTreeLevelKSize(BTNode* root, int k);
//�������(�ݹ�汾)
void BinaryTreePrevOrder_R(BTNode* root);
//�������(�ݹ�汾)
void BinaryTreeMidOrder_R(BTNode* root);
//�������(�ݹ�汾)
void BinaryTreePostOrder_R(BTNode* root);
//�������
void BinaryTreePrevOrder(BTNode* root);
//�������
void BinaryTreeMidOrder(BTNode* root);
//�������
void BinaryTreePostOrder(BTNode* root);
//��α���
void BinaryTreeLevelOrder(BTNode* root);
//��������ľ���(������������)
void BinaryTreeSwapSub_R(BTNode* root);

void BinaryTreeSwapSub(BTNode* root);
#endif //__BINARYTREE_H__