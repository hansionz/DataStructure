#include "HashTable.h"

//��ϣ��ĳ�ʼ��
void HashTableInit(HashTable* ht, size_t len)
{
	assert(ht);
	//��̬����һ������
	ht->_table = (HashData*)malloc(sizeof(HashData)*len);
	if (ht->_table == NULL)
	{
		perror("use malloc to create");
	}
	//���Ƚ��������ݵ�״̬������Ϊ��(EMPTY)
	for (int i = 0; i < ht->_len; i++)
	{
		ht->_table[i]._state = EMPTY;
	}
	ht->_len = len;//��ϣ��ĳ���
	ht->_size = 0;//��ЧԪ�صĸ���
}
//���ٹ�ϣ��(malloc�����Ŀռ�)
void HashTableDestroy(HashTable* ht)
{
	assert(ht);
	free(ht->_table);
	ht->_table = NULL;
	ht->_size = 0;
	ht->_len = 0;
}
//��ϣ���������ݹ�ϣ�����õ�һ����ַ(����ģ��������)
int GetPosition(HashTable* ht, HTKeyType key)
{
	assert(ht);
	return key % (ht->_len);
}
//��鸺�������Ƿ�ﵽ������(�涨Ϊ0.7)������ﵽ���ޣ���Ҫ����ϣ������
void CheckCapacity(HashTable* ht)
{
	assert(ht);
	//˼·������һ���µĹ�ϣ���ȱ���һ��ɹ�ϣ�������е�����ת�Ƶ��µĹ�ϣ��
	//�ڽ��ɹ�ϣ�����٣�����µĹ�ϣ����ɹ�ϣ��ά����ָ��
	HashTable newht;
	int len = 2 * ht->_len;//�±��(����2��������ȽϺ��������̫��̫С)
	if ((ht->_size * 10) / ht->_len > 7)//�������Ӽ���(��Ϊ���������������Ϊ�������޷��븡�������Ƚϣ�����ͬʱ����10��)
	{
		HashTableInit(&newht, len);
		//����һ��ɹ�ϣ�������е�����ת�Ƶ��µĹ�ϣ��
		for (int i = 0; i < ht->_len; i++)
		{
			if (ht->_table[i]._state == EXITST)
			{
				HashTableInsert(&newht, ht->_table[i]._key, ht->_table[i]._value);
			}
		}
		//���پɱ�
		HashTableDestroy(ht);
		//���µĹ�ϣ����ɹ�ϣ��ά����ָ��
		ht->_table = newht._table;
		ht->_size = newht._size;
		ht->_len = newht._len;
	}
}
//���ϣ���в���һ��ֵ
int HashTableInsert(HashTable* ht, HTKeyType key, HTValueType value)
{
	assert(ht);
	//��������Ƿ�ﵽ��������ӣ��ﵽ������
	CheckCapacity(ht);
	//1.ȷ�������λ��
	int index = GetPosition(ht, key);
	//2.����г�ͻ�������ͻ(��ɢ������̽��)
	while (ht->_table[index]._state == EXITST)
	{
		//���������Ҫ��������ݣ������ʧ��
		if (ht->_table[index]._key == key)
		{
			return 0;
		}
		//��ɢ������̽�⣬����һ������λ��
		else
		{
			++index;
		}
	}
	//3.�ҵ�����λ�ã�ֱ�Ӳ���
	ht->_table[index]._state = EXITST;
	ht->_table[index]._key = key;
	ht->_table[index]._value = value;
	ht->_size++;
}
//�ڹ�ϣ���в���һ��ֵ
int HashTableRemove(HashTable* ht, HTKeyType key)
{
	assert(ht);
	//1.�ҵ�Ҫɾ��Ԫ�ص�λ��
	HashData* ret = HashTableFind(ht, key);
	//2.��Ϊ�����ҵ���ֱ���޸�״̬ɾ����ɾ���ɹ�����1
	if (ret)
	{
		ht->_size--;
		ret->_state = DELETE;
		return 1;
	}
	//ɾ��ʧ�ܷ���0
	return 0;
}
//�ڹ�ϣ���в���һ��ֵ
HashData* HashTableFind(HashTable* ht, HTKeyType key)
{
	assert(ht);
	//1.���ݹ�ϣ������ȷ����ϣ��ַ
	int index = GetPosition(ht, key);
	//2.����г�ͻ�����մ����ͻ�ķ�����ȥ����
	while (ht->_table[index]._state != EMPTY)
	{
		if (ht->_table[index]._key == key)
		{
			//�ҵ����ݲ���״̬Ϊ�����򷵻����ĵ�ַ
			if (ht->_table[index]._state == EXITST)
			{
				return &ht->_table[index];
			}
			//״̬Ϊɾ��״̬��˵��Ҫ�ҵ������Ѿ���ɾ����ֱ�ӷ���
			else
			{
				return NULL;
			}
		}
		//���մ����ͻ�ķ�������̽���������
		else
		{
			++index;
		}
	}
	//�ҵ���˵��û���ҵ�
	return NULL;
}
//��ӡ��ϣ��(�������)
void PrintHashTable(HashTable* ht)
{
	assert(ht);
	for (int i = 0; i < ht->_len; i++)
	{
		if (ht->_table[i]._state == EXITST)
		{
			printf("[%d](%d:%c)\n", i, ht->_table[i]._key, ht->_table[i]._value);
		}
	}
	printf("\n");
}
//�жϹ�ϣ���Ƿ�Ϊ��(�շ���0���ǿշ���1)
int HashTableEmpty(HashTable* ht)
{
	assert(ht);

	return ht->_size == 0 ? 0 : 1;
}
//��ϣ�����ЧԪ�ظ���
int HashTableSize(HashTable* ht)
{
	assert(ht);

	return ht->_size;
}