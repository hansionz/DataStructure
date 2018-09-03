#include"SeqListD.h"
//��ʼ����̬˳���
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
//���ٶ�̬˳���
void DestorySeqList(pSeqList ps)
{
	assert(ps != NULL);
	free(ps->data);
	ps->data = NULL;
	ps->sz = 0;
	ps->capacity = 0;
}
//�������(���˳���������������)
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
		printf("���ݳɹ�\n");
	}
}
//β��
void PushBack(pSeqList ps, DataType data)
{
	assert(ps != NULL);
	CheckCapacity(ps);
	*(ps->data + ps->sz) = data;
	ps->sz++;
}
//�п�
int Empty(pSeqList ps)
{
	assert(ps != NULL);
	//�շ���1���ǿշ���0
	return ps->sz == 0;
}
//βɾ
void PopBack(pSeqList ps)
{
	assert(ps != NULL);
	if (Empty(ps))
	{
		printf("˳���Ϊ�գ��޷�ɾ��\n");
		return;
	}
	ps->sz--;
}
//��ӡ����(�������)
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