#include "HashTable.h"

void TestHashTable()
{
	HashTable ht;
	HashTableInit(&ht, 5);
	HashTableInsert(&ht, 15, 'f');
	HashTableInsert(&ht, 24, 't');
	HashTableInsert(&ht, 56, 's');
	HashTableInsert(&ht, 71, 's');
	HashTableInsert(&ht, 23, 's');
	HashTableInsert(&ht, 46, 's');
	HashData* ret = HashTableFind(&ht, 71);
	printf("state:%d,key;%d,value:%c\n", ret->_state, ret->_key, ret->_value);
	printf("哈希表的大小：%d\n", HashTableSize(&ht));
	HashTableRemove(&ht, 15);
	printf("哈希表的大小：%d\n", HashTableSize(&ht));
	HashTableInsert(&ht, 59, 's');
	HashTableInsert(&ht, 31, 's');
	printf("哈希表的大小：%d\n", HashTableSize(&ht));
	PrintHashTable(&ht);
	HashTableDestroy(&ht);
}
int main()
{
	TestHashTable();
	return 0;
}