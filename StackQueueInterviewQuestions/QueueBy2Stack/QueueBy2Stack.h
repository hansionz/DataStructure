#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;
//����ջ�ṹ
typedef struct Stack
{
	DataType *_a;
	int _top;//ջ��
	int _capacity;//����
}Stack;

typedef struct QueueBy2Stack
{
	Stack input;//ʵ����ӵ�ջ
	Stack output;//ʵ�ֳ��ӵ�ջ
	int size; //���е���ЧԪ�ظ���
}QueueBy2Stack;

//��ʼ������
void QueueInit(QueueBy2Stack* pq);
//���ٺ���
void QueueDestroy(QueueBy2Stack* pq);
//��Ӻ���
void QueuePush(QueueBy2Stack* pq, DataType x);
//���Ӻ���
void QueuePop(QueueBy2Stack* pq);
//ȡ��ͷԪ�غ���
DataType QueueFront(QueueBy2Stack*pq);