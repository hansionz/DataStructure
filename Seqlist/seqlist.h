#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef int DataType;
#define MAX 100

typedef struct SeqList
{
	DataType data[MAX];
	int sz;
}SeqList,*pSeqList;

//��ʼ��
void InitSeqList(pSeqList ps);
//β������
void PushBack(pSeqList ps, DataType data);
//β��ɾ��
void PopBack(pSeqList ps);
//ͷ������
void PushFront(pSeqList ps, DataType data);
//ͷ��ɾ��
void PopFront(pSeqList ps);
//����ָ��Ԫ��
int Find(pSeqList ps, DataType data);
//��ָ��λ�ò���ָ��Ԫ��
void Insert(pSeqList ps, DataType data, int pos);
//ɾ��ָ��λ�õ�Ԫ��
void Erase(pSeqList ps, int pos);
//ɾ��ָ��Ԫ��
void Remove(pSeqList ps, DataType data);
//ɾ��ָ��������Ԫ��
void RemoveAll(pSeqList ps, DataType data);
//˳���Ĵ�С
int Size(pSeqList ps);
//�ж�˳����Ƿ�Ϊ��
int Empty(pSeqList ps);
//��˳���Ԫ�ؽ���ð������
void BubbleSort(pSeqList ps);
//ѡ������
void SelectSort(pSeqList ps);
//�Ż�ѡ������(��Сֵ�����ֵ)
void SelectSort_op(pSeqList ps);
//���ֲ���ָ��Ԫ��
int BinarySearch(pSeqList ps, DataType data);
//�ݹ���ֲ���
int BinarySearch_D(pSeqList ps, int left,int right,DataType data);
//��ӡ˳���
void PrintSeqList(pSeqList ps);

#endif //__SEQLIST_H__