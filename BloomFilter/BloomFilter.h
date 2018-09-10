#ifndef _BLOOMFILTER_H__
#define _BLOOMFILTER_H__

#include"BitSet.h"

//布隆过滤器
typedef struct BloomFilter
{
	BitSet bs;//封装一个位图
}BloomFilter;
//初始化布隆过滤器
void BloomFilterInit(BloomFilter* pbf);
//销毁布隆过滤器(释放空间)
void BloomFilterDestroy(BloomFilter* pbf);
//将要放置的内容映射的地址设置为1
void BloomFilterSet(BloomFilter* pbf, const char* str);
//判断一个字符串是否存在(存在返回1，不存在返回0)
int BloomFilterTest(BloomFilter* pbf, const char* str);

/*布隆过滤器不存在将要放置的内容映射的地址设置为0(既删除)，
因为一个位置可能对于多个字符串映射的地址，删除了一个会影响另一个*/
/****************************************************/
#define MAXSIZE 10000//最大容量
#define FUNCMAXSIZE 3//哈希函数最多个数
//函数指针类型重命名
typedef size_t (*BloomFunc)(const char* str);

typedef struct BloomFilter_op
{
	BitSet bs;//位图
	BloomFunc bloomfunc[FUNCMAXSIZE];//函数指针数组
}BloomFilter_op;
//初始化布隆过滤器
void BloomFilterInit_op(BloomFilter_op* pbf, BloomFunc fun1, BloomFunc fun2, BloomFunc fun3);
//销毁布隆过滤器(释放空间)
void BloomFilterDestroy_op(BloomFilter_op* pbf);
//将要放置的内容映射的地址设置为1
void BloomFilterSet_op(BloomFilter_op* pbf, const char* str);
//判断一个字符串是否存在(存在返回1，不存在返回0)
int BloomFilterTest_op(BloomFilter_op* pbf, const char* str);
#endif //_BLOOMFILTER_H__