#ifndef _BLOOMFILTER_H__
#define _BLOOMFILTER_H__

#include"BitSet.h"

//��¡������
typedef struct BloomFilter
{
	BitSet bs;//��װһ��λͼ
}BloomFilter;
//��ʼ����¡������
void BloomFilterInit(BloomFilter* pbf);
//���ٲ�¡������(�ͷſռ�)
void BloomFilterDestroy(BloomFilter* pbf);
//��Ҫ���õ�����ӳ��ĵ�ַ����Ϊ1
void BloomFilterSet(BloomFilter* pbf, const char* str);
//�ж�һ���ַ����Ƿ����(���ڷ���1�������ڷ���0)
int BloomFilterTest(BloomFilter* pbf, const char* str);

/*��¡�����������ڽ�Ҫ���õ�����ӳ��ĵ�ַ����Ϊ0(��ɾ��)��
��Ϊһ��λ�ÿ��ܶ��ڶ���ַ���ӳ��ĵ�ַ��ɾ����һ����Ӱ����һ��*/
/****************************************************/
#define MAXSIZE 10000//�������
#define FUNCMAXSIZE 3//��ϣ����������
//����ָ������������
typedef size_t (*BloomFunc)(const char* str);

typedef struct BloomFilter_op
{
	BitSet bs;//λͼ
	BloomFunc bloomfunc[FUNCMAXSIZE];//����ָ������
}BloomFilter_op;
//��ʼ����¡������
void BloomFilterInit_op(BloomFilter_op* pbf, BloomFunc fun1, BloomFunc fun2, BloomFunc fun3);
//���ٲ�¡������(�ͷſռ�)
void BloomFilterDestroy_op(BloomFilter_op* pbf);
//��Ҫ���õ�����ӳ��ĵ�ַ����Ϊ1
void BloomFilterSet_op(BloomFilter_op* pbf, const char* str);
//�ж�һ���ַ����Ƿ����(���ڷ���1�������ڷ���0)
int BloomFilterTest_op(BloomFilter_op* pbf, const char* str);
#endif //_BLOOMFILTER_H__