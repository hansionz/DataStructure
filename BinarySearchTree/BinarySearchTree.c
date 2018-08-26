#include "BinarySearchTree.h"
//创建一个新的二叉搜索树结点
BSTreeNode* BuyBSTreeNode(BSTDataType x)
{
	BSTreeNode* ret = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	if (ret != NULL)
	{
		ret->_data = x;
		ret->_left = NULL;
		ret->_right = NULL;
	}
	else
	{
		perror("use malloc");
	}
	return ret;
}
//插入一个结点
int BSTreeInsert(BSTreeNode** root, BSTDataType x)
{
	assert(root);

	BSTreeNode* cur = *root;
	BSTreeNode* parent = NULL;//记录要插入位置的母亲
	//当二叉搜索树没有结点时，必须要改变指针的指向，让它指向第一个结点，所有要传地址(二级指针)
	//插入成功返回1
	if (*root == NULL)
	{
		*root = BuyBSTreeNode(x);
		return 1;
	}
	else//二叉搜索树中有结点
	{
		//1.寻找插入位置
		while (cur != NULL)
		{
			if (cur->_data > x)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_data < x)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				//如果二叉搜索树中有和要插入结点一样的数据，则插入失败，返回0
				return 0;
			}
		}
		//parent为插入结点的母亲，比较确定插入位置在左还是右最后插入
		if (parent->_data > x)
		{
			parent->_left = BuyBSTreeNode(x);
			return 1;
		}
		else
		{
			parent->_right = BuyBSTreeNode(x);
			return 1;
		}
	}
}
//删除一个结点

//查找一个结点
//(根据二叉搜索树的特点，左树都小于根节点，右树都大于根节点的特点和已知值相比遍历二叉搜索树来查找)
//这里直接给一级指针也可以，为了和上边操作统一才弄得二级指针
BSTreeNode* BSTreeFind(BSTreeNode** root, BSTDataType x)
{
	assert(root);

	BSTreeNode* cur = *root;
	while (cur)
	{
		//x大于当前结点，必然在右树
		if (cur->_data < x)
		{
			cur = cur->_right;
		}
		//x小于当前结点，必然在左树
		else if (cur->_data>x)
		{
			cur = cur->_left;
		}
		else
		{
			//相等则返回它的指针
			return cur;
		}
	}
	//遍历结束则没有找到，返回NULL
	return NULL;
}

//中序遍历二叉搜索树(递归)
void BSTreeInOrder(BSTreeNode** root)
{
	assert(root);
	if ((*root) == NULL)
	{
		return;
	}
	BSTreeInOrder(&(*root)->_left);
	printf("%d ", (*root)->_data);
	BSTreeInOrder(&(*root)->_right);
}

int BSTreeInsertR(BSTreeNode** root, BSTDataType x)
{
	assert(root);
	//树为空，改变指向根节点指针的指向，要用二级指针
	if ((*root) == NULL)
	{
		*root = BuyBSTreeNode(x);
		return 1;
	}
	//树不为空
	//要插入的数小于根节点的数，则在插入位置在左子树
	if ((*root)->_data > x)
	{
		BSTreeInsertR(&(*root)->_left, x);
	}
	//要插入的数大于根节点的数，则在插入位置在右子树
	else if ((*root)->_data < x)
	{
		BSTreeInsertR(&(*root)->_right, x);
	}
	//要插入的数等于根节点的数，说明此数据不能插入，插入失败
	else
	{
		return 0;
	}
}
BSTreeNode* BSTreeFindR(BSTreeNode** root, BSTDataType x)
{
	assert(root);
	//根为空，直接返回NULL
	if (*root == NULL)
	{
		return NULL;
	}
	//左子树查找
	if ((*root)->_data > x)
	{
		BSTreeFindR(&(*root)->_left, x);
	}
	//右子树查找
	else if ((*root)->_data < x)
	{
		BSTreeFindR(&(*root)->_right, x);
	}
	//相等则返回地址
	else
	{
		return *root;
	}
}
//删除一个结点(成功返回1，失败返回0)
int BSTreeRemoveR(BSTreeNode** root, BSTDataType x)
{
	assert(root);
	//树为空，删除失败
	if ((*root) == NULL)
	{
		return 0;
	}
	//要删除的数小于根结点的数，说明要删除的结点在左树
	if ((*root)->_data > x)
	{
		BSTreeRemoveR(&(*root)->_left, x);
	}
	//要删除的数大于根结点的数，说明要删除的结点在右树
	else if ((*root)->_data < x)
	{
		BSTreeRemoveR(&(*root)->_right, x);
	}
	//*root一定为要删除的结点
	else
	{
		//记录要释放的结点
		BSTreeNode* del = *root;
		//1.左子树为空或者右子树为空
		if ((*root)->_left == NULL)
		{
			*root = (*root)->_right;
			free(del);
		}
		else if ((*root)->_right == NULL)
		{
			*root = (*root)->_left;
			free(del);
		}
		//2.左右子树都不为空(替换删除法)
		else
		{
			BSTreeNode* repalce = (*root)->_right;
			while (repalce->_left)
			{
				repalce = repalce->_left;
			}
			(*root)->_data = repalce->_data;
			BSTreeRemoveR(&(*root)->_right, repalce->_data);
		}
		return 1;
	}
}

/**********************************************************************/
/*key-value*/
//创建一个新的结点
BSTKeyValueNode* BuyBSTKeyValueNode(BSTKeyType key,BSTValueType value)
{
	BSTKeyValueNode* tmp = (BSTKeyValueNode*)malloc(sizeof(BSTKeyValueNode));
	if (tmp == NULL)
	{
		perror("use malloc of create");
	}
	tmp->_key = (char*)malloc(strlen(key) + 1);
	strcpy(tmp->_key, key);//字符串(char*)不能直接赋值，要用strcpy拷贝
	tmp->_value = value;
	tmp->_left = NULL;
	tmp->_right = NULL;

	return tmp;
}
//新插入一个结点(插入成功返回1，失败返回0)
int BSTKVInsert(BSTKeyValueNode** kvroot, BSTKeyType key, BSTValueType value)
{
	assert(kvroot);

	BSTKeyValueNode* cur = *kvroot;
	BSTKeyValueNode* parent = NULL;//用来记录要插入结点的双亲
	//整棵树为空，插入第一个结点(这里要改变根节点指针的指向，必须要用二级指针)
	if (*kvroot == NULL)
	{
		*kvroot = BuyBSTKeyValueNode(key, value);
		return 1;
	}
	//1.找到插入位置
	while (cur)
	{
		if (strcmp(cur->_key, key) > 0)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (strcmp(cur->_key, key) < 0)
		{
			parent = cur;
			cur = cur->_right;
		}
		//如果存在相同的数据，则插入失败
		else
		{
			return 0;
		}
	}
	//2.parent为插入结点的双亲，在确定要插入的结点在左还是右，然后直接插入
	if (strcmp(parent->_key, key) > 0)
	{
		parent->_left = BuyBSTKeyValueNode(key, value);
	}
	else
	{
		parent->_right = BuyBSTKeyValueNode(key, value);
	}
	return 1;
}
//在二叉树中找一个结点
BSTKeyValueNode* BSTKVFind(BSTKeyValueNode** kvroot, BSTKeyType key)
{
	assert(kvroot);

	BSTKeyValueNode* cur = *kvroot;
	//根据二叉搜索树的性质比较遍历一遍
	while (cur)
	{
		if (strcmp(cur->_key, key) > 0)
		{
			cur = cur->_left;
		}
		else if (strcmp(cur->_key, key) < 0)
		{
			cur = cur->_right;
		}
		else
		{
			//找到返回它的地址
			return cur;
		}
	}
	//找不到返回NULL
	return NULL;
}
//中序遍历(方便测试使用)
void BSTKVInorder(BSTKeyValueNode** kvroot)
{
	assert(kvroot);

	if (*kvroot == NULL)
	{
		return;
	}
	BSTKVInorder(&(*kvroot)->_left);
	printf("%s:%d\n", (*kvroot)->_key, (*kvroot)->_value);
	BSTKVInorder(&(*kvroot)->_right);
}