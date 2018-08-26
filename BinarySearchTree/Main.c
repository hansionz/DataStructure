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
	printf("要找的数字为：%d\n", BSTreeFindR(&st, 2)->_data);
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
		//输入exit则结束
		if (strcmp(str, "exit") == 0)
		{
			break;
		}
		BSTKeyValueNode* fnode = BSTKVFind(&kvr, str);
		//如果二叉搜索树中存在结点，则只改变它的value域，记录次数
		if (fnode)
		{
			fnode->_value++;
		}
		//不存在，则插入此结点
		else
		{
			BSTKVInsert(&kvr, str, 1);
		}
	}
	//中序遍历看结果
	BSTKVInorder(&kvr);
}
int main()
{
	/*TestBSTree();*/
	TestBSKVTree();
	return 0;
}