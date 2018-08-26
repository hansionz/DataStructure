#include "BinaryTree.h"

int size;

void TestBinaryTree()
{
	size_t i = 0;
	BTDataType arr[] = { 'A', 'B', 'D', '#', '#', '#', 'C', 'E', '#', '#', 'F', '#', '#' };
	/*BTDataType arr[] = { 'A', 'B', '#', '#', 'C', '#', '#' };*/
	BTNode* root = BinaryTreeCreate(arr, sizeof(arr) / sizeof(arr[0]), &i);
	//前序
	BinaryTreePrevOrder_R(root);
	printf("\n");
	BinaryTreePrevOrder(root);
	printf("\n");
	//中序
	BinaryTreeMidOrder_R(root);
	printf("\n");
	BinaryTreeMidOrder(root);
	printf("\n");
	//后序
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
	printf("要找的结点是：%c\n", ret->_data);
	printf("二叉树的深度为：%d\n", BinaryTreeHigh(root));
	printf("第K层：%d\n", BinaryTreeLevelKSize(root, 3));
	printf("叶子：%d\n", BinaryTreeLeafSzie(root));
	printf("x的父母是：%c\n", BinaryTreeFindParent(root, 'F')->_data);
	BinaryTreeLeafSzie_C(root);
	printf("叶子结点的个数(递归):%d\n", size);
	printf("总结点：%d\n", BinaryTreeSize(root));
	printf("是不是完全二叉树(是：1，不是：0)%d\n", BinaryTreeIsCompleteTree(root));
	BinaryTreeDestroy(&root);
}
int main()
{
	TestBinaryTree();
	return 0;
}