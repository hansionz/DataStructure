#include<stdio.h>
#include<string.h>
#include<assert.h>
//ֱ�Ӳ�������
int InsertSort(int *num,int len)
{
	assert(num);
	int i = 0;
	//��һ��Ԫ���Ѿ�Ϊ�������У�����Ҫ����len-1������
	for (; i < len - 1; i++)
	{
		int end = i;
		int tmp = num[i + 1];//��������������һ��Ԫ�أ������ں�ߵ��ƶ��л�ı�
		//�ȽϺ���
		while (end >= 0 && num[end]>tmp)
		{
			num[end+1] = num[end];
			--end;
		}
		//���뵽�ʵ�λ��
		num[end + 1] = tmp;
	}
}
//ϣ������(��С��������)
/*��ò�����������Sedgewick�����(1, 5, 19, 41, 109,...)*/
int ShellSort(int *num, int len)
{
	assert(num);

	int gap = 5;//����

	//���һ�β�������Ϊ1
	while (gap >= 0)
	{
		//1.gap>1ʱԤ����
		for (int i = 0; i < len - gap; i++)
		{
			int end = i;
			int tmp = num[end + gap];
			while (end >= 0 && num[end] > tmp)
			{
				num[end + gap] = num[end];
				end -= gap;
			}
			num[end + gap] = tmp;
		}
		gap -= 4;
	}
	//2.gapΪ1ʱֱ�Ӳ�������(��ʱҪ���������Ѿ��ӽ�����)
}
//��ӡ���飬�������
void PrintNum(int *num, int len)
{
	assert(num);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");
}
int main()
{
	int num[] = { 1, 3, 5, 2, 6, 10, 8, 7, 28, 92 };
	int len = sizeof(num) / sizeof(num[0]);
	//InsertSort(num, len);
	//PrintNum(num, len);
	ShellSort(num, len);
	PrintNum(num, len);
	return 0;
}