#include "BitSet.h"
//初始化位图
void BitSetInit(BitSet* pbs, size_t n)
{
	assert(pbs);

	pbs->_N = n;
	//这里一定要加1，假如n为25,25/8=4，但是要5个字节才能存的下
	size_t size = n / 8 + 1;
	//开辟空间
	pbs->_a = (char*)malloc(size);
	//初始化为0
	memset(pbs->_a, 0, size);
}
//销毁位图(释放malloc出来的空间)
void BitSetDestory(BitSet* pbs)
{
	assert(pbs);

	free(pbs->_a);
	pbs->_a = NULL;

	pbs->_N = 0;
}
//设置要存的值位置为1
void BitSetSet(BitSet* pbs, size_t x)
{
	assert(pbs);

	int index = x >> 3;//计算在第几个char里，相当于/8
	int num = x % 8;//计算在第几位
	
	pbs->_a[index] |= (1 << num);	
}
//把已经设置为1的位置重新设置为0
void BitSetReSet(BitSet* pbs, size_t x)
{
	assert(pbs);

	int index = x >> 3;//相当于/8
	int num = x % 8;

	pbs->_a[index] &= ~(1 << num);
}
//判断所给数字是否存在(存在返回1，不存在返回0)
int BitSetTest(BitSet* pbs, size_t x)
{
	assert(pbs);

	int index = x >> 3;//相当于/8
	int num = x % 8;

	int ret = pbs->_a[index] & (1 << num);

	if (0 == ret)
	{
		return 0;
	}
	else
		return 1;
}
