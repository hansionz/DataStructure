#include"BloomFilter.h"
//��ʼ����¡������
void BloomFilterInit(BloomFilter* pbf)
{
	assert(pbf);

	BitSetInit(&pbf->bs, MAXSIZE);
}
//���ٲ�¡������(�ͷſռ�)
void BloomFilterDestroy(BloomFilter* pbf)
{
	assert(pbf);

	BitSetDestory(&pbf->bs);
}
//��Ҫ���õ�����ӳ��ĵ�ַ����Ϊ1
void BloomFilterSet(BloomFilter* pbf, const char* str)
{
	assert(pbf&&str);
	//1.���ݹ�ϣ���������ϣ��ַ(���ַ���ת��Ϊ����)
	size_t index1 = HashFunc1(str);
	size_t index2 = HashFunc2(str);
	size_t index3 = HashFunc3(str);
	//2.�ѹ�ϣ��ַӳ����λͼ��λ������Ϊ1
	BitSetSet(&pbf->bs, index1);
	BitSetSet(&pbf->bs, index2);
	BitSetSet(&pbf->bs, index3);
}
//�ж�һ���ַ����Ƿ����(���ڷ���1�������ڷ���0)
int BloomFilterTest(BloomFilter* pbf, const char* str)
{
	assert(pbf&&str);
	//3���������ڵĵ�ַ��Ϊ1����˵���ַ������ڣ����򲻴���
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
//��ʼ����¡������
void BloomFilterInit_op(BloomFilter_op* pbf, BloomFunc fun1, BloomFunc fun2, BloomFunc fun3)
{
	assert(pbf);
	if (fun1 == NULL || fun2 == NULL || fun3 == NULL)
		return;
	BitSetInit(&pbf->bs, MAXSIZE);
	//��ʼ������ָ������
	pbf->bloomfunc[0] = fun1;
	pbf->bloomfunc[1] = fun2;
	pbf->bloomfunc[2] = fun3;
}
//���ٲ�¡������(�ͷſռ�)
void BloomFilterDestroy_op(BloomFilter_op* pbf)
{
	assert(pbf);
	//����λͼ
	BitSetDestory(&pbf->bs);
	//������ָ�������е�ÿһ��Ԫ�ض�����ΪNULL
	memset(pbf->bloomfunc, NULL, sizeof(BloomFunc)*FUNCMAXSIZE);
}
//��Ҫ���õ�����ӳ��ĵ�ַ����Ϊ1
void BloomFilterSet_op(BloomFilter_op* pbf, const char* str)
{
	assert(pbf);
	//���������Ŷ����ϣ��ַ
	size_t bloomindex[FUNCMAXSIZE];
	int i = 0;
	//1.����ÿ����ϣ��ַ����������
	for (; i < FUNCMAXSIZE; i++)
	{
		bloomindex[i] = pbf->bloomfunc[i](str);
	}
	//2.�ҵ���ϣ��ַ������λͼ�е�λ�ã������Ǹ�λ����Ϊ1
	for (i = 0; i < FUNCMAXSIZE; i++)
	{
		BitSetSet(&pbf->bs, bloomindex[i]);
	}
}
//�ж�һ���ַ����Ƿ����(���ڷ���1�������ڷ���0)
int BloomFilterTest_op(BloomFilter_op* pbf, const char* str)
{
	assert(pbf);
	size_t bloomindex[FUNCMAXSIZE];
	int i = 0;
	//1.����ÿ����ϣ��ַ����������
	for (; i < FUNCMAXSIZE; i++)
	{
		bloomindex[i] = pbf->bloomfunc[i](str);
	}
	//2.���3��λ�ö�Ϊ1������ڣ����򲻴���
	for (i = 0; i < FUNCMAXSIZE; i++)
	{
		if (BitSetTest(&pbf->bs, bloomindex[i]) == 0)
			return 0;
	}
	return 1;
}