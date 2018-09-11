#include<stdio.h>
#include<string.h>
#include<assert.h>
//直接插入排序
int InsertSort(int *num,int len)
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
//希尔排序(缩小增量排序)
/*最好步长序列是由Sedgewick提出的(1, 5, 19, 41, 109,...)*/
int ShellSort(int *num, int len)
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
		gap -= 4;
	}
	//2.gap为1时直接插入排序(这时要排序序列已经接近有序)
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
int main()
{
	int num[] = { 1, 3, 5, 2, 6, 10, 8, 7, 28, 92 };
	int len = sizeof(num) / sizeof(num[0]);
	//InsertSort(num, len);
	//PrintNum(num, len);
	ShellSort(num, len);
	PrintNum(num, len);
	return 0;
}