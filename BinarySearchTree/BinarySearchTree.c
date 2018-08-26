#include "BinarySearchTree.h"
//����һ���µĶ������������
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
//����һ�����
int BSTreeInsert(BSTreeNode** root, BSTDataType x)
{
	assert(root);

	BSTreeNode* cur = *root;
	BSTreeNode* parent = NULL;//��¼Ҫ����λ�õ�ĸ��
	//������������û�н��ʱ������Ҫ�ı�ָ���ָ������ָ���һ����㣬����Ҫ����ַ(����ָ��)
	//����ɹ�����1
	if (*root == NULL)
	{
		*root = BuyBSTreeNode(x);
		return 1;
	}
	else//�������������н��
	{
		//1.Ѱ�Ҳ���λ��
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
				//����������������к�Ҫ������һ�������ݣ������ʧ�ܣ�����0
				return 0;
			}
		}
		//parentΪ�������ĸ�ף��Ƚ�ȷ������λ����������������
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
//ɾ��һ�����

//����һ�����
//(���ݶ������������ص㣬������С�ڸ��ڵ㣬���������ڸ��ڵ���ص����ֵ֪��ȱ�������������������)
//����ֱ�Ӹ�һ��ָ��Ҳ���ԣ�Ϊ�˺��ϱ߲���ͳһ��Ū�ö���ָ��
BSTreeNode* BSTreeFind(BSTreeNode** root, BSTDataType x)
{
	assert(root);

	BSTreeNode* cur = *root;
	while (cur)
	{
		//x���ڵ�ǰ��㣬��Ȼ������
		if (cur->_data < x)
		{
			cur = cur->_right;
		}
		//xС�ڵ�ǰ��㣬��Ȼ������
		else if (cur->_data>x)
		{
			cur = cur->_left;
		}
		else
		{
			//����򷵻�����ָ��
			return cur;
		}
	}
	//����������û���ҵ�������NULL
	return NULL;
}

//�����������������(�ݹ�)
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
	//��Ϊ�գ��ı�ָ����ڵ�ָ���ָ��Ҫ�ö���ָ��
	if ((*root) == NULL)
	{
		*root = BuyBSTreeNode(x);
		return 1;
	}
	//����Ϊ��
	//Ҫ�������С�ڸ��ڵ���������ڲ���λ����������
	if ((*root)->_data > x)
	{
		BSTreeInsertR(&(*root)->_left, x);
	}
	//Ҫ����������ڸ��ڵ���������ڲ���λ����������
	else if ((*root)->_data < x)
	{
		BSTreeInsertR(&(*root)->_right, x);
	}
	//Ҫ����������ڸ��ڵ������˵�������ݲ��ܲ��룬����ʧ��
	else
	{
		return 0;
	}
}
BSTreeNode* BSTreeFindR(BSTreeNode** root, BSTDataType x)
{
	assert(root);
	//��Ϊ�գ�ֱ�ӷ���NULL
	if (*root == NULL)
	{
		return NULL;
	}
	//����������
	if ((*root)->_data > x)
	{
		BSTreeFindR(&(*root)->_left, x);
	}
	//����������
	else if ((*root)->_data < x)
	{
		BSTreeFindR(&(*root)->_right, x);
	}
	//����򷵻ص�ַ
	else
	{
		return *root;
	}
}
//ɾ��һ�����(�ɹ�����1��ʧ�ܷ���0)
int BSTreeRemoveR(BSTreeNode** root, BSTDataType x)
{
	assert(root);
	//��Ϊ�գ�ɾ��ʧ��
	if ((*root) == NULL)
	{
		return 0;
	}
	//Ҫɾ������С�ڸ���������˵��Ҫɾ���Ľ��������
	if ((*root)->_data > x)
	{
		BSTreeRemoveR(&(*root)->_left, x);
	}
	//Ҫɾ���������ڸ���������˵��Ҫɾ���Ľ��������
	else if ((*root)->_data < x)
	{
		BSTreeRemoveR(&(*root)->_right, x);
	}
	//*rootһ��ΪҪɾ���Ľ��
	else
	{
		//��¼Ҫ�ͷŵĽ��
		BSTreeNode* del = *root;
		//1.������Ϊ�ջ���������Ϊ��
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
		//2.������������Ϊ��(�滻ɾ����)
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
//����һ���µĽ��
BSTKeyValueNode* BuyBSTKeyValueNode(BSTKeyType key,BSTValueType value)
{
	BSTKeyValueNode* tmp = (BSTKeyValueNode*)malloc(sizeof(BSTKeyValueNode));
	if (tmp == NULL)
	{
		perror("use malloc of create");
	}
	tmp->_key = (char*)malloc(strlen(key) + 1);
	strcpy(tmp->_key, key);//�ַ���(char*)����ֱ�Ӹ�ֵ��Ҫ��strcpy����
	tmp->_value = value;
	tmp->_left = NULL;
	tmp->_right = NULL;

	return tmp;
}
//�²���һ�����(����ɹ�����1��ʧ�ܷ���0)
int BSTKVInsert(BSTKeyValueNode** kvroot, BSTKeyType key, BSTValueType value)
{
	assert(kvroot);

	BSTKeyValueNode* cur = *kvroot;
	BSTKeyValueNode* parent = NULL;//������¼Ҫ�������˫��
	//������Ϊ�գ������һ�����(����Ҫ�ı���ڵ�ָ���ָ�򣬱���Ҫ�ö���ָ��)
	if (*kvroot == NULL)
	{
		*kvroot = BuyBSTKeyValueNode(key, value);
		return 1;
	}
	//1.�ҵ�����λ��
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
		//���������ͬ�����ݣ������ʧ��
		else
		{
			return 0;
		}
	}
	//2.parentΪ�������˫�ף���ȷ��Ҫ����Ľ���������ң�Ȼ��ֱ�Ӳ���
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
//�ڶ���������һ�����
BSTKeyValueNode* BSTKVFind(BSTKeyValueNode** kvroot, BSTKeyType key)
{
	assert(kvroot);

	BSTKeyValueNode* cur = *kvroot;
	//���ݶ��������������ʱȽϱ���һ��
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
			//�ҵ��������ĵ�ַ
			return cur;
		}
	}
	//�Ҳ�������NULL
	return NULL;
}
//�������(�������ʹ��)
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