#include "BinaryTree.h"

//初始化队列
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->front = NULL;
	pq->rear = NULL;
}
//销毁队列
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
//开辟新的结点
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
//入队操作(队尾)
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
//出队操作(队头)
void QueuePop(Queue* pq)
{
	assert(pq);
	QueueNode* next = pq->front->_next;
	free(pq->front);
	pq->front = next;
}
//取队头元素
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->front->_data;
}
//判断队是否为空，空返回0，非空返回1
int QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->front == NULL ? 0 : 1;
}
//初始化栈
void StackInit(Stack* ps)
{
	assert(ps);

	ps->_a = (DataType*)malloc(sizeof(DataType)* 3);
	ps->_top = 0;
	ps->_capacity = 3;
}
//销毁栈
void StackDestroy(Stack* ps)
{
	assert(ps);

	free(ps->_a);
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}
//入栈
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
//出栈
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
//取栈顶元素
DataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->_top > 0);

	return ps->_a[ps->_top - 1];
}
//空返回0，非空返回1
int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0 ? 0 : 1;
}
//创建一个二叉树结点
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
//给一个前序序列，创建一个二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int *pi)
{
	if (a[*pi] != '#')
	{
		BTNode* root = BuyBTNode(a[*pi]);
		//递归建立左子树
		++(*pi);
		root->_left = BinaryTreeCreate(a, n, pi);
		//递归建立右子树
		++(*pi);
		root->_right = BinaryTreeCreate(a, n, pi);

		return root;
	}
	else
	{
		return NULL;
	}
}
//销毁二叉树(要用后序遍历销毁，如果用前序或者中序把根节点销毁了就会找不到其他结点)
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
//结点个数
int BinaryTreeSize(BTNode* root)
{
	//如果根节点为空，返回0
	if (root == NULL)
	{
		return 0;
	}
	//否则返回1加左子树的结点在加上右字数的结点
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
//定义一个全局变量，遍历累加
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
//叶子结点的个数
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
//定义全局变量，遍历符合条件的则累加
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
//第K层有多少结点(左子树的K-1层加上右子树的K-1层)
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
//前序遍历
void BinaryTreePrevOrder_R(BTNode* root)
{
	//树为空，直接返回
	if (root == NULL)
	{
		return;
	}
	//访问根
	printf("%c", root->_data);
	//递归访问左子树
	BinaryTreePrevOrder_R(root->_left);
	//递归访问右子树
	BinaryTreePrevOrder_R(root->_right);
}
//中序遍历
void BinaryTreeMidOrder_R(BTNode* root)
{
	//树为空，直接返回
	if (root == NULL)
	{
		return;
	}
	//递归访问左子树
	BinaryTreeMidOrder_R(root->_left);
	//访问根
	printf("%c", root->_data);
	//递归访问右子树
	BinaryTreeMidOrder_R(root->_right);
}
//后序遍历
void BinaryTreePostOrder_R(BTNode* root)
{
	//树为空，直接返回
	if (root == NULL)
	{
		return;
	}
	//递归访问左子树
	BinaryTreePostOrder_R(root->_left);
	//递归访问右子树
	BinaryTreePostOrder_R(root->_right);
	//访问根
	printf("%c", root->_data);
}
//二叉树中找一个结点(找到返回指针，找不到返回NULL)
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
//二叉树的高度(比较左右子树那个高，高的加1既为二叉树的高度)
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
//层次遍历
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
//判断二叉树是不是完全二叉树(是返回1，不是返回0)
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
//返回结点的双亲结点
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
//前序遍历(非递归)
void BinaryTreePrevOrder(BTNode* root)
{
	Stack s;
	StackInit(&s);
	BTNode* cur = root;
	//cur不等于空说明左路还有结点没有访问，栈不为空说明还有右树未曾访问
	while (cur || StackEmpty(&s) != 0)
	{
		//1.访问左路结点，并压栈
		while (cur)
		{
			printf("%c", cur->_data);
			StackPush(&s, cur);
			cur = cur->_left;
		}
		//2.从栈里出来，说明左树已经被访问过了
		BTNode* top = StackTop(&s);
		StackPop(&s);
		//3.子问题访问右树
		cur = top->_right;
	}
}
//中序遍历(非递归)
void BinaryTreeMidOrder(BTNode* root)
{
	Stack s;
	StackInit(&s);
	BTNode* cur = root;
	//cur不等于空说明左路还有结点没有压栈，栈不为空说明还有右树未曾访问
	while (cur || StackEmpty(&s) != 0)
	{
		//1.先将左路结点压栈
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		//2.出栈说明左树已经访问完了，现在访问根节点
		BTNode* top = StackTop(&s);
		printf("%c", top->_data);
		StackPop(&s);
		//子问题访问右树
		cur = top->_right;
	}
}
//后序遍历(非递归)
void BinaryTreePostOrder(BTNode* root)
{
	Stack s;
	StackInit(&s);
	BTNode* cur = root;
	BTNode* prev = NULL;
	//cur不等于空说明左路还有结点没有压栈，栈不为空说明还有右树未曾访问
	while (cur || StackEmpty(&s))
	{
		//1.将左路结点压栈
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		//2.取栈顶，出栈说明左路结点已经访问
		BTNode* top = StackTop(&s);
		//3.如果当前结点右树为空，则直接访问该节点；
		//  如果右树存在，并且已经访问过，则直接访问它
		//(prev是前一个被访问过的结点，如果右树的根节点等于prev,则说明右树被访问过)
		if ((top->_right == NULL)||(prev == top->_right))
		{
			printf("%c", top->_data);
			prev = top;
			StackPop(&s);
		}
		//如果右树存在，并且没有访问过，则去访问它的右树(子问题)
		else
		{
			cur = top->_right;
		}
	}
}
//二叉树的镜像(交换左右子树)
void BinaryTreeSwapSub_R(BTNode* root)
{
	//如果只有一个结点或者是没有结点，直接结束
	if ((root == NULL)||((root->_left == NULL)&&(root->_right == NULL)))
	{
		return;
	}
	//交换根节点左右子树
	BTNode* tmp = root->_left;
	root->_left = root->_right;
	root->_right = tmp;
	//递归交换左子树
	if (root->_left)
		BinaryTreeSwapSub_R(root->_left);
	//递归交换右子树
	if (root->_right)
		BinaryTreeSwapSub_R(root->_right);
}
//二叉树镜像(非递归)
void BinaryTreeSwapSub(BTNode* root)
{
	//如果只有一个结点或者是没有结点，直接结束
	if ((root == NULL) || ((root->_left == NULL) && (root->_right == NULL)))
	{
		return;
	}
	BTNode* cur = root;
	BTNode* prev = NULL;
	Stack s;
	StackInit(&s);
	//cur不等于空说明左路还有结点没有压栈，栈不为空说明还有右树的左右未曾交换
	while (cur || StackEmpty(&s) != 0)
	{
		//将左路的结点压栈
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		BTNode* top = StackTop(&s);
		//prev是记录上一个交换的结点，如果prev==top->_right说明它的右树已经交换过了
		//如果它的右树为空，则直接交换
		if ((prev==top->_right) || (top->_right == NULL))
		{
			BTNode* tmp = top->_left;
			top->_left = top->_right;
			top->_right = tmp;
			prev = top;
			StackPop(&s);
		}
		//子问题继续交换
		else
		{
			cur = top->_right;
		}
	}
}