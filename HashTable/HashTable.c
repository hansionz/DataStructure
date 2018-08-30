#include "HashTable.h"

//哈希表的初始化
void HashTableInit(HashTable* ht, size_t len)
{
	assert(ht);
	//动态开辟一个数组
	ht->_table = (HashData*)malloc(sizeof(HashData)*len);
	if (ht->_table == NULL)
	{
		perror("use malloc to create");
	}
	//首先将所有数据的状态都设置为空(EMPTY)
	for (int i = 0; i < ht->_len; i++)
	{
		ht->_table[i]._state = EMPTY;
	}
	ht->_len = len;//哈希表的长度
	ht->_size = 0;//有效元素的个数
}
//销毁哈希表(malloc出来的空间)
void HashTableDestroy(HashTable* ht)
{
	assert(ht);
	free(ht->_table);
	ht->_table = NULL;
	ht->_size = 0;
	ht->_len = 0;
}
//哈希函数，根据哈希函数得到一个地址(采用模留余数法)
int GetPosition(HashTable* ht, HTKeyType key)
{
	assert(ht);
	return key % (ht->_len);
}
//检查负载因子是否达到了上限(规定为0.7)，如果达到上限，则要给哈希表扩容
void CheckCapacity(HashTable* ht)
{
	assert(ht);
	//思路：开辟一个新的哈希表，先遍历一遍旧哈希表，将所有的数据转移到新的哈希表
	//在将旧哈希表销毁，最后将新的哈希表给旧哈希表维护的指针
	HashTable newht;
	int len = 2 * ht->_len;//新表表长(按照2倍来计算比较合理，否则会太大太小)
	if ((ht->_size * 10) / ht->_len > 7)//负载因子计算(因为整数除以整数结果为整数，无法与浮点数作比较，所以同时扩大10倍)
	{
		HashTableInit(&newht, len);
		//遍历一遍旧哈希表，将所有的数据转移到新的哈希表
		for (int i = 0; i < ht->_len; i++)
		{
			if (ht->_table[i]._state == EXITST)
			{
				HashTableInsert(&newht, ht->_table[i]._key, ht->_table[i]._value);
			}
		}
		//销毁旧表
		HashTableDestroy(ht);
		//将新的哈希表给旧哈希表维护的指针
		ht->_table = newht._table;
		ht->_size = newht._size;
		ht->_len = newht._len;
	}
}
//向哈希表中插入一个值
int HashTableInsert(HashTable* ht, HTKeyType key, HTValueType value)
{
	assert(ht);
	//检查容量是否达到最大负载因子，达到则扩容
	CheckCapacity(ht);
	//1.确定插入的位置
	int index = GetPosition(ht, key);
	//2.如果有冲突，处理冲突(闭散列线性探测)
	while (ht->_table[index]._state == EXITST)
	{
		//如果表中有要插入的数据，则插入失败
		if (ht->_table[index]._key == key)
		{
			return 0;
		}
		//闭散列线性探测，找下一个插入位置
		else
		{
			++index;
		}
	}
	//3.找到插入位置，直接插入
	ht->_table[index]._state = EXITST;
	ht->_table[index]._key = key;
	ht->_table[index]._value = value;
	ht->_size++;
}
//在哈希表中查找一个值
int HashTableRemove(HashTable* ht, HTKeyType key)
{
	assert(ht);
	//1.找到要删除元素的位置
	HashData* ret = HashTableFind(ht, key);
	//2.不为空则找到，直接修改状态删除，删除成功返回1
	if (ret)
	{
		ht->_size--;
		ret->_state = DELETE;
		return 1;
	}
	//删除失败返回0
	return 0;
}
//在哈希表中查找一个值
HashData* HashTableFind(HashTable* ht, HTKeyType key)
{
	assert(ht);
	//1.根据哈希哈数先确定哈希地址
	int index = GetPosition(ht, key);
	//2.如果有冲突，按照处理冲突的方法再去查找
	while (ht->_table[index]._state != EMPTY)
	{
		if (ht->_table[index]._key == key)
		{
			//找到数据并且状态为存在则返回它的地址
			if (ht->_table[index]._state == EXITST)
			{
				return &ht->_table[index];
			}
			//状态为删除状态，说明要找的数据已经被删除，直接返回
			else
			{
				return NULL;
			}
		}
		//按照处理冲突的方法线性探测继续查找
		else
		{
			++index;
		}
	}
	//找到空说明没有找到
	return NULL;
}
//打印哈希表(方便测试)
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
//判断哈希表是否为空(空返回0，非空返回1)
int HashTableEmpty(HashTable* ht)
{
	assert(ht);

	return ht->_size == 0 ? 0 : 1;
}
//哈希表的有效元素个数
int HashTableSize(HashTable* ht)
{
	assert(ht);

	return ht->_size;
}