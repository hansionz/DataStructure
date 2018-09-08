#include"HashTableBucket.h"
//��ʼ��
void HTBInit(HTB* htb, size_t len)
{
	assert(htb);
	//�����������ȡ��ϣ��ĳ���
	int HTB_len = GetPrime(len);
	//Ϊ��ϣ���ٿռ�(ע�����ָ���ʹ��)
	HashNode** table = (HashNode**)malloc(sizeof(HashNode*)*(HTB_len));
	if (table == NULL)
	{
		perror("use malloc of create");
		exit(EXIT_FAILURE);
	}
	htb->_table = table;
	htb->_size = 0;
	htb->_len = HTB_len;
	//����ϣ���е�����ָ���ʼ��Ϊ�գ�������Ұָ�����
	memset(htb->_table, NULL, sizeof(HashNode*)*(htb->_len));
}
//���ٹ�ϣ��
void HTBDestory(HTB* htb)
{
	assert(htb);
	int i = 0;
	//1.�ͷŹ�ϣ����ÿһ�����ϵĽ��
	for (; i < htb->_len; i++)
	{
		HashNode* cur = htb->_table[i];
		while (cur)
		{
			HashNode* next = cur->_next;
			free(cur);
			cur = next;
		}
		htb->_table[i] = NULL;
	}
	//2.�ͷŹ�ϣ��(��̬���ٵ�����)
	free(htb->_table);
	htb->_table = NULL;
	htb->_size = 0;
	htb->_len = 0;
}
//��ϣ����,�����ϣ��ַ(�ַ�����ģ��������)
static int HTBFunc(HTBKeyType key, int len)
{
	int count = 0;
	int i = 0;
	int seed = 31;//31,131(����)
	while (*(key + i) != '\0')
	{
		count += count*seed + *(key + i);
		++i;
	}
	return count%len;
}
//��ϣ����,�����ϣ��ַ(����)
//static int HTBFunc(HTBKeyType key, int len)
//{
//	return key%len;
//}
//������ϣ���
HashNode* BuyHashNode(HTBKeyType key, HTBValueType value)
{
	HashNode* node = (HashNode*)malloc(sizeof(HashNode));
	if (node != NULL)
	{
		node->_key = key;
		node->_vaule = value;
		node->_next = NULL;
	}
	return node;
}
//��鸺�������Ƿ�ﵽ1������ﵽ1������Ҫ���ݣ��������Ч�ʻ����
void CheckHTBCapacity(HTB* htb)
{
	assert(htb);
	HTB newhtb;
	//���ݾɵĹ�ϣ�������µĹ�ϣ��
	int newlen = GetPrime(htb->_len);
	HTBInit(&newhtb, newlen);
	//�������Ӵﵽ1����Ҫ����
	if (htb->_size == htb->_len)
	{
		for (int i = 0; i < htb->_len; i++)
		{
			HashNode* cur = htb->_table[i];
			while (cur)
			{
				//��¼��һ������λ��
				HashNode* next = cur->_next;
				int index = HTBFunc(cur->_key, newlen);
				//ͷ�嵽�µĹ�ϣ����
				cur->_next = newhtb._table[index];
				newhtb._table[index] = cur;
				cur = next;
			}
			htb->_table[i] = NULL;
		}
		//�ͷžɱ�
		free(htb->_table);
		htb->_table = newhtb._table;
		htb->_size = newhtb._size;
		htb->_len = newhtb._len;
	}
}
//���ϣ���в���һ��Ԫ��
int HTBInsert(HTB* htb, HTBKeyType key, HTBValueType value)
{
	assert(htb);
	int index = HTBFunc(key, htb->_len);
	CheckHTBCapacity(htb);
	HashNode* cur = htb->_table[index];
	HashNode* newnode = BuyHashNode(key, value);
	//ͷ��
	newnode->_next = cur;
	htb->_table[index] = newnode;

	htb->_size++;
	return 1;
}
//ɾ����ϣ���е�һ��Ԫ��
int HTBRemove(HTB* htb, HTBKeyType key)
{
	assert(htb);
	int index = HTBFunc(key, htb->_len);
	HashNode* cur = htb->_table[index];
	HashNode* prev = NULL;//��¼Ҫɾ������ǰһ�����
	while (cur)
	{
		//Ҫɾ���Ľ���ǵ�һ����㣬���⴦��
		if (prev == NULL)
		{
			htb->_table[index] = cur->_next;
			free(cur);
			cur = NULL;
			htb->_size--;
			return 1;
		}
		if (cur->_key == key)
		{
			prev->_next = cur->_next;
		}
		prev = cur;
		cur = cur->_next;
	}
	return 0;
}
//�ڹ�ϣ���в���һ��Ԫ��
HashNode* HTBFind(HTB* htb, HTBKeyType key)
{
	assert(htb);
	int index = HTBFunc(key, htb->_len);
	HashNode* cur = htb->_table[index];
	//������ϣ������
	while (cur)
	{
		if (cur->_key == key)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
//��ӡ��ϣ��(�������)
void PrintHTB(HTB* htb)
{
	assert(htb);
	for (int i = 0; i < htb->_len; i++)
	{
		int count = 0;
		printf("Ͱ[%d]->", i);
		HashNode* cur = htb->_table[i];
		while (cur)
		{
			printf("([key:%s]:[value:%s])->", cur->_key, cur->_vaule);
			count++;
			cur = cur->_next;
		}
		printf("(count=%d)->over\n", count);
	}
}
//��ϣ��Ĵ�С
int HTBSize(HTB* htb)
{
	assert(htb);
	return htb->_size == 0 ? 0 : 1;
}
//��ϣ���Ƿ�Ϊ��
int HTBEmpty(HTB* htb)
{
	assert(htb);
	return htb->_size == htb->_len ? 0 : 1;
}
