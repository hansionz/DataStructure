#include"SeqListD.h"
//初始化动态顺序表
void InitSeqList(pSeqList ps)
{
	assert(ps != NULL);
	ps->data = (DataType *)malloc(DEFAULT_SZ*sizeof(DataType));
	if (ps->data == NULL)
	{
		perror("use malloc");
		exit(EXIT_FAILURE);
	}
	ps->sz = 0;
	ps->capacity = DEFAULT_SZ;
}
//销毁动态顺序表
void DestorySeqList(pSeqList ps)
{
	assert(ps != NULL);
	free(ps->data);
	ps->data = NULL;
	ps->sz = 0;
	ps->capacity = 0;
}
//检查容量(如果顺序表已满，则扩容)
static void CheckCapacity(pSeqList ps)
{
	assert(ps != NULL);
	if (ps->sz == ps->capacity)
	{
		DataType *tmp = realloc(ps->data, (ps->capacity + DEFAULT_SZ)*sizeof(DataType));
		if (tmp != NULL)
		{
			ps->data = tmp;
		}
		ps->capacity += DEFAULT_SZ;
		printf("扩容成功\n");
	}
}
//尾插
void PushBack(pSeqList ps, DataType data)
{
	assert(ps != NULL);
	CheckCapacity(ps);
	*(ps->data + ps->sz) = data;
	ps->sz++;
}
//判空
int Empty(pSeqList ps)
{
	assert(ps != NULL);
	//空返回1，非空返回0
	return ps->sz == 0;
}
//尾删
void PopBack(pSeqList ps)
{
	assert(ps != NULL);
	if (Empty(ps))
	{
		printf("顺序表为空，无法删除\n");
		return;
	}
	ps->sz--;
}
//打印函数(方便测试)
void PrintSeqList(pSeqList ps)
{
	assert(ps != NULL);
	int i = 0;
	for (i = 0; i < ps->sz; i++)
	{
		printf("%d ", *(ps->data + i));
	}
	printf("\n");
}