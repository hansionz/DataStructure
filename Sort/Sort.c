#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<time.h>

//ֱ�Ӳ�������
void InsertSort(int *num,int len)
{
	assert(num);
	int i = 0;
	//��һ��Ԫ���Ѿ�Ϊ�������У�����Ҫ����len-1������
	for (; i < len - 1; i++)
	{
		int end = i;
		int tmp = num[i + 1];//��������������һ��Ԫ�أ������ں�ߵ��ƶ��л�ı�
		//�ȽϺ���
		while (end >= 0 && num[end]>tmp)
		{
			num[end+1] = num[end];
			--end;
		}
		//���뵽�ʵ�λ��
		num[end + 1] = tmp;
	}
}
//ֱ�Ӳ��������Ż�
void InsertSort_op(int arr[], int len)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	int k = 0;//������¼Ҫ�����λ��
	for (i = 1; i < len; i++)
	{
		tmp = arr[i];
		int left = 0;
		int right = i - 1;//��������
		while (left <= right)
		{
			int mid = (left&right) + ((left^right) >> 1);//��������ƽ��ֵ�������в����������
			if (arr[mid]>tmp)//tmp�����λ�ñ�ȻС��mid
			{
				right = mid - 1;
				k = mid;
			}
			else if (arr[mid] <= tmp)//tmp�����λ�ñ�ȻС��mid
			{
				left = mid + 1;
				k = mid + 1;
			}
		}
		//��kλ�ü��Ժ��Ԫ������ƶ�
		for (j = i; j > k; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[k] = tmp;
	}
}
//ϣ������(��С��������)
/*��ò�����������Sedgewick�����(1, 5, 19, 41, 109,...)*/
void ShellSort(int *num, int len)
{
	assert(num);

	int gap = 5;//����

	//���һ�β�������Ϊ1
	while (gap >= 0)
	{
		//1.gap>1ʱԤ����
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
	//2.gapΪ1ʱֱ�Ӳ�������(��ʱҪ���������Ѿ��ӽ�����)
}
//2.ֱ��ѡ������
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
	//1.ȷ��ѭ������
	for (; i < len - 1; i++)
	{
		int minindex = i;
		int j = i + 1;
		//2.�ҵ�����������Сֵ
		for (; j < len; j++)
		{
			if (num[minindex] > num[j])
			{
				minindex = j;
			}
		}
		//����������һ��Ԫ�ؽ���
		if (minindex != i)
			Swap(&num[minindex], &num[i]);
	}
}
//ѡ�������Ż�(˫��ѡ��)
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
			//maxindexȷ�����ֵ���±�
			if (num[i]>num[maxindex])
				maxindex = i;
			//minindexȷ����Сֵ���±�
			if (num[i] < num[minindex])
				minindex = i;
		}
		//���minindex����left���򽻻�
		if (minindex != left)
			Swap(&num[minindex], &num[left]);
		//���maxindex��left����ô���ֵ�Ѿ���������minindex��λ��
		if (maxindex == left)
			maxindex = minindex;
		//���maxindex����right���򽻻�
		if (maxindex != right)
			Swap(&num[maxindex], &num[right]);

		left++;
		right--;
	}
}
//��ӡ���飬�������
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