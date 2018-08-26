#ifndef __HEAP_H__
#define __HEAP_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//����ѽṹ(��̬���Ա�ʵ��)
typedef int HTDataType;
typedef struct Heap
{
	HTDataType* _a;
	int _size;
	int _capacity;
}Heap;

//��ʼ����
void HeapInit(Heap* hp, HTDataType* a, int n);
//�ѵ�����(�ͷ�malloc�����Ŀռ�)
void HeapDestory(Heap* hp);
//��������һ������
void HeapPush(Heap* hp, HTDataType x);
//�����Ѷ�������
void HeapPop(Heap* hp);
//ȡ�Ѷ�����
HTDataType HeapTop(Heap* hp);
//�ѵĴ�С
int HeapSize(Heap* hp);
//�ж϶��Ƿ�Ϊ��(�շ���0���ǿշ���1)
int HeapEmpty(Heap* hp);
//���µ���
void AdjustDown(HTDataType* a, int n, int parent);
//���ϵ���
void AdjustUp(HTDataType* a, int n, int child);

//������
void HeapSort(HTDataType* a, int n);

#endif __HEAP_H__
