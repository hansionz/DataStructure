#include "Sort.h"
#include"Stack.h"
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
//���µ���
void  AdjustDown(int* num, int n, int parent)
{
	if (num == NULL || n <= 0)
		return;
	
	int child = 2 * parent + 1;
	while (child < n)
	{
		//������childָ�����Һ����нϴ����һ��
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
//������
void HeapSort(int* num, int len)
{
	if (num == NULL || len <= 0)
		return;
	//1.����(����->���,����->С��)
	for (int i = (2 * len - 2) / 2; i >= 0; i--)
	{
		AdjustDown(num, len, i);
	}
	//2.�������һ��Ԫ�غ͵�һ��Ԫ��
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
//ð�������Ż�1
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
//ð�������Ż�2��������ǰ���������߲�������(4,2,3,1,0,7,8,9)
void BubbleSort_op2(int* num, int len)
{
	if (num == NULL || len <= 0)
		return;
	
	int pos = len - 1;
	int k = 0;//��¼���һ�ν������ط���������û�н�����˵������������
	for (int i = 0; i < len - 1; i++)
	{
		int flag = 0;
		int j = 0;
		//ֻ�н�������һ�ν�����¼���ĵط��Ϳ���
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
//����ȡ���Ż���
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
//hoare�汾(����Ҵ��ڻ�׼���ұ���С�ڻ�׼������)
int PartSort1(int* num, int begin, int end)
{
	int index = GetMidKey(num, begin, end);

	Swap(&num[index], &num[end]);
	int key = num[end];
	int last = end;

	while (begin < end)
	{
		//1.����ҵ����ڻ�׼ֵ��Ԫ��
		while ((begin < end) && (num[begin] <= key))
			begin++;
		//2.�ұ��ҵ�С�ڻ�׼ֵ��Ԫ��
		while ((begin < end) && (num[end] >= key))
			end--;
		//3.��������ֵ
		Swap(&num[begin], &num[end]);
	}
	//�����±��ߵ�һ���ʱ�򣬰ѻ�׼ֵ��������
	Swap(&num[begin], &num[last]);
	//���ػ�׼ֵ��λ��
	return begin;
}
//�ڿӷ�
int PartSort2(int* num, int begin, int end)
{
	int key = num[end];//�ѻ�׼ֵ�ó���(��һ����)

	while (begin < end)
	{
		//1.����ҵ����ڻ�׼ֵ��Ԫ�أ����������
		while ((begin < end) && (num[begin] <= key))
			begin++;
		num[end] = num[begin];
		//2.�ұ��ҵ�С�ڻ�׼ֵ��Ԫ�أ����������
		while ((begin < end) && (num[end] >= key))
			end--;
		num[begin] = num[end];
	}
	//3.���ó�����׼ֵ�������
	num[begin] = key;
	//���ػ�׼ֵ��λ��
	return begin;
}
//ǰ��ָ�뷨
int PartSort3(int* num, int begin, int end)
{
	int prev = begin - 1;
	int cur = begin;
	int key = num[end];
	while (cur < end)
	{
		//++prev=cur˵�����Ԫ��ʱ��һ��Ԫ�ػ�������һ��������С�ڻ�׼������
		if ((cur < key) && (++prev != cur))
			Swap(&num[cur], &num[prev]);
		cur++;
	}
	//�ѻ�׼��������С�ڻ�׼�ĺ��
	Swap(&num[++prev], &num[end]);
	return prev;
}

void QuickSort(int* num, int left, int right)
{
	if (num == NULL)
		return;
	//�ݹ����
	if (left >= right)
		return;

	////С�����Ż�(�滻����߼���ĵݹ�)
	//if (right - left + 1 < 10)
	//	InsertSort(num, right - left + 1);

	//���ջ�׼ֵ�����������仮��Ϊ����������
	int div = PartSort1(num, left, right);
	//������������������
	QuickSort(num, left, div - 1);
	//������������������
	QuickSort(num, div + 1, right);
}

void QuickSort1(int* num, int left, int right)
{
	if (num == NULL)
		return;
	//�ݹ����
	if (left >= right)
		return;

	//С�����Ż�(�滻����߼���ĵݹ�)
	if (right - left + 1 < 10)
		InsertSort(num, right - left + 1);

	//���ջ�׼ֵ�����������仮��Ϊ����������
	int div = PartSort1(num, left, right);
	//������������������
	QuickSort1(num, left, div - 1);
	//������������������
	QuickSort1(num, div + 1, right);
}
//���ŷǵݹ�(���յݹ�����ǰ��·����)
void QuickSortNonR(int* num, int left, int right)
{
	if (num == NULL || right <= left)
		return;

	struct Stack st;
	StackInit(&st);
	//�Ƚ���������ѹջ
	StackPush(&st, left);	
	StackPush(&st, right);

	while (StackEmpty(&st) != 0)
	{
		//ȡջ�����ҳ�ջ
		int end = StackTop(&st);
		StackPop(&st);
		int begin = StackTop(&st);
		StackPop(&st);
		//�Ȼ��������䣬�̶���һ����׼
		int div = PartSort1(num, begin, end);
		//����������л��д���1��Ԫ�أ�����ѹջ
		if (begin < div - 1)
		{
			StackPush(&st, begin);
			StackPush(&st, div - 1);
		}
		//����������л��д���1��Ԫ�أ�����ѹջ
		if (div + 1 < end)
		{
			StackPush(&st, div + 1);
			StackPush(&st, end);
		}
	}
	StackDestroy(&st);
}
//�鲢����ϲ�����
void Merge(int* num, int start1, int end1, int start2, int end2, int* tmp)
{
	assert(num&&tmp);
	int begin = start1;
	int index = start1;//��start1�ĵط��ϲ�
	//��������������ĺϲ��Ĺ�������
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
	//��ʣ��ĺϲ���tmp��
	while (start1 <= end1)
		tmp[index++] = num[start1++];
	while (start2 <= end2)
		tmp[index++] = num[start2++];
	//tmp�Ǹ���ʱ�ռ䣬��󵽰Ѻϲ������ݿ�����num��
	memcpy(num + begin, tmp + begin, sizeof(int)*(end2 - begin + 1));
}
//�鲢����ֿ�����(�ݹ�������ǰ��·��չ��)
void _MergeSort(int* num, int begin, int end,int* tmp)
{
	assert(num&&tmp);
	int mid = begin + (end - begin) / 2;
	//ֻ��һ��Ԫ�أ�˵����������Ѿ�����
	if (begin == end)
		return;

	_MergeSort(num, begin, mid, tmp);
	_MergeSort(num, mid + 1, end, tmp);

	Merge(num, begin, mid, mid + 1, end, tmp);
}
//�鲢����
void MergeSort(int* num, int len)
{
	if (num == NULL || len <= 0)
		return;

	int* tmp = (int*)malloc(sizeof(int)*len);
	_MergeSort(num, 0, len - 1, tmp);

	free(tmp);
	tmp = NULL;
}