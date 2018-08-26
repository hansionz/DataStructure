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
	if (*ppl == NULL)//������ֱ�Ӳ���
	{
		(*ppl)= newNode;
	}
	else//�ǿ��������ҵ����һ���ڵ��ڲ���
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
	s->top = 0;//��ʼ��ջ
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
		//ǰ��
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
	//������������һ����
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = *ppl;
	//������д���1��������������
	while (cur != cur->next)
	{
		int count = k;
		//��k-1�������һ��
		while (--count)
		{
			cur = cur->next;
		}
		//ɾ����ǰ���
		del = cur->next;
		printf("ɾ����%d\n", cur->data);
		cur->data = cur->next->data;
		cur->next = del->next;
		free(del);
		del = NULL;
	}
	printf("ʣ�ࣺ%d\n", cur->data);
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
		tmp = cur->next;//������һ����㣬����ᶪʧ�����ߵ�����
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
	while (cur != tail)//ȷ������
	{
		while (cur->next != tail) //ȷ���Ƚϴ���
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
	//һ������Ϊ�գ���һ����Ϊ��
	if (list1 == NULL)
	{
		return list2;
	}
	if (list2 == NULL)
	{
		return list1;
	}
	//��������Ϊ��
	if ((list1 == NULL) && (list2 == NULL))
	{
		return NULL;
	}
	//��ͷ���ĵ����������Ȳ���һ�������ܽ��Ժ�Ľ�����ͳһ
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
	//�����������һ������λ��
	pNode tail = newhead;
	//���αȽ�β��
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
	//��ʣ��Ľ����뵽��������
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
	//����û�н�����ֻ��һ�����ֱ�ӷ���
	if ((plist == NULL) || (plist->next == NULL))
	{
		return plist;
	}
	//�ڵ���Ϊż��ʱ�ж�����Ϊfast!=NULL,��ʱ�м�ڵ�Ϊ������Ǹ�;
	//Ϊ����ʱ�ж�����Ϊfast->next!=NULL.
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
	//��ָ����k-1��
	while (--k)
	{
		//��������ܵĽڵ���С��k,��϶������ڵ�����k�����
		if (fast == NULL)
		{
			return NULL;
		}
		fast = fast->next;
	}
	//����ָ��һ���ߣ���ĵ��յ㣬��ָ����ָ������k�����
	while (fast->next != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
//�������������㣬����������NULL
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
	//len�����1��ʼ������û����meet�Ǹ����
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
	//ȷ������һ��β���
	while (end1->next != NULL)
	{
		end1 = end1->next;
	}
	//ȷ���������β���
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
	//������1����
	while (cur1)
	{
		len1++;
		cur1 = cur1->next;
	}
	//������2����
	while (cur2)
	{
		len2++;
		cur2 = cur2->next;
	}
	//���ֵ
	gap = abs(len1 - len2);

	cur1 = plist1;//��
	cur2 = plist2;//��
	if (len1 < len2)
	{
		cur1 = plist2;
		cur2 = plist1;
	}
	//��������gap��
	while (gap--)
	{
		cur1 = cur1->next;
	}
	//һ����
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
	//����ÿһ�������׷��һ��һ���Ľ��5 5 4 4 3 3 2 2 1 1 
	while (cur != NULL)
	{
		pComplexNode tmp = cur->next;
		pComplexNode newnode = BuyComplexNode(cur->data);
		assert(newnode);
		newnode->next = tmp;
		cur->next = newnode;
		cur = tmp;
	}
	//�ڸ���random��
	cur = plist;
	while (cur != NULL)
	{
		cp = cur->next;
		if (cur->random!=NULL)
			cp->random = cur->random->next;
		cur = cp->next;
	}
	//�۲������
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
/*˫��ѭ����ͷ����*/
//����һ��˫��ѭ��������
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
//��ʼ��˫��ѭ����ͷ����
void ListInit(List* pcl)
{
	assert(pcl);
	ListNode* head = BuyListNode(0);
	pcl->_head = head;
	pcl->_head->_next = pcl->_head;
	pcl->_head->_prev = pcl->_head;
}
//����˫��ѭ����ͷ����
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
//β��
void ListPushBack(List* pcl, CLDataType x)
{
	assert(pcl);
	//β�����ͷ���ǰ�����һ�����һ��
	ListInsert(pcl->_head, x);
}
//ͷ��
void ListPushFront(List* pcl, CLDataType x)
{
	assert(pcl);
	//ͷ����ڵ�һ�����ǰ�����һ��
	ListInsert(pcl->_head->_next, x);
}
//ָ��λ��ǰ������� 
void ListInsert(ListNode* pos, CLDataType x)
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	//����ǰ����(������ôд�����ֱ����ָ�����̫����)
	ListNode* prev = pos->_prev;
	//prev newnode posָ����������
	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}
//βɾ
void ListPopBack(List* pcl)
{
	assert(pcl);
	//βɾ����ɾ��ָ�����һ�����һ��
	ListErase(pcl, pcl->_head->_prev);
}
//ͷɾ
void ListPopFront(List* pcl)
{
	assert(pcl);
	//ͷɾ��ɾ��ָ����һ�����һ��
	ListErase(pcl, pcl->_head->_next);
}
//ָ��λ��ɾ�����
void ListErase(List* pcl, ListNode* pos)
{
	assert(pos);
	//ɾ���Ľ�㲻����ͷ���
	assert(pos != pcl->_head);
	//����posǰ����
	ListNode* prev = pos->_prev;
	//����pos������
	ListNode* next = pos->_next;
	//prev pos next(posΪɾ�����) 
	prev->_next = next;
	next->_prev = prev;
	free(pos);
	pos = NULL;
}
//������ӡ����
void ListPrint(List* pcl)
{
	assert(pcl);
	ListNode* cur = pcl->_head->_next;
	//��ͷ������һ����㿪ʼ����
	while (cur != pcl->_head)
	{
		printf("%d-->", cur->_data);
		cur = cur->_next;
	}
	printf("over\n");
}
//����ĳ���
int ListSize(List* pcl)
{
	assert(pcl);
	ListNode* cur = pcl->_head->_next;
	int count = 0;
	//����һ������(����ͷ���)
	while (cur != pcl->_head)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}
//�ж������Ƿ�Ϊ��(Ϊ�շ���0���ǿշ���1)
int ListEmpty(List* pcl)
{
	assert(pcl);
	//prev��next�����ָ���Լ���������Ϊ��
	return ((pcl->_head->_next == pcl->_head) && (pcl->_head->_prev == pcl->_head)) ? 0 : 1;
}
//Ѱ��ָ�����ݵĽ��(�ҵ����ص�ַ���Ҳ�������NULL)
ListNode* FindListNode(List* pcl, CLDataType x)
{
	assert(pcl);
	ListNode* cur = pcl->_head->_next;
	//���������ҵ���ͬ���ݷ��ص�ַ���Ҳ�����NULL
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