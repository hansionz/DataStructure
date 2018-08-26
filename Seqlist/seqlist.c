#include"seqlist.h"

void InitSeqList(pSeqList ps)
{
	assert(ps != NULL);
	ps->sz = 0;
	memset(ps->data, 0, sizeof(ps->data));
}
void PushBack(pSeqList ps, DataType data)
{
	assert(ps != NULL);
	if (ps->sz == MAX)
	{
		printf("顺序表已满，不能插入\n");
		return;
	}
	ps->data[ps->sz] = data;
	ps->sz++;
}
void PrintSeqList(pSeqList ps)
{
	assert(ps != NULL);
	int i = 0;
	if (ps->sz == 0)
	{
		printf("顺序表为空");
	}
	for (i = 0; i < ps->sz; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}
void PopBack(pSeqList ps)
{
	assert(ps != NULL);
	if (ps->sz == 0)
	{
		printf("顺序表为空，不能删除\n");
		return;
	}
	ps->sz--;
}
void PushFront(pSeqList ps, DataType data)
{
	int i = 0;
	assert(ps != NULL);
	if (ps->sz == MAX)
	{
		printf("顺序表已满，不能插入\n");
		return;
	}
	for (i = ps->sz - 1; i >= 0; i--)
	{
		ps->data[i + 1] = ps->data[i];
	}
	ps->data[0] = data;
	ps->sz++;
}
void PopFront(pSeqList ps)
{
	int i = 0;
	assert(ps != NULL);
	if (ps->sz == 0)
	{
		printf("顺序表为空，不能删除\n");
		return;
	}
	for (i = 0; i < ps->sz - 1; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}
	ps->sz--;
}
int Find(pSeqList ps, DataType data)
{
	int i = 0;
	assert(ps != NULL);
	for (i = 0; i < ps->sz; i++)
	{
		if (ps->data[i] == data)
		{
			return i;
		}
	}
	return -1;
}
void Insert(pSeqList ps, DataType data, int pos)
{
	int i = 0;
	assert(ps != NULL);
	assert(pos >= 0 && pos <= ps->sz);
	if (ps->sz == MAX)
	{
		printf("顺序表已满，不能插入\n");
		return;
	}
	for (i = ps->sz - 1; i >= pos; i--)
	{
		ps->data[i + 1] = ps->data[i];
	}
	ps->data[pos] = data;
	ps->sz++;
}
void Erase(pSeqList ps, int pos)
{
	int i = 0;
	assert(ps != NULL);
	assert(pos >= 0 && pos <= ps->sz);
	if (ps->sz == 0)
	{
		printf("顺序表为空，不能删除\n");
		return;
	}
	for (i = pos; i < ps->sz - 1; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}
	ps->sz--;
}
void Remove(pSeqList ps, DataType data)
{
	int i = 0;
	assert(ps != NULL);
	if (ps->sz == 0)
	{
		printf("顺序表为空\n");
		return;
	}
	for (i = 0; i < ps->sz; i++)
	{
		if (ps->data[i] == data)
		{
			break;
		}
	}
	if (i == ps->sz)
	{
		printf("没有要删除的元素\n");
		return;
	}
	for (; i < ps->sz - 1; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}
	ps->sz--;
}
void RemoveAll(pSeqList ps, DataType data)
{
	int i = 0;
	int pos = 0;
	int count = 0;
	assert(ps != NULL);
#if 0
	while ((pos = Find(ps, data)) != -1)
	{
		Erase(ps, pos);
	}
#endif
#if 0
	for (i = 0; i < ps->sz; i++)
	{
		if (ps->data[i] == data)
		{
			int j = i;
			for (; j < ps->sz - 1; j++)
			{
				ps->data[j] = ps->data[j + 1];
			}
			ps->sz--;
			i--;
			//只要一移动元素，就一定要将i减1，否则会跳过去一个元素
		}
	}
#endif
#if 0
	DataType *tmp = malloc(sizeof(DataType)*ps->sz);
	for (i = 0; i < ps->sz; i++)
	{
		if (ps->data[i] != data)
		{
			tmp[count++] = ps->data[i];
		}
	}
	memcpy(ps->data, tmp, sizeof(DataType)*count);
	ps->sz = count;
	free(tmp);
	tmp = NULL;
#endif
	for (i = 0; i < ps->sz; i++)
	{
		if (ps->data[i] != data)
		{
			ps->data[count++] = ps->data[i];
		}
	}
	ps->sz = count;
}
int Size(pSeqList ps)
{
	return ps->sz;
}
int Empty(pSeqList ps)
{
	//非空返回0，空返回1
	return ps->sz == 0;
}
static Swap(DataType *ps1, DataType *ps2)
{
	DataType tmp = 0;
	tmp = *ps1;
	*ps1 = *ps2;
	*ps2 = tmp;
}
void BubbleSort(pSeqList ps)
{
	assert(ps != NULL);
	int i = 0;
	int flag = 0;
	for (i = 0; i < ps->sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < ps->sz - 1 - i; j++)
		{
			flag = 0;
			if (ps->data[j]>ps->data[j + 1])
			{
				Swap(ps->data + j, ps->data + j + 1);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return;
		}
	}
}

void SelectSort(pSeqList ps)
{
	assert(ps != NULL);
	int i = 0;
	for (i = 0; i < ps->sz - 1; i++)
	{
		int j = 0;
		//max为最大元素的下标
		int max = 0;
		for (j = 1; j < ps->sz - i; j++)
		{
			if (ps->data[max] < ps->data[j])
			{
				max = j;
			}
		}
		if (max != ps->sz - 1 - i)
		{
			Swap(ps->data + max, ps->data + ps->sz - 1 - i);
		}
	}
}
void SelectSort_op(pSeqList ps)
{
	int start = 0;
	int end = ps->sz - 1;
	assert(ps != NULL);
	while (start < end)
	{
		int max = start;
		int min = start;
		int i = 0;
		for (i = start; i <= end; i++)
		{
			if (ps->data[max] < ps->data[i])
			{
				max = i;
			}
			if (ps->data[min]>ps->data[i])
			{
				min = i;
			}
		}
		if (min != start)
		{
			Swap(ps->data + start, ps->data + min);
		}
		if (max == start)
		{
			max = min;
		}//如果max等于min，最小值已经被交换，所以要找到最大值，必须改变下标
		if (max != end)
		{
			Swap(ps->data + max, ps->data + end);
		}
		start++;
		end--;
	}
}

int BinarySearch(pSeqList ps, DataType data)
{
	int left = 0;
	int right = ps->sz - 1;
	while (left <= right)
	{
		int mid = left + ((right - left) / 2);
		if (ps->data[mid] > data)
		{
			right = mid - 1;
		}
		else if (ps->data[mid] < data)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
int BinarySearch_D(pSeqList ps, int left, int right, DataType data)
{
	int mid = 0;
	if (left > right)
	{
		return -1;
	}
	mid = left + ((right - left) / 2);
    if (ps->data[mid] > data)
	{
		return BinarySearch_D(ps, left, mid - 1, data);
	}
	else if (ps->data[mid] < data)
	{
		return BinarySearch_D(ps, mid + 1, right, data);
	}
	else
	{
		return mid;
	}
}