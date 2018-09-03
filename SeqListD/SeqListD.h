#ifndef __SEQLISTD_H__
#define __SEQLISTD_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define DEFAULT_SZ 3
typedef int DataType;

typedef struct SeqListD
{
	DataType *data;
	int sz;
	int capacity;
}SeqList,*pSeqList;

void InitSeqList(pSeqList ps);
void DestorySeqList(pSeqList ps);
void PushBack(pSeqList ps, DataType data);
void PopBack(pSeqList ps);
int Empty(pSeqList ps);
void PrintSeqList(pSeqList ps);

#endif  //__SEQLISTD_H__