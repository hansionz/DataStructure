#ifndef __BITSET_H__
#define __BITSET_H__

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef struct BitSet
{
	char* _a;
	size_t _N;//Î»¸öÊý
}BitSet;

void BitSetInit(BitSet* pbs, size_t n);
void BitSetDestory(BitSet* pbs);

void BitSetSet(BitSet* pbs, size_t x);
void BitSetReSet(BitSet* pbs, size_t x);

int BitSetTest(BitSet* pbs, size_t x);

#endif //__BITSET_H__


