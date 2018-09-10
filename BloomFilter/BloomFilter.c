#include"BloomFilter.h"
//初始化布隆过滤器
void BloomFilterInit(BloomFilter* pbf)
{
	assert(pbf);

	BitSetInit(&pbf->bs, MAXSIZE);
}
//销毁布隆过滤器(释放空间)
void BloomFilterDestroy(BloomFilter* pbf)
{
	assert(pbf);

	BitSetDestory(&pbf->bs);
}
//将要放置的内容映射的地址设置为1
void BloomFilterSet(BloomFilter* pbf, const char* str)
{
	assert(pbf&&str);
	//1.根据哈希函数计算哈希地址(将字符串转换为整数)
	size_t index1 = HashFunc1(str);
	size_t index2 = HashFunc2(str);
	size_t index3 = HashFunc3(str);
	//2.把哈希地址映射在位图的位置设置为1
	BitSetSet(&pbf->bs, index1);
	BitSetSet(&pbf->bs, index2);
	BitSetSet(&pbf->bs, index3);
}
//判断一个字符串是否存在(存在返回1，不存在返回0)
int BloomFilterTest(BloomFilter* pbf, const char* str)
{
	assert(pbf&&str);
	//3个函数对于的地址都为1才能说明字符串存在，否则不存在
	int index1 = HashFunc1(str);
	if (BitSetTest(&pbf->bs, index1) == 0)
		return 0;
	int index2 = HashFunc2(str);
	if (BitSetTest(&pbf->bs, index2) == 0)
		return 0;
	int index3 = HashFunc3(str);
	if (BitSetTest(&pbf->bs, index3) == 0)
		return 0;
	return 1;
}
//初始化布隆过滤器
void BloomFilterInit_op(BloomFilter_op* pbf, BloomFunc fun1, BloomFunc fun2, BloomFunc fun3)
{
	assert(pbf);
	if (fun1 == NULL || fun2 == NULL || fun3 == NULL)
		return;
	BitSetInit(&pbf->bs, MAXSIZE);
	//初始化函数指针数组
	pbf->bloomfunc[0] = fun1;
	pbf->bloomfunc[1] = fun2;
	pbf->bloomfunc[2] = fun3;
}
//销毁布隆过滤器(释放空间)
void BloomFilterDestroy_op(BloomFilter_op* pbf)
{
	assert(pbf);
	//销毁位图
	BitSetDestory(&pbf->bs);
	//将函数指针数组中的每一个元素都设置为NULL
	memset(pbf->bloomfunc, NULL, sizeof(BloomFunc)*FUNCMAXSIZE);
}
//将要放置的内容映射的地址设置为1
void BloomFilterSet_op(BloomFilter_op* pbf, const char* str)
{
	assert(pbf);
	//定义数组存放多个哈希地址
	size_t bloomindex[FUNCMAXSIZE];
	int i = 0;
	//1.计算每个哈希地址放在数组中
	for (; i < FUNCMAXSIZE; i++)
	{
		bloomindex[i] = pbf->bloomfunc[i](str);
	}
	//2.找到哈希地址对于在位图中的位置，并把那个位设置为1
	for (i = 0; i < FUNCMAXSIZE; i++)
	{
		BitSetSet(&pbf->bs, bloomindex[i]);
	}
}
//判断一个字符串是否存在(存在返回1，不存在返回0)
int BloomFilterTest_op(BloomFilter_op* pbf, const char* str)
{
	assert(pbf);
	size_t bloomindex[FUNCMAXSIZE];
	int i = 0;
	//1.计算每个哈希地址放在数组中
	for (; i < FUNCMAXSIZE; i++)
	{
		bloomindex[i] = pbf->bloomfunc[i](str);
	}
	//2.如果3个位置都为1，则存在，否则不存在
	for (i = 0; i < FUNCMAXSIZE; i++)
	{
		if (BitSetTest(&pbf->bs, bloomindex[i]) == 0)
			return 0;
	}
	return 1;
}