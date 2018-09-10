#include"BloomFilter.h"

int HashFunc1(const char* str)
{
	long long count = 0;
	int seed = 31;
	while (*str)
	{
		++str;
		count = count*seed + (*str);
	}
	return count % 1000;
}
int HashFunc2(const char* str)
{
	long long count = 0;
	int seed = 131;
	while (*str)
	{
		++str;
		count = count*seed + (*str);
	}
	return count % 1000;
}
int HashFunc3(const char* str)
{
	long long count = 0;
	int seed = 1313;
	while (*str)
	{
		++str;
		count = count*seed + (*str);
	}
	return count % 1000;
}
void TestBloomFilter()
{
	BloomFilter bf;
	BloomFilterInit(&bf);

	BloomFilterSet(&bf, "find");
	BloomFilterSet(&bf, "insert");
	BloomFilterSet(&bf, "seed");
	BloomFilterSet(&bf, "xikeda");

	printf("%d\n", BloomFilterTest(&bf, "in"));
	BloomFilterDestroy(&bf);
}
void TestBloomFilter_op()
{
	BloomFilter_op bf;
	BloomFilterInit_op(&bf, HashFunc1, HashFunc2, HashFunc3);

	BloomFilterSet_op(&bf, "find");
	BloomFilterSet_op(&bf, "insert");
	BloomFilterSet_op(&bf, "seed");
	BloomFilterSet_op(&bf, "xikeda");

	printf("%d\n", BloomFilterTest_op(&bf, "insert"));
	BloomFilterDestroy_op(&bf);
}
int main()
{
	/*TestBloomFilter();*/
	TestBloomFilter_op();
	return 0;
}