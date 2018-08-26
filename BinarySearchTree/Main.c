#include "BinarySearchTree.h"

void TestBSTree()
{
	BSTreeNode* st = NULL;
	int arr[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		BSTreeInsertR(&st, arr[i]);
	}
	BSTreeInOrder(&st);
	printf("\n");
	BSTreeRemoveR(&st, 1);
	printf("Ҫ�ҵ�����Ϊ��%d\n", BSTreeFindR(&st, 2)->_data);
	BSTreeInOrder(&st);
	printf("\n");
}
void TestBSKVTree()
{
	BSTKeyValueNode* kvr = NULL;
	char str[20] = { '0' };
	while (1)
	{
		scanf("%s", str);
		//����exit�����
		if (strcmp(str, "exit") == 0)
		{
			break;
		}
		BSTKeyValueNode* fnode = BSTKVFind(&kvr, str);
		//��������������д��ڽ�㣬��ֻ�ı�����value�򣬼�¼����
		if (fnode)
		{
			fnode->_value++;
		}
		//�����ڣ������˽��
		else
		{
			BSTKVInsert(&kvr, str, 1);
		}
	}
	//������������
	BSTKVInorder(&kvr);
}
int main()
{
	/*TestBSTree();*/
	TestBSKVTree();
	return 0;
}