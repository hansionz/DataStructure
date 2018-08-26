#ifndef __STACK_H__
#define __STACK_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
typedef char DataType;
//����ջ�ṹ
typedef struct Stack
{
	DataType *_a;
	int _top;//ջ��
	int _capacity;//����
}Stack;

//��ʼ��ջ
void StackInit(Stack* ps);
//����ջ
void StackDestroy(Stack* ps);
//��ջ
void StackPush(Stack* ps, DataType x);
//��ջ
void StackPop(Stack* ps);
//ȡջ��Ԫ��
DataType StackTop(Stack* ps);
//�ж�ջ�Ƿ�Ϊ�գ��շ���0���ǿշ���1
int StackEmpty(Stack* ps);
//��ջ�Ĵ�С
int StackSize(Stack* ps);

/*******************************************************************************/
/*����������*/
//4.Ԫ�س�ջ����ջ˳��ĺϷ���
int CheckLegal(int* num_in, int* num_out, int len_in, int len_out);
/*******************************************************************************/
//1.��ȡ��Сֵ(O(1))
typedef struct GetMinStack
{
	Stack _mst;
	Stack _msmin;
}GetMinStack;

DataType GetMinValue(GetMinStack* ps);
//��ջ����
void Stack_O1Push(GetMinStack* ps, DataType x);
//��ջ����
void Stack_O1Pop(GetMinStack* ps);
//ȡջ��Ԫ��
DataType GetStack_O1Top(GetMinStack* ps);

//5.һ������ʵ��һ������ջ
#define MAXSIZE 10
typedef struct StackShare
{
	DataType _a[MAXSIZE];
	int top_low;//��ջջ��
	int top_high;//��ջջ��
}StackShare;
//��ʼ��ջ
void StackShareInit(StackShare* ps);
//����ջ
void StackShareDestroy(StackShare* ps, char c);
//���ջ�Ƿ���
int StackIsFull(StackShare* ps);
//��鹲��ջ�Ƿ�Ϊ��
int StackShareEmpty(StackShare* ps, char c);
//��ջ�Ĵ�С
int StackShareSize(StackShare* ps, char c);
//��ջ����
void StackSharePush(StackShare* ps, DataType x, char c);
//��ջ����
void StackSharePop(StackShare* ps, char c);
//ȡջ��Ԫ��
DataType StackShareTop(StackShare* ps, char c);
/******************************************************/
/*5.һ������ʵ��һ������ջ(��żջ)*/
typedef struct ShareStack
{
	DataType* _a;
	int _top_l;//��ջջ��
	int _top_r;//��ջջ��
	int capacity;//����
}ShareStack;
//��ʼ������ջ
void ShareStackInit(ShareStack* ps);
//���ٹ���ջ
void ShareStackDestroy(ShareStack* ps, char c);
//��ջ
void ShareStackPush(ShareStack* ps, DataType x, char c);
//��ջ
void ShareStackPop(ShareStack* ps, char c);
//ȡջ��Ԫ��
DataType ShareStackTop(ShareStack* ps, char c);
//�ж�ջ�Ƿ�Ϊ��(Ϊ�շ���0���ǿշ���1)
int ShareStackEmpty(ShareStack* ps, char c);
//��ջ�Ĵ�С
int ShareStackSize(ShareStack* ps, char c);
#endif //__STACK_H__