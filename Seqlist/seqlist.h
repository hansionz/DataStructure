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

//初始化
void InitSeqList(pSeqList ps);
//尾部插入
void PushBack(pSeqList ps, DataType data);
//尾部删除
void PopBack(pSeqList ps);
//头部插入
void PushFront(pSeqList ps, DataType data);
//头部删除
void PopFront(pSeqList ps);
//查找指定元素
int Find(pSeqList ps, DataType data);
//在指定位置插入指定元素
void Insert(pSeqList ps, DataType data, int pos);
//删除指定位置的元素
void Erase(pSeqList ps, int pos);
//删除指定元素
void Remove(pSeqList ps, DataType data);
//删除指定的所有元素
void RemoveAll(pSeqList ps, DataType data);
//顺序表的大小
int Size(pSeqList ps);
//判断顺序表是否为空
int Empty(pSeqList ps);
//对顺序的元素进行冒泡排序
void BubbleSort(pSeqList ps);
//选择排序
void SelectSort(pSeqList ps);
//优化选择排序(最小值和最大值)
void SelectSort_op(pSeqList ps);
//二分查找指定元素
int BinarySearch(pSeqList ps, DataType data);
//递归二分查找
int BinarySearch_D(pSeqList ps, int left,int right,DataType data);
//打印顺序表
void PrintSeqList(pSeqList ps);

#endif //__SEQLIST_H__