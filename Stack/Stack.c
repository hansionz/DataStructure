#include"Stack.h"
//初始化栈
void StackInit(Stack* ps)
{
	assert(ps);

	ps->_a = (DataType*)malloc(sizeof(DataType)* 3);
	ps->_top = 0;
	ps->_capacity = 3;
}
//销毁栈
void StackDestroy(Stack* ps)
{
	assert(ps);

	free(ps->_a);
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}
//入栈
void StackPush(Stack* ps, DataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		DataType* tmp = realloc(ps->_a, sizeof(DataType)*(ps->_capacity * 2));
		if (tmp != NULL)
		{
			ps->_a = tmp;
		}
		ps->_capacity = 2 * ps->_capacity;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}
//出栈
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->_top > 0);
	if (StackEmpty(ps))
	{
		ps->_top--;
	}
	else
	{
		return;
	}
}
//取栈顶元素
DataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->_top > 0);

	return ps->_a[ps->_top - 1];
}
//空返回0，非空返回1
int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0 ? 0 : 1;
}
//求栈的大小
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}
/*************************************************************/
/*检查出入栈的合法性，合法返回1，不合法返回0*/
int CheckLegal(int* num_in, int* num_out,int len_in,int len_out)
{
	Stack s;
	StackInit(&s);
	//如果两个出入栈序列长度不相同必然不合法
	if (len_in != len_out)
	{
		return 0;
	}
	assert(num_in);
	assert(num_out);
	int j = 0;
	for (int i = 0; i < len_in; i++)
	{
		StackPush(&s, num_in[i]);
		//栈顶元素和出栈序列相同则出栈一次，出栈序列向后移动一位

		while ((StackEmpty(&s) != 0) && (StackTop(&s) == num_out[j]))
		{
			StackPop(&s);
			j++;
		}
	}
	return StackEmpty(&s) == 0 ? 1 : 0;
}
/***************************************************************/
/*O(1)的时间内找到最小值*/
//使用一个栈，下边压数据，上边压最小值得方法
void Stack_O1Push(Stack* ps,DataType x)
{
	assert(ps);
	if (StackEmpty(ps) == 0)
	{
		StackPush(ps, x);
		StackPush(ps, x);
	}
	else
	{
		DataType min = StackTop(ps);
		if (x < min)
		{
			min = x;
		}
		StackPush(ps, x);
		StackPush(ps, min);
	}
}
void Stack_O1Pop(Stack* ps)
{
	assert(ps);
	StackPop(ps);
	StackPop(ps);
}
//求最小值
DataType GetMinValue(Stack* ps)
{
	assert(ps);
	return StackTop(ps);
}
//获取栈顶元素
DataType GetStack_O1Top(Stack* ps)
{
	assert(ps);
	DataType tmp = StackTop(ps);
	StackPop(ps);
	DataType cur = StackTop(ps);
	StackPush(ps, tmp);
	return cur;
}
//求栈的大小
int Stack_O1Size(Stack* ps)
{
	assert(ps);
	return StackSize(ps) / 2;
}
//使用两个栈，一个栈压数据，一个栈压最小值的方法
void Stack_O1Push(GetMinStack* ps, DataType x)
{
	assert(ps);
	//存放数据的栈无论如何必须压栈
	StackPush(&ps->_mst, x);
	//如果存放最小值那个栈栈顶元素大于x或者是那个栈还为空，必须压栈
	if ((StackTop(&ps->_msmin) > x) || (StackEmpty(&ps->_msmin) == 0))
	{
		StackPush(&ps->_msmin, x);
	}
}
void Stack_O1Pop(GetMinStack* ps)
{
	assert(ps);
	//比较两个栈顶元素是否相同，如果相同都出栈，如果不相同，只出数据栈
	if (StackTop(&ps->_mst) == StackTop(&ps->_msmin))
	{
		StackPop(&ps->_msmin);
	}
	StackPop(&ps->_mst);
}
DataType GetMinValue(GetMinStack* ps)
{
	assert(ps);
	return StackTop(&ps->_msmin);
}
DataType GetStack_O1Top(GetMinStack* ps)
{
	assert(ps);
	return StackTop(&ps->_mst);
}
/***************************************************************/
/*共享栈,‘L’代表左栈，‘R’代表右栈(静态实现)*/
//初始化栈
void StackShareInit(StackShare* ps)
{
	assert(ps);
	memset(ps->_a, sizeof(DataType)*MAXSIZE, 0);
	ps->top_high = MAXSIZE - 1;
	ps->top_low = 0;
}
//销毁栈
void StackShareDestroy(StackShare* ps, char c)
{
	assert(ps);
	//c只能等于‘L’或‘R’中的一个
	assert((c == 'R' || (c == 'L')));
	if (c == 'L')
	{
		ps->top_low = 0;
	}
	else
	{
		ps->top_high = 0;
	}
}
//判断栈是否为空，空返回0，非空返回1
int StackShareEmpty(StackShare* ps, char c)
{
	assert(ps);
	assert((c == 'R' || (c == 'L')));
	//左栈
	if (c == 'L')
	{
		return ps->top_low == 0 ? 0 : 1;
	}
	//右栈
	else
	{
		return ps->top_high == MAXSIZE - 1 ? 0 : 1;
	}
}
//栈的大小
int StackShareSize(StackShare* ps, char c)
{
	assert(ps);
	assert((c == 'R' || (c == 'L')));
	if (c == 'L')
	{
		return ps->top_low;
	}
	else 
	{
		return MAXSIZE - 1 - ps->top_high;
	}
}
//入栈
void StackSharePush(StackShare* ps, DataType x, char c)
{
	assert(ps);
	assert((c == 'R' || (c == 'L')));
	if (StackIsFull(ps))
	{
		printf("StackFull\n");
		return;
	}
	if (c == 'L')
	{
		ps->_a[ps->top_low] = x;
		ps->top_low++;
	}
	else
	{
		ps->_a[ps->top_high] = x;
		ps->top_high--;
	}
}
//出栈
void StackSharePop(StackShare* ps, char c)
{
	assert(ps);
	assert((c == 'R' || (c == 'L')));
	if (c == 'L')
	{
		if (StackShareEmpty(ps, c))
		{
			ps->top_low--;
		}
		else
		{
			printf("StackEmpty\n");
		}
	}
	else
	{
		if (StackShareEmpty(ps, c))
		{
			ps->top_high++;
		}
		else
		{
			printf("StackEmpty\n");
		}
	}
}
//取栈顶元素
DataType StackShareTop(StackShare* ps, char c)
{
	assert(ps);
	assert((c == 'R' || (c == 'L')));
	if (c == 'L')
	{
		return ps->_a[ps->top_low - 1];
	}
	else
	{
		return ps->_a[ps->top_high + 1];
	}
}
//判断栈是否满，满返回1，不满返回0
int StackIsFull(StackShare* ps)
{
	assert(ps);
	if (ps->top_low <= ps->top_high)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
/******************************************************/
/*5.一个数组实现一个共享栈(奇偶栈)*/
//初始化共享栈(动态实现)
/*void ShareStackInit(ShareStack* ps)
{
	assert(ps);
	ps->_a = (DataType*)malloc(sizeof(DataType)* 3);
	ps->_top_l = 0;
	ps->_top_r = 1;
	ps->capacity = 3;
}
//销毁共享栈
void ShareStackDestroy(ShareStack* ps, char c)
{
	assert(ps);
	assert(c == 'L' || c == 'R');
	if (c == 'L')
	{
		ps->_top_l = 0;
		if (ps->_top_r == 1)
		{
			free(ps->_a);
			ps->_a = NULL;
			ps->capacity = 0;
		}
	}
	else
	{
		ps->_top_r = 1;
		if (ps->_top_l == 0)
		{
			free(ps->_a);
			ps->_a = NULL;
			ps->capacity = 0;
		}
	}
}
//入栈
void ShareStackPush(ShareStack* ps, DataType x, char c)
{
	assert(ps);
	assert(c == 'L' || c == 'R');
	if (c == 'L')
	{
		if (ps->_top_l >= ps->capacity)
		{
			DataType* tmp = realloc(ps->_a, (sizeof(DataType)*  (2 * ps->capacity)));
			if (tmp != NULL)
			{
				ps->_a = tmp;
			}
			ps->capacity *= 2;
		}
		ps->_a[ps->_top_l] = x;
		ps->_top_l += 2;
	}
	else
	{
		if (ps->_top_r >= ps->capacity)
		{
			DataType* tmp = realloc(ps->_a, 2 * (ps->capacity));
			if (tmp != NULL)
			{
				ps->_a = tmp;
			}
			ps->capacity *= 2;
		}
		ps->_a[ps->_top_r] = x;
		ps->_top_r += 2;
	}
}
//出栈
void ShareStackPop(ShareStack* ps, char c)
{
	assert(ps);
	assert(c == 'L' || c == 'R');
	if (c == 'L')
	{
		if (ps->_top_l == 0)
		{
			printf("StackEmpty\n");
			return;
		}
		ps->_top_l -= 2;
	}
	else
	{
		if (ps->_top_r == 0)
		{
			printf("StackEmpty\n");
			return;
		}
		ps->_top_r -= 2;
	}
}
//取栈顶元素
DataType ShareStackTop(ShareStack* ps, char c)
{
	assert(ps);
	assert(c == 'L' || c == 'R');
	if (c == 'L')
	{
		return ps->_a[ps->_top_l - 2];
	}
	else
	{
		return ps->_a[ps->_top_r - 2];
	}
}
//为空返回0，非空返回1
int ShareStackEmpty(ShareStack* ps, char c)
{
	assert(ps);
	assert(c == 'L' || c == 'R');
	if (c == 'L')
	{
		return ps->_top_l == 0 ? 0 : 1;
	}
	else
	{
		return ps->_top_r == 1 ? 0 : 1;
	}
}
//求栈的大小
int ShareStackSize(ShareStack* ps, char c)
{
	assert(ps);
	assert(c == 'L' || c == 'R');
	if (c == 'L')
	{
		return ps->_top_l / 2;
	}
	else
	{
		return ps->_top_r / 2;//向下取整
	}
}*/