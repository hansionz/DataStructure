#include "HashTable.h"
#include"HashTableBucket.h"

void TestHashTable()
{
	HashTable ht;
	char* strs[] = { "insert", "insert", "find", "exit", "six", "six", "six" };
}
void TestHashTable()
{
	HashTable ht;
	HashTableInit(&ht, 5);
	HashTableInsert(&ht, 7, 'f');
	HashTableInsert(&ht, 17, 't');
	HashTableInsert(&ht, 27, 's');
	HashTableInsert(&ht, 8, 's');
	HashTableInsert(&ht, 23, 's');
	HashTableInsert(&ht, 46, 's');
	HashData* ret = HashTableFind(&ht, 8);
	printf("state:%d,key:%d,value:%c\n", ret->_state, ret->_key, ret->_value);
	//printf("哈希表的大小：%d\n", HashTableSize(&ht));
	HashTableRemove(&ht, 8);
	//printf("哈希表的大小：%d\n", HashTableSize(&ht));
	//HashTableInsert(&ht, 59, 's');
	//HashTableInsert(&ht, 31, 's');
	//printf("哈希表的大小：%d\n", HashTableSize(&ht));
	PrintHashTable(&ht);
	HashTableDestroy(&ht);
	/*char str[] = "傻逼";
	char str1[5] = { 0 };
	str1[0] = -55;
	str1[1] = -76;   
	str1[2] = -79;
	str1[3] = -56;
	str1[4] = '\0';
	printf("%s\n", str1);*/
}
void TestHashTableBucket()
{
	HTB htb;
	HTBInit(&htb, 10);
	HTBInsert(&htb, "like", "insert");
	HTBInsert(&htb, "bit", "insert");
	HTBInsert(&htb, "am", "insert");
	HTBInsert(&htb, "find", "insert");
	HTBInsert(&htb, "insert", "insert");
	/*srand((unsigned int)time(0));
	for (int i = 0; i < 100; i++)
	{
		HTBInsert(&htb, rand()%1000, 10);
	}*/
	/*HTBRemove(&htb, 32);*/
	/*HashNode* ret=HTBFind(&htb, 11);*/
	/*printf("要找的数为:%d\n", ret->_key);*/
	PrintHTB(&htb);
	HTBDestory(&htb);
}
int main()
{
	TestHashTable();
	/*TestHashTableBucket();*/
	return 0;
}