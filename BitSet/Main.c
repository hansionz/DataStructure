#include"BitSet.h"

void TestBitSet()
{
	BitSet bs;
	BitSetInit(&bs, 20);

	BitSetSet(&bs, 14);
	BitSetSet(&bs, 2);
	BitSetSet(&bs, 9);
	BitSetSet(&bs, 19);
	BitSetReSet(&bs, 19);
	printf("%d\n", BitSetTest(&bs, 19));
	printf("%d\n", BitSetTest(&bs, 3));
	printf("%d\n", BitSetTest(&bs, 9));
	printf("%d\n", BitSetTest(&bs, 4));

	BitSetDestory(&bs);
}

int main()
{
	TestBitSet();
	return 0;
}