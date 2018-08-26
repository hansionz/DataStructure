#include "BinaryTree.h"

int size;

void TestBinaryTree()
{
	size_t i = 0;
	BTDataType arr[] = { 'A', 'B', 'D', '#', '#', '#', 'C', 'E', '#', '#', 'F', '#', '#' };
	/*BTDataType arr[] = { 'A', 'B', '#', '#', 'C', '#', '#' };*/
	BTNode* root = BinaryTreeCreate(arr, sizeof(arr) / sizeof(arr[0]), &i);
	//ǰ��
	BinaryTreePrevOrder_R(root);
	printf("\n");
	BinaryTreePrevOrder(root);
	printf("\n");
	//����
	BinaryTreeMidOrder_R(root);
	printf("\n");
	BinaryTreeMidOrder(root);
	printf("\n");
	//����
	BinaryTreePostOrder_R(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");

	BinaryTreeSwapSub_R(root);
	BinaryTreeLevelOrder(root);
	printf("\n");
	BinaryTreeSwapSub(root);
	BinaryTreeLevelOrder(root);
	printf("\n");
	BTNode* ret = BinaryTreeFind(root, 'A');
	printf("Ҫ�ҵĽ���ǣ�%c\n", ret->_data);
	printf("�����������Ϊ��%d\n", BinaryTreeHigh(root));
	printf("��K�㣺%d\n", BinaryTreeLevelKSize(root, 3));
	printf("Ҷ�ӣ�%d\n", BinaryTreeLeafSzie(root));
	printf("x�ĸ�ĸ�ǣ�%c\n", BinaryTreeFindParent(root, 'F')->_data);
	BinaryTreeLeafSzie_C(root);
	printf("Ҷ�ӽ��ĸ���(�ݹ�):%d\n", size);
	printf("�ܽ�㣺%d\n", BinaryTreeSize(root));
	printf("�ǲ�����ȫ������(�ǣ�1�����ǣ�0)%d\n", BinaryTreeIsCompleteTree(root));
	BinaryTreeDestroy(&root);
}
int main()
{
	TestBinaryTree();
	return 0;
}