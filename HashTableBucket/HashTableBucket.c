#include"HashTableBucket.h"
//初始化
void HTBInit(HTB* htb, size_t len)
{
	assert(htb);
	//根据素数表获取哈希表的长度
	int HTB_len = GetPrime(len);
	//为哈希表开辟空间(注意二级指针的使用)
	HashNode** table = (HashNode**)malloc(sizeof(HashNode*)*(HTB_len));
	if (table == NULL)
	{
		perror("use malloc of create");
		exit(EXIT_FAILURE);
	}
	htb->_table = table;
	htb->_size = 0;
	htb->_len = HTB_len;
	//将哈希表中的所有指针初始化为空，否则会对野指针操作
	memset(htb->_table, NULL, sizeof(HashNode*)*(htb->_len));
}
//销毁哈希表
void HTBDestory(HTB* htb)
{
	assert(htb);
	int i = 0;
	//1.释放哈希表上每一条链上的结点
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
	//2.释放哈希表(动态开辟的数组)
	free(htb->_table);
	htb->_table = NULL;
	htb->_size = 0;
	htb->_len = 0;
}
//哈希函数,计算哈希地址(字符串，模留余数法)
static int HTBFunc(HTBKeyType key, int len)
{
	int count = 0;
	int i = 0;
	int seed = 31;//31,131(种子)
	while (*(key + i) != '\0')
	{
		count += count*seed + *(key + i);
		++i;
	}
	return count%len;
}
//哈希函数,计算哈希地址(整数)
//static int HTBFunc(HTBKeyType key, int len)
//{
//	return key%len;
//}
//创建哈希结点
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
//检查负载因子是否达到1，如果达到1，则需要扩容，否则查找效率会变慢
void CheckHTBCapacity(HTB* htb)
{
	assert(htb);
	HTB newhtb;
	//根据旧的哈希表长计算新的哈希表长
	int newlen = GetPrime(htb->_len);
	HTBInit(&newhtb, newlen);
	//负载因子达到1，需要扩容
	if (htb->_size == htb->_len)
	{
		for (int i = 0; i < htb->_len; i++)
		{
			HashNode* cur = htb->_table[i];
			while (cur)
			{
				//记录下一个结点的位置
				HashNode* next = cur->_next;
				int index = HTBFunc(cur->_key, newlen);
				//头插到新的哈希表中
				cur->_next = newhtb._table[index];
				newhtb._table[index] = cur;
				cur = next;
			}
			htb->_table[i] = NULL;
		}
		//释放旧表
		free(htb->_table);
		htb->_table = newhtb._table;
		htb->_size = newhtb._size;
		htb->_len = newhtb._len;
	}
}
//向哈希表中插入一个元素
int HTBInsert(HTB* htb, HTBKeyType key, HTBValueType value)
{
	assert(htb);
	int index = HTBFunc(key, htb->_len);
	CheckHTBCapacity(htb);
	HashNode* cur = htb->_table[index];
	HashNode* newnode = BuyHashNode(key, value);
	//头插
	newnode->_next = cur;
	htb->_table[index] = newnode;

	htb->_size++;
	return 1;
}
//删除哈希表中的一个元素
int HTBRemove(HTB* htb, HTBKeyType key)
{
	assert(htb);
	int index = HTBFunc(key, htb->_len);
	HashNode* cur = htb->_table[index];
	HashNode* prev = NULL;//记录要删除结点的前一个结点
	while (cur)
	{
		//要删除的结点是第一个结点，特殊处理
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
//在哈希表中查找一个元素
HashNode* HTBFind(HTB* htb, HTBKeyType key)
{
	assert(htb);
	int index = HTBFunc(key, htb->_len);
	HashNode* cur = htb->_table[index];
	//遍历哈希表，查找
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
//打印哈希表(方便测试)
void PrintHTB(HTB* htb)
{
	assert(htb);
	for (int i = 0; i < htb->_len; i++)
	{
		int count = 0;
		printf("桶[%d]->", i);
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
//哈希表的大小
int HTBSize(HTB* htb)
{
	assert(htb);
	return htb->_size == 0 ? 0 : 1;
}
//哈希表是否为空
int HTBEmpty(HTB* htb)
{
	assert(htb);
	return htb->_size == htb->_len ? 0 : 1;
}
