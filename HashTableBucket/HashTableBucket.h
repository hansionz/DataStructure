#ifndef __HASHTABLEBUCKET_H__
#define __HASHTABLEBUCKET_H__

#include"Commet.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef char* HTBKeyType;
typedef char* HTBValueType;

//哈希表中结点的类型(拉链法)
typedef struct HashNode
{
	struct HashNode* _next;
	HTBKeyType _key;
	HTBValueType _vaule;//key-value模型
}HashNode;
//哈希表的类型
typedef struct HashTableBucket
{
	HashNode** _table;//动态数组，里边存放的是指向结点的指针
	int _len;//哈希表长度
	int _size;//有效元素的个数
}HTB;
//初始化
void HTBInit(HTB* htb, size_t len);
//销毁哈希表
void HTBDestory(HTB* htb);
//向哈希表中插入一个元素
int HTBInsert(HTB* htb, HTBKeyType key, HTBValueType value);
//删除哈希表中的一个元素
int HTBRemove(HTB* htb, HTBKeyType key);
//在哈希表中查找一个元素
HashNode* HTBFind(HTB* htb, HTBKeyType key);
//哈希表的大小
int HTBSize(HTB* htb);
//哈希表是否为空
int HTBEmpty(HTB* htb);

#endif //__HASHTABLEBUCKET_H__