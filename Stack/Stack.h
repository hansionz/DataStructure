#ifndef __STACK_H__
#define __STACK_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
typedef char DataType;
//定义栈结构
typedef struct Stack
{
	DataType *_a;
	int _top;//栈顶
	int _capacity;//容量
}Stack;

//初始化栈
void StackInit(Stack* ps);
//销毁栈
void StackDestroy(Stack* ps);
//入栈
void StackPush(Stack* ps, DataType x);
//出栈
void StackPop(Stack* ps);
//取栈顶元素
DataType StackTop(Stack* ps);
//判断栈是否为空，空返回0，非空返回1
int StackEmpty(Stack* ps);
//求栈的大小
int StackSize(Stack* ps);

/*******************************************************************************/
/*链表面试题*/
//4.元素出栈、入栈顺序的合法性
int CheckLegal(int* num_in, int* num_out, int len_in, int len_out);
/*******************************************************************************/
//1.获取最小值(O(1))
typedef struct GetMinStack
{
	Stack _mst;
	Stack _msmin;
}GetMinStack;

DataType GetMinValue(GetMinStack* ps);
//入栈操作
void Stack_O1Push(GetMinStack* ps, DataType x);
//出栈操作
void Stack_O1Pop(GetMinStack* ps);
//取栈顶元素
DataType GetStack_O1Top(GetMinStack* ps);

//5.一个数组实现一个共享栈
#define MAXSIZE 10
typedef struct StackShare
{
	DataType _a[MAXSIZE];
	int top_low;//左栈栈顶
	int top_high;//右栈栈顶
}StackShare;
//初始化栈
void StackShareInit(StackShare* ps);
//销毁栈
void StackShareDestroy(StackShare* ps, char c);
//检查栈是否满
int StackIsFull(StackShare* ps);
//检查共享栈是否为空
int StackShareEmpty(StackShare* ps, char c);
//求栈的大小
int StackShareSize(StackShare* ps, char c);
//入栈操作
void StackSharePush(StackShare* ps, DataType x, char c);
//出栈操作
void StackSharePop(StackShare* ps, char c);
//取栈顶元素
DataType StackShareTop(StackShare* ps, char c);
/******************************************************/
/*5.一个数组实现一个共享栈(奇偶栈)*/
typedef struct ShareStack
{
	DataType* _a;
	int _top_l;//左栈栈顶
	int _top_r;//右栈栈顶
	int capacity;//容量
}ShareStack;
//初始换共享栈
void ShareStackInit(ShareStack* ps);
//销毁共享栈
void ShareStackDestroy(ShareStack* ps, char c);
//入栈
void ShareStackPush(ShareStack* ps, DataType x, char c);
//出栈
void ShareStackPop(ShareStack* ps, char c);
//取栈顶元素
DataType ShareStackTop(ShareStack* ps, char c);
//判断栈是否为空(为空返回0，非空返回1)
int ShareStackEmpty(ShareStack* ps, char c);
//求栈的大小
int ShareStackSize(ShareStack* ps, char c);
#endif //__STACK_H__