#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//栈
typedef struct BinaryTreeNode* DataType;
//定义栈结构
typedef struct Stack
{
	DataType *_a;
	int _top;//栈顶
	int _capacity;//容量
}Stack;
//队列
typedef struct BinaryTreeNode* QDataType;
//定义队列结点类型
typedef struct QueueNode
{
	struct QueueNode* _next;
	QDataType _data;
}QueueNode;

//定义队列类型
typedef struct Queue
{
	QueueNode* front;//队头
	QueueNode* rear;//队尾
}Queue;
//二叉树
typedef char BTDataType;	
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;
//创建一个二叉树结点
BTNode* BuyBTNode(BTDataType x);
//创建一颗二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int *pi);
//销毁二叉树
void BinaryTreeDestroy(BTNode** newnode);
//二叉树结点个数(递归版本)
int BinaryTreeSize(BTNode* root);
//二叉树结点个数(设置全局变量，遍历一遍二叉树累加)
void BinaryTreeSize_C(BTNode* root);
//叶子节点个数
int BinaryTreeLeafSzie(BTNode* root);
//叶子结点个数(设置全局变量，遍历一遍二叉树符合条件则累加)
void BinaryTreeLeafSzie_C(BTNode* root);
//判断一个结点是否在二叉树里，如果在返回指针，如果不在返回NULL
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
//二叉树的高度
int BinaryTreeHigh(BTNode* root);
//判断二叉树是不是完全二叉树(是返回1,不是返回0)
int BinaryTreeIsCompleteTree(BTNode* root);
//返回结点的双亲结点
BTNode* BinaryTreeFindParent(BTNode* root, BTDataType x);
//第k层结点的个数
int BinaryTreeLevelKSize(BTNode* root, int k);
//先序遍历(递归版本)
void BinaryTreePrevOrder_R(BTNode* root);
//中序遍历(递归版本)
void BinaryTreeMidOrder_R(BTNode* root);
//后序遍历(递归版本)
void BinaryTreePostOrder_R(BTNode* root);
//先序遍历
void BinaryTreePrevOrder(BTNode* root);
//中序遍历
void BinaryTreeMidOrder(BTNode* root);
//后序遍历
void BinaryTreePostOrder(BTNode* root);
//层次遍历
void BinaryTreeLevelOrder(BTNode* root);
//求二叉树的镜像(交换左右子树)
void BinaryTreeSwapSub_R(BTNode* root);

void BinaryTreeSwapSub(BTNode* root);
#endif //__BINARYTREE_H__