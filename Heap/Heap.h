#ifndef __HEAP_H__
#define __HEAP_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//定义堆结构(动态线性表实现)
typedef int HTDataType;
typedef struct Heap
{
	HTDataType* _a;
	int _size;
	int _capacity;
}Heap;

//初始化堆
void HeapInit(Heap* hp, HTDataType* a, int n);
//堆的销毁(释放malloc出来的空间)
void HeapDestory(Heap* hp);
//向堆里插入一个数据
void HeapPush(Heap* hp, HTDataType x);
//弹出堆顶的数据
void HeapPop(Heap* hp);
//取堆顶数据
HTDataType HeapTop(Heap* hp);
//堆的大小
int HeapSize(Heap* hp);
//判断堆是否为空(空返回0，非空返回1)
int HeapEmpty(Heap* hp);
//向下调堆
void AdjustDown(HTDataType* a, int n, int parent);
//向上调堆
void AdjustUp(HTDataType* a, int n, int child);

//堆排序
void HeapSort(HTDataType* a, int n);

#endif __HEAP_H__
