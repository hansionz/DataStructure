#ifndef __BSTREE_H__
#define __BSTREE_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#pragma warning(disable:4996)

typedef int BSTDataType;

//��������������������
typedef struct BSTreeNode
{
	BSTDataType _data;
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
}BSTreeNode;

//������������в���һ��ֵ
int BSTreeInsert(BSTreeNode** root, BSTDataType x);
//������������в���һ��ֵ(�ݹ�)
int BSTreeInsertR(BSTreeNode** root, BSTDataType x);
//ɾ��һ�����
int BSTreeRemove(BSTreeNode** root, BSTDataType x);
//ɾ��һ�����(�ݹ�)
int BSTreeRemoveR(BSTreeNode** root, BSTDataType x);
//����һ�����
BSTreeNode* BSTreeFind(BSTreeNode** root, BSTDataType x);
//����һ�����(�ݹ�)
BSTreeNode* BSTreeFindR(BSTreeNode** root, BSTDataType x);
//�����������������(���е���)
void BSTreeInOrder(BSTreeNode** root);

/*****************************************************************/
/*key-valueģʽ*/

typedef char* BSTKeyType;//key����(�ַ���)
typedef int BSTValueType;//value����(�����õ�Ϊ����)
//��������������������
typedef struct BSTKeyValueNode
{
	BSTKeyType _key;
	BSTValueType _value;
	struct BSTKeyValueNode* _left;
	struct BSTKeyValueNode* _right;
}BSTKeyValueNode;
//����һ�����
int BSTKVInsert(BSTKeyValueNode** kvroot, BSTKeyType key, BSTValueType value);
//��������һ�����
BSTKeyValueNode* BSTKVFind(BSTKeyValueNode** kvroot, BSTKeyType key);
//�������(�������ʹ��)
void BSTKVInorder(BSTKeyValueNode** kvroot);

#endif //__BSTREE_H__