#include "Heap.h"
//交换两个数据
static void Swap(HTDataType* a, HTDataType* b)
{
	HTDataType tmp = *a;
	*a = *b;
	*b = tmp;
}
//向下调堆
void AdjustDown(HTDataType* a, int n, int parent)
{
	assert(a);

	int child = 2 * parent + 1;//左孩子
	while (child < n)
	{
		//确定比较大的那个孩子
		if ((a[child] < a[child + 1])&&(child+1 != n))
		{
			child++;
		}
		//如果建大堆，如果双亲小于孩子，则交换
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			//调整parent和child,继续向下调堆直到叶子为止
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
//初始化堆
void HeapInit(Heap* hp, HTDataType* a, int n)
{
	assert(hp);
	//开辟空间
	hp->_capacity = 6;
	hp->_a = (HTDataType*)malloc(sizeof(HTDataType)*(hp->_capacity));
	hp->_size = 0;

	//建堆
	//1.给堆里的数组赋值
	int i = 0;
	for (i = 0; i < n; i++)
	{
		hp->_a[i] = a[i];
		hp->_size++;
	}
	//2.从第一个非叶子结点开始向上调整(n为数组大小，所以n-1为数组最后一个元素的下标)
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}
//堆的销毁(释放malloc出来的空间)
void HeapDestory(Heap* hp)
{
	assert(hp);

	free(hp->_a);
	hp->_a = NULL;

	hp->_capacity = 0;
	hp->_size = 0;
}
//向上调整堆
void AdjustUp(HTDataType* a, int n, int child)
{
	assert(a);

	int parent = (child - 1) / 2;//双亲
	while (child > 0)
	{
		//如果建大堆，如果双亲小于孩子，则交换
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			//调整parent和child向上走
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//向堆里插入一个数据
void HeapPush(Heap* hp, HTDataType x)
{
	assert(hp);
	//堆满了则先扩容在入堆
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		HTDataType* tmp = realloc(hp->_a, sizeof(HTDataType)*(hp->_capacity));
		if (tmp != NULL)
		{
			hp->_a = tmp;
		}
	}
	//1.先将数据入到堆的最后一个位置
	hp->_a[hp->_size] = x;
	hp->_size++;
	//2.向上调堆一次
	AdjustUp(hp->_a, hp->_size, hp->_size - 1);
}
//弹出堆顶的数据
void HeapPop(Heap* hp)
{
	assert(hp);
	//1.交换第一个数据和最后一个数据
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	//2.size减1(下标向前移动)
	hp->_size --;
	//3.向下调堆一次(因为堆顶的元素已变，但是左右子树都是一个堆)
	AdjustDown(hp->_a, hp->_size, 0);
}
//取堆顶数据
HTDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}
//堆的大小
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
//空返回0，非空返回1
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0 ? 0 : 1;
}
//堆排序
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
//打印堆的元素
void PrintHeap(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}