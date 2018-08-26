#include "Heap.h"
//������������
static void Swap(HTDataType* a, HTDataType* b)
{
	HTDataType tmp = *a;
	*a = *b;
	*b = tmp;
}
//���µ���
void AdjustDown(HTDataType* a, int n, int parent)
{
	assert(a);

	int child = 2 * parent + 1;//����
	while (child < n)
	{
		//ȷ���Ƚϴ���Ǹ�����
		if ((a[child] < a[child + 1])&&(child+1 != n))
		{
			child++;
		}
		//�������ѣ����˫��С�ں��ӣ��򽻻�
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			//����parent��child,�������µ���ֱ��Ҷ��Ϊֹ
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
//��ʼ����
void HeapInit(Heap* hp, HTDataType* a, int n)
{
	assert(hp);
	//���ٿռ�
	hp->_capacity = 6;
	hp->_a = (HTDataType*)malloc(sizeof(HTDataType)*(hp->_capacity));
	hp->_size = 0;

	//����
	//1.����������鸳ֵ
	int i = 0;
	for (i = 0; i < n; i++)
	{
		hp->_a[i] = a[i];
		hp->_size++;
	}
	//2.�ӵ�һ����Ҷ�ӽ�㿪ʼ���ϵ���(nΪ�����С������n-1Ϊ�������һ��Ԫ�ص��±�)
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}
//�ѵ�����(�ͷ�malloc�����Ŀռ�)
void HeapDestory(Heap* hp)
{
	assert(hp);

	free(hp->_a);
	hp->_a = NULL;

	hp->_capacity = 0;
	hp->_size = 0;
}
//���ϵ�����
void AdjustUp(HTDataType* a, int n, int child)
{
	assert(a);

	int parent = (child - 1) / 2;//˫��
	while (child > 0)
	{
		//�������ѣ����˫��С�ں��ӣ��򽻻�
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			//����parent��child������
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//��������һ������
void HeapPush(Heap* hp, HTDataType x)
{
	assert(hp);
	//�������������������
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		HTDataType* tmp = realloc(hp->_a, sizeof(HTDataType)*(hp->_capacity));
		if (tmp != NULL)
		{
			hp->_a = tmp;
		}
	}
	//1.�Ƚ������뵽�ѵ����һ��λ��
	hp->_a[hp->_size] = x;
	hp->_size++;
	//2.���ϵ���һ��
	AdjustUp(hp->_a, hp->_size, hp->_size - 1);
}
//�����Ѷ�������
void HeapPop(Heap* hp)
{
	assert(hp);
	//1.������һ�����ݺ����һ������
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	//2.size��1(�±���ǰ�ƶ�)
	hp->_size --;
	//3.���µ���һ��(��Ϊ�Ѷ���Ԫ���ѱ䣬����������������һ����)
	AdjustDown(hp->_a, hp->_size, 0);
}
//ȡ�Ѷ�����
HTDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}
//�ѵĴ�С
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
//�շ���0���ǿշ���1
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0 ? 0 : 1;
}
//������
void HeapSort(HTDataType* a, int n)
{
	assert(a);
	int index = n;

	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	while (index != 1)
	{
		Swap(&a[0], &a[index - 1]);
		index--;
		AdjustDown(a, index, 0);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//��ӡ�ѵ�Ԫ��
void PrintHeap(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}