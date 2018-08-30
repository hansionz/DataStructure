#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int HTKeyType;
typedef char HTValueType;
//ö�ٹ�ϣ����ÿһ�����ݵ�����״̬
typedef enum State
{
	EMPTY,//��
	EXITST,//��������
	DELETE//�ѱ�ɾ��
}State;
//�����ϣ������������
typedef struct HashData
{
	State _state;//״̬
	HTKeyType _key;//key-value
	HTValueType _value;//key-value
}HashData;
//�����ϣ��Ľṹ
typedef struct HashTable
{
	HashData* _table;//��̬����ʵ��
	int _len;//��
	int _size;//��ЧԪ�صĸ���
}HashTable;

//��ϣ��ĳ�ʼ��
void HashTableInit(HashTable* ht, size_t len);
//���ٹ�ϣ��(malloc�����Ŀռ�)
void HashTableDestroy(HashTable* ht);
//���ϣ���в���һ��ֵ
int HashTableInsert(HashTable* ht, HTKeyType key, HTValueType value);
//�ڹ�ϣ����ɾ��һ��ֵ
int HashTableRemove(HashTable* ht, HTKeyType key);
//�ڹ�ϣ���в���һ��ֵ
HashData* HashTableFind(HashTable* ht, HTKeyType key);
//�жϹ�ϣ���Ƿ�Ϊ��(�շ���0���ǿշ���1)
int HashTableEmpty(HashTable* ht);
//��ϣ�����ЧԪ�ظ���
int HashTableSize(HashTable* ht);
//��ӡ��ϣ���е�����
void PrintHashTable(HashTable* ht);

#endif //__HASHTABLE_H__