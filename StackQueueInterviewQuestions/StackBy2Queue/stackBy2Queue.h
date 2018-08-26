#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;
//������н������
typedef struct QueueNode
{
	struct QueueNode* _next;
	DataType _data;
}QueueNode;
//�����������
typedef struct Queue
{
	QueueNode* front;//��ͷ
	QueueNode* rear;//��β
}Queue;

typedef struct StackBy2Queue
{
	Queue queue1;
	Queue queue2;
	int size;
}StackBy2Queue;

//��ʼ������
void StackInit(StackBy2Queue* ps);
//���ٺ���
void StackDestroy(StackBy2Queue* ps);
//��ջ��������
void StackPush(StackBy2Queue* ps, DataType x);
//��ջ��������
void StackPop(StackBy2Queue* ps);
//ȡջ��Ԫ�غ���
DataType StackGetTop(StackBy2Queue* ps);