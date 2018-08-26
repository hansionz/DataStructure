#ifndef __BSTREE_H__
#define __BSTREE_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#pragma warning(disable:4996)

typedef int BSTDataType;

//定义二叉搜索树结点类型
typedef struct BSTreeNode
{
	BSTDataType _data;
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
}BSTreeNode;

//向二叉搜索树中插入一个值
int BSTreeInsert(BSTreeNode** root, BSTDataType x);
//向二叉搜索树中插入一个值(递归)
int BSTreeInsertR(BSTreeNode** root, BSTDataType x);
//删除一个结点
int BSTreeRemove(BSTreeNode** root, BSTDataType x);
//删除一个结点(递归)
int BSTreeRemoveR(BSTreeNode** root, BSTDataType x);
//查找一个结点
BSTreeNode* BSTreeFind(BSTreeNode** root, BSTDataType x);
//查找一个结点(递归)
BSTreeNode* BSTreeFindR(BSTreeNode** root, BSTDataType x);
//中序遍历二叉搜索树(序列递增)
void BSTreeInOrder(BSTreeNode** root);

/*****************************************************************/
/*key-value模式*/

typedef char* BSTKeyType;//key类型(字符串)
typedef int BSTValueType;//value类型(计数用的为整型)
//定义二叉搜索树结点类型
typedef struct BSTKeyValueNode
{
	BSTKeyType _key;
	BSTValueType _value;
	struct BSTKeyValueNode* _left;
	struct BSTKeyValueNode* _right;
}BSTKeyValueNode;
//插入一个结点
int BSTKVInsert(BSTKeyValueNode** kvroot, BSTKeyType key, BSTValueType value);
//在树中找一个结点
BSTKeyValueNode* BSTKVFind(BSTKeyValueNode** kvroot, BSTKeyType key);
//中序遍历(方便测试使用)
void BSTKVInorder(BSTKeyValueNode** kvroot);

#endif //__BSTREE_H__