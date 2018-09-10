#include "BitSet.h"
//��ʼ��λͼ
void BitSetInit(BitSet* pbs, size_t n)
{
	assert(pbs);

	pbs->_N = n;
	//����һ��Ҫ��1������nΪ25,25/8=4������Ҫ5���ֽڲ��ܴ����
	size_t size = n / 8 + 1;
	//���ٿռ�
	pbs->_a = (char*)malloc(size);
	//��ʼ��Ϊ0
	memset(pbs->_a, 0, size);
}
//����λͼ(�ͷ�malloc�����Ŀռ�)
void BitSetDestory(BitSet* pbs)
{
	assert(pbs);

	free(pbs->_a);
	pbs->_a = NULL;

	pbs->_N = 0;
}
//����Ҫ���ֵλ��Ϊ1
void BitSetSet(BitSet* pbs, size_t x)
{
	assert(pbs);

	int index = x >> 3;//�����ڵڼ���char��൱��/8
	int num = x % 8;//�����ڵڼ�λ
	
	pbs->_a[index] |= (1 << num);	
}
//���Ѿ�����Ϊ1��λ����������Ϊ0
void BitSetReSet(BitSet* pbs, size_t x)
{
	assert(pbs);

	int index = x >> 3;//�൱��/8
	int num = x % 8;

	pbs->_a[index] &= ~(1 << num);
}
//�ж����������Ƿ����(���ڷ���1�������ڷ���0)
int BitSetTest(BitSet* pbs, size_t x)
{
	assert(pbs);

	int index = x >> 3;//�൱��/8
	int num = x % 8;

	int ret = pbs->_a[index] & (1 << num);

	if (0 == ret)
	{
		return 0;
	}
	else
		return 1;
}
