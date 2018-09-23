#include "Sort.h"
#include"Stack.h"
//直接插入排序
void InsertSort(int *num,int len)
{
	assert(num);
	int i = 0;
	//第一个元素已经为有序序列，所以要进行len-1次排序
	for (; i < len - 1; i++)
	{
		int end = i;
		int tmp = num[i + 1];//保存非有序区间第一个元素，否则在后边的移动中会改变
		//比较后移
		while (end >= 0 && num[end]>tmp)
		{
			num[end+1] = num[end];
			--end;
		}
		//插入到适当位置
		num[end + 1] = tmp;
	}
}
//直接插入排序优化
void InsertSort_op(int arr[], int len)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	int k = 0;//用来记录要插入的位置
	for (i = 1; i < len; i++)
	{
		tmp = arr[i];
		int left = 0;
		int right = i - 1;//有序区间
		while (left <= right)
		{
			int mid = (left&right) + ((left^right) >> 1);//求两个数平均值，底下有博客链接详解
			if (arr[mid]>tmp)//tmp插入的位置必然小于mid
			{
				right = mid - 1;
				k = mid;
			}
			else if (arr[mid] <= tmp)//tmp插入的位置必然小于mid
			{
				left = mid + 1;
				k = mid + 1;
			}
		}
		//将k位置及以后的元素向后移动
		for (j = i; j > k; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[k] = tmp;
	}
}
//希尔排序(缩小增量排序)
/*最好步长序列是由Sedgewick提出的(1, 5, 19, 41, 109,...)*/
void ShellSort(int *num, int len)
{
	assert(num);

	int gap = 5;//步长

	//最后一次步长必须为1
	while (gap >= 0)
	{
		//1.gap>1时预排序
		for (int i = 0; i < len - gap; i++)
		{
			int end = i;
			int tmp = num[end + gap];
			while (end >= 0 && num[end] > tmp)
			{
				num[end + gap] = num[end];
				end -= gap;
			}
			num[end + gap] = tmp;
		}
		gap -= 2;
	}
	//2.gap为1时直接插入排序(这时要排序序列已经接近有序)
}
//2.直接选择排序
static void Swap(int* x1, int* x2)
{
	int tmp = *x1;
	*x1 = *x2;
	*x2 = tmp;
}
void SelectSort(int* num, int len)
{
	if (num == NULL || len <= 0)
		return;
	int i = 0;
	//1.确定循环躺数
	for (; i < len - 1; i++)
	{
		int minindex = i;
		int j = i + 1;
		//2.找到无序区的最小值
		for (; j < len; j++)
		{
			if (num[minindex] > num[j])
			{
				minindex = j;
			}
		}
		//与无序区第一个元素交换
		if (minindex != i)
			Swap(&num[minindex], &num[i]);
	}
}
//选择排序优化(双向选择)
void SelectSort_op(int* num, int len)
{
	if (num == NULL || len <= 0)
		return;

	int left = 0;
	int right = len - 1;
	while (left < right)
	{
		int maxindex = left;
		int minindex = left;
		for (int i = left + 1; i <= right; i++)
		{
			//maxindex确定最大值的下标
			if (num[i]>num[maxindex])
				maxindex = i;
			//minindex确定最小值的下标
			if (num[i] < num[minindex])
				minindex = i;
		}
		//如果minindex不是left，则交换
		if (minindex != left)
			Swap(&num[minindex], &num[left]);
		//如果maxindex是left，那么最大值已经交换到了minindex的位置
		if (maxindex == left)
			maxindex = minindex;
		//如果maxindex不是right，则交换
		if (maxindex != right)
			Swap(&num[maxindex], &num[right]);

		left++;
		right--;
	}
}
//向下调堆
void  AdjustDown(int* num, int n, int parent)
{
	if (num == NULL || n <= 0)
		return;
	
	int child = 2 * parent + 1;
	while (child < n)
	{
		//处理让child指向左右孩子中较大的哪一个
		if ((child + 1 < n) && (num[child] < num[child + 1]))
			child++;
		//
		if (num[child]>num[parent])
		{
			Swap(&num[child], &num[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
//堆排序
void HeapSort(int* num, int len)
{
	if (num == NULL || len <= 0)
		return;
	//1.建堆(升序->大堆,降序->小堆)
	for (int i = (2 * len - 2) / 2; i >= 0; i--)
	{
		AdjustDown(num, len, i);
	}
	//2.交换最后一个元素和第一个元素
	int end = len - 1;
	while (end > 0)
	{
		Swap(&num[0], &num[end]);
		AdjustDown(num, end, 0);
		--end;
	}
}
void BubbleSort(int* num, int len)
{
	if (num == NULL || len <= 0)
		return;

	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (num[j]>num[j + 1])
				Swap(&num[j], &num[j + 1]);
		}
	}
}
//冒泡排序优化1
void BubbleSort_op1(int* num, int len)
{
	if (num == NULL || len <= 0)
		return;

	for (int i = 0; i < len - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (num[j]>num[j + 1]){
				Swap(&num[j], &num[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
//冒泡排序优化2：适用于前部分无序后边部分有序(4,2,3,1,0,7,8,9)
void BubbleSort_op2(int* num, int len)
{
	if (num == NULL || len <= 0)
		return;
	
	int pos = len - 1;
	int k = 0;//记录最后一次交换过地方，如果后边没有交换，说明后边是有序的
	for (int i = 0; i < len - 1; i++)
	{
		int flag = 0;
		int j = 0;
		//只有交换到上一次交换记录到的地方就可以
		for (; j < pos; j++)
		{
			if (num[j]>num[j + 1]){
				Swap(&num[j], &num[j + 1]);
				flag = 1;
				k = j;
			}
		}
		if (flag == 0)
			break;
		pos = k;
	}
}
//三数取中优化法
int GetMidKey(int* num, int begin, int end)
{
	assert(num);
	int mid = begin + (end - begin) / 2;
	if (num[begin] < num[mid])
	{
		if (num[mid] < num[end])
			return mid;
		else
		{
			if (num[begin]>num[end])
				return begin;
			else
				return end;
		}
	}
	else
	{
		if (num[begin] < num[end])
			return begin;
		else
		{
			if (num[mid]>num[end])
				return mid;
			else
				return end;
		}	
	}
}
//hoare版本(左边找大于基准，右边找小于基准，交换)
int PartSort1(int* num, int begin, int end)
{
	int index = GetMidKey(num, begin, end);

	Swap(&num[index], &num[end]);
	int key = num[end];
	int last = end;

	while (begin < end)
	{
		//1.左边找到大于基准值的元素
		while ((begin < end) && (num[begin] <= key))
			begin++;
		//2.右边找到小于基准值的元素
		while ((begin < end) && (num[end] >= key))
			end--;
		//3.交换两个值
		Swap(&num[begin], &num[end]);
	}
	//两个下标走到一块的时候，把基准值交换过来
	Swap(&num[begin], &num[last]);
	//返回基准值的位置
	return begin;
}
//挖坑法
int PartSort2(int* num, int begin, int end)
{
	int key = num[end];//把基准值拿出来(挖一个坑)

	while (begin < end)
	{
		//1.左边找到大于基准值的元素，并放入坑里
		while ((begin < end) && (num[begin] <= key))
			begin++;
		num[end] = num[begin];
		//2.右边找到小于基准值的元素，并放入坑里
		while ((begin < end) && (num[end] >= key))
			end--;
		num[begin] = num[end];
	}
	//3.把拿出来基准值放入坑里
	num[begin] = key;
	//返回基准值的位置
	return begin;
}
//前后指针法
int PartSort3(int* num, int begin, int end)
{
	int prev = begin - 1;
	int cur = begin;
	int key = num[end];
	while (cur < end)
	{
		//++prev=cur说明这个元素时第一个元素或者这是一段连续的小于基准的序列
		if ((cur < key) && (++prev != cur))
			Swap(&num[cur], &num[prev]);
		cur++;
	}
	//把基准放在所有小于基准的后边
	Swap(&num[++prev], &num[end]);
	return prev;
}

void QuickSort(int* num, int left, int right)
{
	if (num == NULL)
		return;
	//递归出口
	if (left >= right)
		return;

	////小区间优化(替换掉后边几层的递归)
	//if (right - left + 1 < 10)
	//	InsertSort(num, right - left + 1);

	//按照基准值将待排序区间划分为两个子区间
	int div = PartSort1(num, left, right);
	//子问题排序左子区间
	QuickSort(num, left, div - 1);
	//子问题排序右子区间
	QuickSort(num, div + 1, right);
}

void QuickSort1(int* num, int left, int right)
{
	if (num == NULL)
		return;
	//递归出口
	if (left >= right)
		return;

	//小区间优化(替换掉后边几层的递归)
	if (right - left + 1 < 10)
		InsertSort(num, right - left + 1);

	//按照基准值将待排序区间划分为两个子区间
	int div = PartSort1(num, left, right);
	//子问题排序左子区间
	QuickSort1(num, left, div - 1);
	//子问题排序右子区间
	QuickSort1(num, div + 1, right);
}
//快排非递归(按照递归树的前序路线走)
void QuickSortNonR(int* num, int left, int right)
{
	if (num == NULL || right <= left)
		return;

	struct Stack st;
	StackInit(&st);
	//先将整个区间压栈
	StackPush(&st, left);	
	StackPush(&st, right);

	while (StackEmpty(&st) != 0)
	{
		//取栈顶并且出栈
		int end = StackTop(&st);
		StackPop(&st);
		int begin = StackTop(&st);
		StackPop(&st);
		//先划分主区间，固定好一个基准
		int div = PartSort1(num, begin, end);
		//如果左子序列还有大于1个元素，继续压栈
		if (begin < div - 1)
		{
			StackPush(&st, begin);
			StackPush(&st, div - 1);
		}
		//如果右子序列还有大于1个元素，继续压栈
		if (div + 1 < end)
		{
			StackPush(&st, div + 1);
			StackPush(&st, end);
		}
	}
	StackDestroy(&st);
}
//归并排序合并过程
void Merge(int* num, int start1, int end1, int start2, int end2, int* tmp)
{
	assert(num&&tmp);
	int begin = start1;
	int index = start1;//从start1的地方合并
	//和两条有序单链表的合并的过程类似
	while ((start1 <= end1) && (start2 <= end2))
	{
		if (num[start1] < num[start2])
		{
			tmp[index++] = num[start1++];
		}
		else
		{
			tmp[index++] = num[start2++];
		}
	}
	//把剩余的合并到tmp上
	while (start1 <= end1)
		tmp[index++] = num[start1++];
	while (start2 <= end2)
		tmp[index++] = num[start2++];
	//tmp是个临时空间，最后到把合并的内容拷贝到num上
	memcpy(num + begin, tmp + begin, sizeof(int)*(end2 - begin + 1));
}
//归并排序分开过程(递归树按照前序路线展开)
void _MergeSort(int* num, int begin, int end,int* tmp)
{
	assert(num&&tmp);
	int mid = begin + (end - begin) / 2;
	//只有一个元素，说明这个序列已经有序
	if (begin == end)
		return;

	_MergeSort(num, begin, mid, tmp);
	_MergeSort(num, mid + 1, end, tmp);

	Merge(num, begin, mid, mid + 1, end, tmp);
}
//归并排序
void MergeSort(int* num, int len)
{
	if (num == NULL || len <= 0)
		return;

	int* tmp = (int*)malloc(sizeof(int)*len);
	_MergeSort(num, 0, len - 1, tmp);

	free(tmp);
	tmp = NULL;
}