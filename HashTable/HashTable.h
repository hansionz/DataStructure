#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int HTKeyType;
typedef char HTValueType;
//枚举哈希表中每一个数据的三种状态
typedef enum State
{
	EMPTY,//空
	EXITST,//存在数据
	DELETE//已被删除
}State;
//定义哈希表中数据类型
typedef struct HashData
{
	State _state;//状态
	HTKeyType _key;//key-value
	HTValueType _value;//key-value
}HashData;
//定义哈希表的结构
typedef struct HashTable
{
	HashData* _table;//动态数组实现
	int _len;//表长
	int _size;//有效元素的个数
}HashTable;

//哈希表的初始化
void HashTableInit(HashTable* ht, size_t len);
//销毁哈希表(malloc出来的空间)
void HashTableDestroy(HashTable* ht);
//向哈希表中插入一个值
int HashTableInsert(HashTable* ht, HTKeyType key, HTValueType value);
//在哈希表中删除一个值
int HashTableRemove(HashTable* ht, HTKeyType key);
//在哈希表中查找一个值
HashData* HashTableFind(HashTable* ht, HTKeyType key);
//判断哈希表是否为空(空返回0，非空返回1)
int HashTableEmpty(HashTable* ht);
//哈希表的有效元素个数
int HashTableSize(HashTable* ht);
//打印哈希表中的数据
void PrintHashTable(HashTable* ht);

#endif //__HASHTABLE_H__