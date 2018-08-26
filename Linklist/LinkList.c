#include"LinkList.h"

void InitLinkList(pLinkList * ppl)
{
	assert(ppl != NULL);
	*ppl = NULL;
}
pNode BuyNode(DataType data)
{
	pNode tmp = (pNode)malloc(sizeof(Node));
	if (tmp == NULL)
	{
		perror("use malloc");
		return NULL;
	}
	tmp->data = data;
	tmp->next = NULL;
	return tmp;
}
void PushBack(pLinkList *ppl, DataType data)
{
	assert(ppl != NULL);
	pNode newNode = BuyNode(data);
	if (newNode == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (*ppl == NULL)//空链表，直接插入
	{
		(*ppl)= newNode;
	}
	else//非空链表，先找到最后一个节点在插入
	{
		pNode cur = *ppl;
		while ((cur->next)!=NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}
void PopBack(pLinkList* ppl)
{
	assert(ppl != NULL);
	if (*ppl == NULL)
	{
		return;
	}
	if ((*ppl)->next == NULL)
	{
		free(*ppl);
		ppl = NULL;
	}
	else
	{
		pNode cur = *ppl;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}
void PushFront(pLinkList* ppl, DataType data)
{
	assert(ppl != NULL);
	pNode newNode = BuyNode(data);
	newNode->next = *ppl;
	*ppl = newNode;
}
void PopFront(pLinkList* ppl)
{
	assert(ppl != NULL);
	if (*ppl == NULL)
	{
		return;
	}
	else
	{
		pNode del = *ppl;
		*ppl = del->next;
		free(del);
		del = NULL;
	}
}
void PrintLinkList(pLinkList *ppl)
{
	assert(ppl != NULL);
	pNode cur = *ppl;
	while (cur != NULL)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("over\n");
}
void DestoryList(pLinkList *ppl)
{
	assert(ppl != NULL);
	pNode cur = *ppl;
	while (cur != NULL)
	{
		pNode del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	*ppl = NULL;
}
void InitStack(stack * s)
{
	memset(s->data, 0, sizeof(s->data));
	s->top = 0;//初始化栈
}
void PrintLinkTailToHead(pLinkList pl,stack * s)
{
#if 0
	if(pl != NULL)
	{
		if(pl->next != NULL)
		{
			PrintLinkTailToHead(pl->next);
		}
		printf("%d--->",pl->data);
	}
	/*if (pl == NULL)
	{
		return NULL;
	}
	PrintLinkTailToHead(pl->next);
	printf("%d--->", pl->data);*/
#endif
#if 0
	pNode tail = NULL;
	while (pl != tail)
	{
		pNode cur = pl;
		while (cur->next != tail)
		{
			cur = cur->next;
		}
		printf("%d--->", cur->data);
		tail = cur;
	}
#endif
	Node* cur = pl;
	while (cur != NULL)
	{
		s->data[s->top++] = cur->data;
		cur = cur->next;
	}
	while (s->top >= 0)
	{
		printf("%d--->", s->data[s->top--]);
	}
	printf("over\n");
}
void RmoveNodeNotTail(pLinkList *ppl, pNode pos)
{
	pNode del = NULL;
	assert(ppl != NULL);
	assert(pos->next != NULL);
	assert(*ppl != NULL);

	pos->data = pos->next->data;
	del = pos->next;
	pos->next = del->next;

	free(del);
	del = NULL;
}
void Insert(pLinkList* ppl, pNode pos, DataType data)
{
	assert(ppl != NULL);
	assert(pos != NULL);
	assert(*ppl != NULL);
	pNode NewNode = BuyNode(data);
	if (*ppl == pos)
	{
		//前插
		NewNode->next = *ppl;
		*ppl = NewNode;
	}
	else
	{
		pNode cur = *ppl;
		while (cur&&cur->next != pos)
		{
			cur = cur->next;
		}
		NewNode->next = cur->next;
		cur->next = NewNode;
	}
}
void Erase(pLinkList* ppl, pNode pos)
{
	pNode cur = *ppl;
	assert(*ppl != NULL);
	assert(pos != NULL);
	assert(*ppl != NULL);
	if (*ppl == pos)
	{
		*ppl = pos->next;
		free(pos);
		pos = NULL;
	}
	else
	{
		while (cur&&cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
void Remove(pLinkList* ppl, DataType data)
{
	pNode cur = *ppl;
	pNode pre = *ppl;
	assert(ppl != NULL);
	while (cur)
	{
		if (cur->data == data)
		{
			if (*ppl == cur)
			{
				*ppl = cur->next;
				free(cur);
				cur = NULL;
			}
			else
			{
				while (pre&&pre->next != cur)
				{
					pre = pre->next;
				}
				pre->next = cur->next;
				free(cur);
				cur = NULL;
			}
			return;
		}
		cur = cur->next;
	}
}
void RemoveAll(pLinkList* ppl, DataType data)
{
	pNode cur = *ppl;
	pNode pre = *ppl;
	pNode del = NULL;
	assert(ppl != NULL);
	while (cur)
	{
		if (cur->data == data)
		{
			if (*ppl == cur)
			{
				*ppl = cur->next;
				free(cur);
				cur = *ppl;
			}
			else
			{
				del = cur;
				pre->next = cur->next;
				cur = cur->next;
				free(del);
				del = NULL;
			}
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
}
pNode Find(pLinkList plist, DataType data)
{
	pNode cur = plist;
	if (plist == NULL)
	{
		return NULL;
	}
	while (cur)
	{
		if (cur->data == data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
int GetListLength(pLinkList pl)
{
	int count = 0;
	pNode cur = pl;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
void InsertNodeNotHead(pLinkList *ppl, DataType data, pNode pos)
{
	pNode newNode = NULL;
	assert(ppl != NULL);
#if 0
	DataType tmp = 0;
	newNode = BuyNode(data);
	newNode->next = pos->next;
	pos->next = newNode;
	tmp = newNode->data;
	newNode->data = pos->data;
	pos->data = tmp;
#endif
	newNode = BuyNode(pos->data);
	newNode->next = pos->next;
	pos->next = newNode;
	pos->data = data;
}
void JosephCircle(pLinkList *ppl, int k)
{
	assert(ppl != NULL);
	pNode cur = *ppl;
	pNode tmp = *ppl;
	pNode del = NULL;
	//将单链表连成一个换
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = *ppl;
	//如果还有大于1个结点则继续查找
	while (cur != cur->next)
	{
		int count = k;
		//走k-1步，清除一个
		while (--count)
		{
			cur = cur->next;
		}
		//删除当前结点
		del = cur->next;
		printf("删除：%d\n", cur->data);
		cur->data = cur->next->data;
		cur->next = del->next;
		free(del);
		del = NULL;
	}
	printf("剩余：%d\n", cur->data);
}
void Reverselist(pLinkList *ppl)
{
	pNode cur = *ppl;
	pNode tmp = NULL;
	pLinkList head = NULL;
	assert(ppl != NULL);
	if (*ppl == NULL || (*ppl)->next == NULL)
	{
		return;
	}
	while (cur)
	{
		tmp = cur->next;//保存下一个结点，否则会丢失链表后边的内容
		cur->next = head;
		head = cur;
		cur = tmp;
	}
	*ppl = head;
}
void BubbleSort(pLinkList *ppl)
{
	assert(ppl != NULL);
	pNode cur = *ppl;
	pNode tail = NULL;
	while (cur != tail)//确定躺数
	{
		while (cur->next != tail) //确定比较次数
		{
			if (cur->data > cur->next->data)
			{
				DataType tmp = cur->data;
				cur->data = cur->next->data;
				cur->next->data = tmp;
			}
			cur = cur->next;
		}
		tail = cur;
		cur = *ppl;
	}
}
pNode Merge(pLinkList list1, pLinkList list2)
{
	pLinkList newhead = NULL;
	//一个链表为空，另一个不为空
	if (list1 == NULL)
	{
		return list2;
	}
	if (list2 == NULL)
	{
		return list1;
	}
	//两个链表都为空
	if ((list1 == NULL) && (list2 == NULL))
	{
		return NULL;
	}
	//无头结点的单链表，必须先插入一个结点才能将以后的结点操作统一
	if (list1->data < list2->data)
	{
		newhead = list1;
		list1 = list1->next;
	}
	else
	{
		newhead = list2;
		list2 = list2->next;
	}
	//保存链表最后一个结点的位置
	pNode tail = newhead;
	//依次比较尾插
	while ((list1 != NULL) && (list2 != NULL))
	{
		if (list1->data < list2->data)
		{
			tail->next = list1;
			list1 = list1->next;
		}
		else
		{
			tail->next = list2;
			list2 = list2->next;
		}
		tail = tail->next;
	}
	//将剩余的结点插入到新链表中
	if (list1 == NULL)
	{
		tail->next = list2;
	}
	else if (list2 == NULL)
	{
		tail->next = list1;
	}
	return newhead;
}
pNode Merge_R(pLinkList list1, pLinkList list2)
{
	pLinkList newhead = NULL;
	if (list1 == NULL)
	{
		return list2;
	}
	if (list2 == NULL)
	{
		return list1;
	}
	if ((list1 == NULL) && (list2 == NULL))
	{
		return NULL;
	}
	if (list1->data < list2->data)
	{
		newhead = list1;
		newhead->next = Merge_R(list1->next, list2);
	}
	else
	{
		newhead = list2;
		newhead->next = Merge_R(list1, list2->next);
	}
	return newhead;
}
pNode FindMidNode(pLinkList plist)
{
	pNode slow = plist;
	pNode fast = plist;
	//链表没有结点或者只有一个结点直接返回
	if ((plist == NULL) || (plist->next == NULL))
	{
		return plist;
	}
	//节点数为偶数时判断条件为fast!=NULL,此时中间节点为后面的那个;
	//为奇数时判断条件为fast->next!=NULL.
	while ((fast != NULL) && (fast->next != NULL))
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
pNode FindLastKNode(pLinkList plist, int k)
{
	pNode fast = plist;
	pNode slow = plist;
	if (plist == NULL)
	{
		return plist;
	}
	//快指针走k-1步
	while (--k)
	{
		//如果链表总的节点数小于k,则肯定不存在倒数第k个结点
		if (fast == NULL)
		{
			return NULL;
		}
		fast = fast->next;
	}
	//快慢指针一起走，快的到终点，慢指针则指向倒数第k个结点
	while (fast->next != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
//带环返回相遇点，不带环返回NULL
pNode IsCircle(pLinkList plist)
{
	pNode fast = plist;
	pNode slow = plist;
	if (plist == NULL)
		return NULL;
	while ((fast != NULL) && (fast->next != NULL))
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return fast;
		}
	}
	return NULL;
}
int GetCircleLength(pNode meet)
{
	assert(meet != NULL);
	pNode cur = meet->next;
	int len = 1;
	//len必须从1开始，否则没有算meet那个结点
	while (cur != meet)
	{
		len++;
		cur = cur->next;
	}
	return len;
}
pNode GetCircleEntryNode(pLinkList plist, pNode meet)
{
	pNode cur = plist;
	if (plist == NULL)
	{
		return NULL;
	}
	assert(meet != NULL);
	while (cur != meet)
	{
		cur = cur->next;
		meet = meet->next;
	}
	return cur;
}
int IsCross(pLinkList plist1, pLinkList plist2)
{
	pNode end1 = plist1;
	pNode end2 = plist2;
	if ((plist1 == NULL) || (plist2 == NULL))
	{
		return 0;
	}
	//确定链表一的尾结点
	while (end1->next != NULL)
	{
		end1 = end1->next;
	}
	//确定链表二的尾结点
	while (end2->next != NULL)
	{
		end2 = end2->next;
	}
	return end1 == end2;
}
pNode GetMeetNode(pLinkList plist1, pLinkList plist2)
{
	int len1 = 0;
	int len2 = 0;
	int gap = 0;
	pNode cur1 = plist1;
	pNode cur2 = plist2;
	//求链表1长度
	while (cur1)
	{
		len1++;
		cur1 = cur1->next;
	}
	//求链表2长度
	while (cur2)
	{
		len2++;
		cur2 = cur2->next;
	}
	//求差值
	gap = abs(len1 - len2);

	cur1 = plist1;//长
	cur2 = plist2;//短
	if (len1 < len2)
	{
		cur1 = plist2;
		cur2 = plist1;
	}
	//长链表走gap步
	while (gap--)
	{
		cur1 = cur1->next;
	}
	//一起走
	while (cur1!=cur2)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}
void UnionSet(pLinkList plist1, pLinkList plist2)
{
	if ((plist1 == NULL) || (plist2 == NULL))
	{
		return;
	}
	while ((plist1 != NULL) && (plist2 != NULL))
	{
		if (plist1->data < plist2->data)
		{
			plist1 = plist1->next;
		}
		else if (plist1->data > plist2->data)
		{
			plist2 = plist2->next;
		}
		else
		{
			printf("%d ", plist1->data);
			plist1 = plist1->next;
			plist2 = plist2->next;
		}
	}
}
pComplexNode BuyComplexNode(DataType d)
{
	pComplexNode newnode = (pComplexNode)malloc(sizeof(ComNode));

	if (newnode != NULL)
	{
		newnode->data = d;
		newnode->next = NULL;
		newnode->random = NULL;
	}
	return newnode;
}

void PrintComplexList(pComplexNode plist)
{
	pComplexNode cur = plist;
	while (cur)
	{
		printf("%d:", cur->data);
		if (cur->random != NULL)
		{
			printf("(%d)-->", cur->random->data);
		}
		else
		{
			printf("(NULL)-->");
		}
		cur = cur->next;
	}
	printf("over\n");
}

pComplexNode CopyComplexList(pComplexNode plist)
{
	pComplexNode cur = plist;
	pComplexNode cp = NULL;
	pComplexNode newlist = NULL;
	//①在每一个结点后边追加一个一样的结点5 5 4 4 3 3 2 2 1 1 
	while (cur != NULL)
	{
		pComplexNode tmp = cur->next;
		pComplexNode newnode = BuyComplexNode(cur->data);
		assert(newnode);
		newnode->next = tmp;
		cur->next = newnode;
		cur = tmp;
	}
	//②复制random域
	cur = plist;
	while (cur != NULL)
	{
		cp = cur->next;
		if (cur->random!=NULL)
			cp->random = cur->random->next;
		cur = cp->next;
	}
	//③拆除链表
	cur = plist;
	cp = cur->next;
	newlist = cp;
	while (cur!=NULL)
	{
		cur->next = cp->next;
		if (cur->next !=NULL)
			cp->next = cur->next->next;
		cur = cur->next;
		cp = cp->next;
	}
	return newlist;
}
/*************************************************************************/
/*双向循环带头链表*/
//创建一个双向循环链表结点
ListNode* BuyListNode(CLDataType x)
{
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	if (cur == NULL)
	{
		perror("use malloc");
	}
	cur->_data = x;
	cur->_next = NULL;
	cur->_prev = NULL;
}
//初始化双向循环带头链表
void ListInit(List* pcl)
{
	assert(pcl);
	ListNode* head = BuyListNode(0);
	pcl->_head = head;
	pcl->_head->_next = pcl->_head;
	pcl->_head->_prev = pcl->_head;
}
//销毁双向循环带头链表
void ListDestory(List* pcl)
{
	assert(pcl);
	ListNode* cur = pcl->_head;
	while (cur != pcl->_head)
	{
		ListNode* tmp = cur->_next;
		free(cur);
		cur = tmp;
	}
	free(pcl->_head);
	pcl->_head = NULL;
}
//尾插
void ListPushBack(List* pcl, CLDataType x)
{
	assert(pcl);
	//尾插和在头结点前面插入一个结点一样
	ListInsert(pcl->_head, x);
}
//头插
void ListPushFront(List* pcl, CLDataType x)
{
	assert(pcl);
	//头插和在第一个结点前面插入一样
	ListInsert(pcl->_head->_next, x);
}
//指定位置前面插入结点 
void ListInsert(ListNode* pos, CLDataType x)
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	//保存前面结点(建议这么写，如果直接用指针完会太绕了)
	ListNode* prev = pos->_prev;
	//prev newnode pos指针连接起来
	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}
//尾删
void ListPopBack(List* pcl)
{
	assert(pcl);
	//尾删和在删除指定最后一个结点一样
	ListErase(pcl, pcl->_head->_prev);
}
//头删
void ListPopFront(List* pcl)
{
	assert(pcl);
	//头删和删除指定第一个结点一样
	ListErase(pcl, pcl->_head->_next);
}
//指定位置删除结点
void ListErase(List* pcl, ListNode* pos)
{
	assert(pos);
	//删除的结点不能是头结点
	assert(pos != pcl->_head);
	//保存pos前面结点
	ListNode* prev = pos->_prev;
	//保存pos后面结点
	ListNode* next = pos->_next;
	//prev pos next(pos为删除结点) 
	prev->_next = next;
	next->_prev = prev;
	free(pos);
	pos = NULL;
}
//遍历打印链表
void ListPrint(List* pcl)
{
	assert(pcl);
	ListNode* cur = pcl->_head->_next;
	//从头结点的下一个结点开始遍历
	while (cur != pcl->_head)
	{
		printf("%d-->", cur->_data);
		cur = cur->_next;
	}
	printf("over\n");
}
//链表的长度
int ListSize(List* pcl)
{
	assert(pcl);
	ListNode* cur = pcl->_head->_next;
	int count = 0;
	//遍历一遍链表(不算头结点)
	while (cur != pcl->_head)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}
//判断链表是否为空(为空返回0，非空返回1)
int ListEmpty(List* pcl)
{
	assert(pcl);
	//prev和next如果都指向自己，则链表为空
	return ((pcl->_head->_next == pcl->_head) && (pcl->_head->_prev == pcl->_head)) ? 0 : 1;
}
//寻找指定数据的结点(找到返回地址，找不到返回NULL)
ListNode* FindListNode(List* pcl, CLDataType x)
{
	assert(pcl);
	ListNode* cur = pcl->_head->_next;
	//遍历链表找到相同数据返回地址，找不到则返NULL
	while (cur != pcl->_head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}