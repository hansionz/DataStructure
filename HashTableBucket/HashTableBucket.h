#ifndef __HASHTABLEBUCKET_H__
#define __HASHTABLEBUCKET_H__

#include"Commet.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef char* HTBKeyType;
typedef char* HTBValueType;

//��ϣ���н�������(������)
typedef struct HashNode
{
	struct HashNode* _next;
	HTBKeyType _key;
	HTBValueType _vaule;//key-valueģ��
}HashNode;
//��ϣ�������
typedef struct HashTableBucket
{
	HashNode** _table;//��̬���飬��ߴ�ŵ���ָ�����ָ��
	int _len;//��ϣ����
	int _size;//��ЧԪ�صĸ���
}HTB;
//��ʼ��
void HTBInit(HTB* htb, size_t len);
//���ٹ�ϣ��
void HTBDestory(HTB* htb);
//���ϣ���в���һ��Ԫ��
int HTBInsert(HTB* htb, HTBKeyType key, HTBValueType value);
//ɾ����ϣ���е�һ��Ԫ��
int HTBRemove(HTB* htb, HTBKeyType key);
//�ڹ�ϣ���в���һ��Ԫ��
HashNode* HTBFind(HTB* htb, HTBKeyType key);
//��ϣ��Ĵ�С
int HTBSize(HTB* htb);
//��ϣ���Ƿ�Ϊ��
int HTBEmpty(HTB* htb);

#endif //__HASHTABLEBUCKET_H__