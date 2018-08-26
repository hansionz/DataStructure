#include "BinaryTree.h"

//��ʼ������
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->front = NULL;
	pq->rear = NULL;
}
//���ٶ���
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->front;
	while (cur)
	{
		QueueNode* tmp = cur->_next;
		free(cur);
		cur = tmp;
	}
	pq->front = pq->rear = NULL;
}
//�����µĽ��
QueueNode* BuyQueueNode(QDataType x)
{
	QueueNode* tmp = (QueueNode*)malloc(sizeof(QueueNode));
	if (tmp == NULL)
	{
		perror("use malloc");
	}
	tmp->_next = NULL;
	tmp->_data = x;
	return tmp;
}
//��Ӳ���(��β)
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	if (pq->front == NULL)
	{
		QueueNode *next = BuyQueueNode(x);
		pq->rear = next;
		pq->front = next;
	}
	else
	{
		QueueNode *next = BuyQueueNode(x);
		pq->rear->_next = next;
		pq->rear = next;
	}
}
//���Ӳ���(��ͷ)
void QueuePop(Queue* pq)
{
	assert(pq);
	QueueNode* next = pq->front->_next;
	free(pq->front);
	pq->front = next;
}
//ȡ��ͷԪ��
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->front->_data;
}
//�ж϶��Ƿ�Ϊ�գ��շ���0���ǿշ���1
int QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->front == NULL ? 0 : 1;
}
//��ʼ��ջ
void StackInit(Stack* ps)
{
	assert(ps);

	ps->_a = (DataType*)malloc(sizeof(DataType)* 3);
	ps->_top = 0;
	ps->_capacity = 3;
}
//����ջ
void StackDestroy(Stack* ps)
{
	assert(ps);

	free(ps->_a);
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}
//��ջ
void StackPush(Stack* ps, DataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		DataType* tmp = realloc(ps->_a, sizeof(DataType)*(ps->_capacity * 2));
		if (tmp != NULL)
		{
			ps->_a = tmp;
		}
		ps->_capacity = 2 * ps->_capacity;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}
//��ջ
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->_top > 0);
	if (StackEmpty(ps))
	{
		ps->_top--;
	}
	else
	{
		return;
	}
}
//ȡջ��Ԫ��
DataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->_top > 0);

	return ps->_a[ps->_top - 1];
}
//�շ���0���ǿշ���1
int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0 ? 0 : 1;
}
//����һ�����������
BTNode* BuyBTNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode != NULL)
	{
		newnode->_data = x;
		newnode->_left = NULL;
		newnode->_right = NULL;
	}
	return newnode;
}
//��һ��ǰ�����У�����һ��������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int *pi)
{
	if (a[*pi] != '#')
	{
		BTNode* root = BuyBTNode(a[*pi]);
		//�ݹ齨��������
		++(*pi);
		root->_left = BinaryTreeCreate(a, n, pi);
		//�ݹ齨��������
		++(*pi);
		root->_right = BinaryTreeCreate(a, n, pi);

		return root;
	}
	else
	{
		return NULL;
	}
}
//���ٶ�����(Ҫ�ú���������٣������ǰ���������Ѹ��ڵ������˾ͻ��Ҳ����������)
void BinaryTreeDestroy(BTNode** newnode)
{
	BTNode* root = *newnode;
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestroy(&root->_left);

	BinaryTreeDestroy(&root->_right);
	free(root);
	root = NULL;
}
//������
int BinaryTreeSize(BTNode* root)
{
	//������ڵ�Ϊ�գ�����0
	if (root == NULL)
	{
		return 0;
	}
	//���򷵻�1���������Ľ���ڼ����������Ľ��
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
//����һ��ȫ�ֱ����������ۼ�
int size = 0;
void BinaryTreeSize_C(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	size++;
	BinaryTreeSize_C(root->_left);
	BinaryTreeSize_C(root->_right);
}
//Ҷ�ӽ��ĸ���
int BinaryTreeLeafSzie(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if ((root->_left == NULL) && (root->_right == NULL))
	{
		return 1;
	}
	return BinaryTreeLeafSzie(root->_left) + BinaryTreeLeafSzie(root->_right);
}
//����ȫ�ֱ����������������������ۼ�
void BinaryTreeLeafSzie_C(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	if ((root->_left == NULL) && (root->_right == NULL))
	{
		size++;
	}
	BinaryTreeLeafSzie_C(root->_left);
	BinaryTreeLeafSzie_C(root->_right);
}
//��K���ж��ٽ��(��������K-1�������������K-1��)
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
//ǰ�����
void BinaryTreePrevOrder_R(BTNode* root)
{
	//��Ϊ�գ�ֱ�ӷ���
	if (root == NULL)
	{
		return;
	}
	//���ʸ�
	printf("%c", root->_data);
	//�ݹ����������
	BinaryTreePrevOrder_R(root->_left);
	//�ݹ����������
	BinaryTreePrevOrder_R(root->_right);
}
//�������
void BinaryTreeMidOrder_R(BTNode* root)
{
	//��Ϊ�գ�ֱ�ӷ���
	if (root == NULL)
	{
		return;
	}
	//�ݹ����������
	BinaryTreeMidOrder_R(root->_left);
	//���ʸ�
	printf("%c", root->_data);
	//�ݹ����������
	BinaryTreeMidOrder_R(root->_right);
}
//�������
void BinaryTreePostOrder_R(BTNode* root)
{
	//��Ϊ�գ�ֱ�ӷ���
	if (root == NULL)
	{
		return;
	}
	//�ݹ����������
	BinaryTreePostOrder_R(root->_left);
	//�ݹ����������
	BinaryTreePostOrder_R(root->_right);
	//���ʸ�
	printf("%c", root->_data);
}
//����������һ�����(�ҵ�����ָ�룬�Ҳ�������NULL)
BTNode* BinaryTreeFind(BTNode* root,BTDataType x)
{
	BTNode* ret;
	if ((root == NULL)||(root->_data == x))
	{
		return root;
	}
	ret = BinaryTreeFind(root->_left, x);
	if (ret)
		return ret;
	ret = BinaryTreeFind(root->_right, x);
	if (ret)
		return ret;
	return NULL;
	/*return BinaryTreeFind(root->_right, x);*/
}
//�������ĸ߶�(�Ƚ����������Ǹ��ߣ��ߵļ�1��Ϊ�������ĸ߶�)
int BinaryTreeHigh(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int ret1 = BinaryTreeHigh(root->_left);
	int ret2 = BinaryTreeHigh(root->_right);

	return ret1 > ret2 ? ret1 + 1 : ret2 + 1;
}
//��α���
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	if (root == NULL)
	{
		return;
	}
	QueueInit(&q);
	QueuePush(&q, root);
	while (QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		printf("%c", front->_data);
		QueuePop(&q);
		if (front->_left)
			QueuePush(&q, front->_left);
		if (front->_right)
			QueuePush(&q, front->_right);
	}
}
//�ж϶������ǲ�����ȫ������(�Ƿ���1�����Ƿ���0)
int BinaryTreeIsCompleteTree(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (QueueEmpty(&q) != 0)
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front != NULL)
		{
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		else
		{
			break;
		}
	}
	while (QueueEmpty(&q) != 0)
	{
		if (QueueFront(&q))
		{
			return 0;
		}
		QueuePop(&q);
	}
	return 1;
}
//���ؽ���˫�׽��
BTNode* BinaryTreeFindParent(BTNode* root, BTDataType x)
{
	if ((root == NULL) || (root->_data == x))
	{
		return NULL;
	}
	if (root->_left)
	{
		if (root->_left->_data == x)
		{
			return root;
		}
	}
	if (root->_right)
	{
		if (root->_right->_data == x)
		{
			return root;
		}
	}
	BTNode* ret = BinaryTreeFindParent(root->_left, x);
	if (ret)
		return ret;
	ret = BinaryTreeFindParent(root->_right, x);
	if (ret)
		return ret;
	return NULL;
}
//ǰ�����(�ǵݹ�)
void BinaryTreePrevOrder(BTNode* root)
{
	Stack s;
	StackInit(&s);
	BTNode* cur = root;
	//cur�����ڿ�˵����·���н��û�з��ʣ�ջ��Ϊ��˵����������δ������
	while (cur || StackEmpty(&s) != 0)
	{
		//1.������·��㣬��ѹջ
		while (cur)
		{
			printf("%c", cur->_data);
			StackPush(&s, cur);
			cur = cur->_left;
		}
		//2.��ջ�������˵�������Ѿ������ʹ���
		BTNode* top = StackTop(&s);
		StackPop(&s);
		//3.�������������
		cur = top->_right;
	}
}
//�������(�ǵݹ�)
void BinaryTreeMidOrder(BTNode* root)
{
	Stack s;
	StackInit(&s);
	BTNode* cur = root;
	//cur�����ڿ�˵����·���н��û��ѹջ��ջ��Ϊ��˵����������δ������
	while (cur || StackEmpty(&s) != 0)
	{
		//1.�Ƚ���·���ѹջ
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		//2.��ջ˵�������Ѿ��������ˣ����ڷ��ʸ��ڵ�
		BTNode* top = StackTop(&s);
		printf("%c", top->_data);
		StackPop(&s);
		//�������������
		cur = top->_right;
	}
}
//�������(�ǵݹ�)
void BinaryTreePostOrder(BTNode* root)
{
	Stack s;
	StackInit(&s);
	BTNode* cur = root;
	BTNode* prev = NULL;
	//cur�����ڿ�˵����·���н��û��ѹջ��ջ��Ϊ��˵����������δ������
	while (cur || StackEmpty(&s))
	{
		//1.����·���ѹջ
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		//2.ȡջ������ջ˵����·����Ѿ�����
		BTNode* top = StackTop(&s);
		//3.�����ǰ�������Ϊ�գ���ֱ�ӷ��ʸýڵ㣻
		//  ����������ڣ������Ѿ����ʹ�����ֱ�ӷ�����
		//(prev��ǰһ�������ʹ��Ľ�㣬��������ĸ��ڵ����prev,��˵�����������ʹ�)
		if ((top->_right == NULL)||(prev == top->_right))
		{
			printf("%c", top->_data);
			prev = top;
			StackPop(&s);
		}
		//����������ڣ�����û�з��ʹ�����ȥ������������(������)
		else
		{
			cur = top->_right;
		}
	}
}
//�������ľ���(������������)
void BinaryTreeSwapSub_R(BTNode* root)
{
	//���ֻ��һ����������û�н�㣬ֱ�ӽ���
	if ((root == NULL)||((root->_left == NULL)&&(root->_right == NULL)))
	{
		return;
	}
	//�������ڵ���������
	BTNode* tmp = root->_left;
	root->_left = root->_right;
	root->_right = tmp;
	//�ݹ齻��������
	if (root->_left)
		BinaryTreeSwapSub_R(root->_left);
	//�ݹ齻��������
	if (root->_right)
		BinaryTreeSwapSub_R(root->_right);
}
//����������(�ǵݹ�)
void BinaryTreeSwapSub(BTNode* root)
{
	//���ֻ��һ����������û�н�㣬ֱ�ӽ���
	if ((root == NULL) || ((root->_left == NULL) && (root->_right == NULL)))
	{
		return;
	}
	BTNode* cur = root;
	BTNode* prev = NULL;
	Stack s;
	StackInit(&s);
	//cur�����ڿ�˵����·���н��û��ѹջ��ջ��Ϊ��˵����������������δ������
	while (cur || StackEmpty(&s) != 0)
	{
		//����·�Ľ��ѹջ
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		BTNode* top = StackTop(&s);
		//prev�Ǽ�¼��һ�������Ľ�㣬���prev==top->_right˵�����������Ѿ���������
		//�����������Ϊ�գ���ֱ�ӽ���
		if ((prev==top->_right) || (top->_right == NULL))
		{
			BTNode* tmp = top->_left;
			top->_left = top->_right;
			top->_right = tmp;
			prev = top;
			StackPop(&s);
		}
		//�������������
		else
		{
			cur = top->_right;
		}
	}
}