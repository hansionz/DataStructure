#include"Stack.h"
//��ʼ��ջ
void StackInit(Stack* ps)
{
	assert(ps);

	ps->_a = (DataType*)malloc(sizeof(DataType)* 3);
	ps->_top = 0;
	ps->_capacity = 3;
}
//����ջ
void StackDestroy(Stack* ps)
{
	assert(ps);

	free(ps->_a);
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}
//��ջ
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
//��ջ
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
//ȡջ��Ԫ��
DataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->_top > 0);

	return ps->_a[ps->_top - 1];
}
//�շ���0���ǿշ���1
int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0 ? 0 : 1;
}
//��ջ�Ĵ�С
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}
/*************************************************************/
/*������ջ�ĺϷ��ԣ��Ϸ�����1�����Ϸ�����0*/
int CheckLegal(int* num_in, int* num_out,int len_in,int len_out)
{
	Stack s;
	StackInit(&s);
	//�����������ջ���г��Ȳ���ͬ��Ȼ���Ϸ�
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
		//ջ��Ԫ�غͳ�ջ������ͬ���ջһ�Σ���ջ��������ƶ�һλ

		while ((StackEmpty(&s) != 0) && (StackTop(&s) == num_out[j]))
		{
			StackPop(&s);
			j++;
		}
	}
	return StackEmpty(&s) == 0 ? 1 : 0;
}
/***************************************************************/
/*O(1)��ʱ�����ҵ���Сֵ*/
//ʹ��һ��ջ���±�ѹ���ݣ��ϱ�ѹ��Сֵ�÷���
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
//����Сֵ
DataType GetMinValue(Stack* ps)
{
	assert(ps);
	return StackTop(ps);
}
//��ȡջ��Ԫ��
DataType GetStack_O1Top(Stack* ps)
{
	assert(ps);
	DataType tmp = StackTop(ps);
	StackPop(ps);
	DataType cur = StackTop(ps);
	StackPush(ps, tmp);
	return cur;
}
//��ջ�Ĵ�С
int Stack_O1Size(Stack* ps)
{
	assert(ps);
	return StackSize(ps) / 2;
}
//ʹ������ջ��һ��ջѹ���ݣ�һ��ջѹ��Сֵ�ķ���
void Stack_O1Push(GetMinStack* ps, DataType x)
{
	assert(ps);
	//������ݵ�ջ������α���ѹջ
	StackPush(&ps->_mst, x);
	//��������Сֵ�Ǹ�ջջ��Ԫ�ش���x�������Ǹ�ջ��Ϊ�գ�����ѹջ
	if ((StackTop(&ps->_msmin) > x) || (StackEmpty(&ps->_msmin) == 0))
	{
		StackPush(&ps->_msmin, x);
	}
}
void Stack_O1Pop(GetMinStack* ps)
{
	assert(ps);
	//�Ƚ�����ջ��Ԫ���Ƿ���ͬ�������ͬ����ջ���������ͬ��ֻ������ջ
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
/*����ջ,��L��������ջ����R��������ջ(��̬ʵ��)*/
//��ʼ��ջ
void StackShareInit(StackShare* ps)
{
	assert(ps);
	memset(ps->_a, sizeof(DataType)*MAXSIZE, 0);
	ps->top_high = MAXSIZE - 1;
	ps->top_low = 0;
}
//����ջ
void StackShareDestroy(StackShare* ps, char c)
{
	assert(ps);
	//cֻ�ܵ��ڡ�L����R���е�һ��
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
//�ж�ջ�Ƿ�Ϊ�գ��շ���0���ǿշ���1
int StackShareEmpty(StackShare* ps, char c)
{
	assert(ps);
	assert((c == 'R' || (c == 'L')));
	//��ջ
	if (c == 'L')
	{
		return ps->top_low == 0 ? 0 : 1;
	}
	//��ջ
	else
	{
		return ps->top_high == MAXSIZE - 1 ? 0 : 1;
	}
}
//ջ�Ĵ�С
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
//��ջ
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
//��ջ
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
//ȡջ��Ԫ��
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
//�ж�ջ�Ƿ�����������1����������0
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
/*5.һ������ʵ��һ������ջ(��żջ)*/
//��ʼ������ջ(��̬ʵ��)
/*void ShareStackInit(ShareStack* ps)
{
	assert(ps);
	ps->_a = (DataType*)malloc(sizeof(DataType)* 3);
	ps->_top_l = 0;
	ps->_top_r = 1;
	ps->capacity = 3;
}
//���ٹ���ջ
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
//��ջ
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
//��ջ
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
//ȡջ��Ԫ��
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
//Ϊ�շ���0���ǿշ���1
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
//��ջ�Ĵ�С
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
		return ps->_top_r / 2;//����ȡ��
	}
}*/