#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<time.h>

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
//打印数组，方便测试
void PrintNum(int *num, int len)
{
	assert(num);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");
}
void TestInertSort()
{
	int num[] = { 1, 3, 5, 2, 6, 10, 8, 7, 28, 92 };
	int len = sizeof(num) / sizeof(num[0]);
	//InsertSort(num, len);
	//PrintNum(num, len);
	InsertSort_op(num, len);
	PrintNum(num, len);

	//ShellSort(num, len);
	//PrintNum(num, len);
}
void TestSelectSort()
{

	int num[10000];
	srand(time(0));
	for (int i = 0; i < 10000; i++)
	{
		num[i] = rand();
	}
	int len = sizeof(num) / sizeof(num[0]);
	int start1 = clock();
	SelectSort(num, len);
	int end1 = clock();
	/*PrintNum(num, len);*/
	printf("%d\n", end1 - start1);

	int start2 = clock();
	SelectSort_op(num, len);
	int end2 = clock();
	/*PrintNum(num, len);*/
	printf("%d\n", end1 - start1);
}
int main()
{
	//TestInertSort();
	TestSelectSort();
	return 0;
}