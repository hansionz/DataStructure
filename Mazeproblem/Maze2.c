#include"Maze.h"
//��¼��Сֵ
int stacksize = 0;
int pathsize = 0;
//�Թ���ͼ
int maze[N][N] =
{
	{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 1 },
	{ 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 1, 1, 1, 1 },
	{ 0, 0, 1, 0, 0, 0 },
};
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

	ps->_top--;
}
//ȡջ��
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
//ջ�Ĵ�С
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}
//ͨ·���ڻ�����һ�ֱ�Ƿ�ʽ��ҲҪ��һ�ּ���Ƿ��ͨ�ķ�ʽ
int CheckAccess(Pos cur, Pos next)
{
	//���겻��Խ��
	//����Ϊ1(·)����ͨ��
	//��һ����ı�Ǳ�����ڵ�ǰ�����Ǽ�1����ͨ��
	if ((next._row >= 0) && (next._row < N) && (next._col >= 0) &&(next._row < N) 
		&& ((maze[next._row][next._col] == 1) 
		||(maze[next._row][next._col]  > maze[cur._row][cur._col] + 1)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//����һ���յ㣬ȷ����һ������Ƿ��ͨ
int CheckAccess_E(Pos cur)
{
	//�������û��Խ�磬���ҵ�ǰ����Ϊ��1��(����·)�ſ���ͨ��
	//����ͨ������1��������ͨ������0
	if ((cur._row >= 0) && (cur._row < N) && (cur._col >= 0) && 
		(cur._row < N) && (maze[cur._row][cur._col] == 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//ͨ·֮�����
void GetMazePath_C(Pos entry)
{
	Stack s;
	Pos next;
	StackInit(&s);
	StackPush(&s, entry);
	//����ڱ��Ϊ2
	maze[entry._row][entry._col] = 2;
	while (StackEmpty(&s))
	{
		Pos cur = StackTop(&s);
		//ȷ�����·��
		if (cur._col == N-1)
		{
			if ((StackSize(&s) < stacksize) || (stacksize == 0))
			{
				stacksize = StackSize(&s);
			}
		}
		//�ң��л���ǰλ��
		next = cur;
		next._col += 1;
		if (CheckAccess(cur, next))
		{
			//��һ��λ�õı��ֵΪ��һ��λ�õı��ֵ��1
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&s, next);
			continue;
		}
		//��
		next = cur;
		next._col -= 1;
		if (CheckAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&s, next);
			continue;
		}
		//��
		next = cur;
		next._row += 1;
		if (CheckAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&s, next);
			continue;
		}
		//��
	    next = cur;
		next._row -= 1;
		if (CheckAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&s, next);
			continue;
		}
		//��ǰ���겻ͨ������ݳ�ջ
		StackPop(&s);
	}
}
//һ����ڣ�������ڣ���һ�����ͨ·
void GetMazePath_M(Pos entry)
{
	Stack s;
	Pos next;
	StackInit(&s);
	//�Ƚ��������ѹջ
	StackPush(&s, entry);
	//ջ��Ϊ��˵����������û�л����꣬��������
	while (StackEmpty(&s))
	{
		Pos cur = StackTop(&s);
		//��ǵ�ǰλ��Ϊ�Ѿ��߹�������
		maze[cur._row][cur._col] = 2;
		//���ڶ����е�5�����ϣ���ǰλ���ڳ����ϣ���ֹͣ���򣬼�����������һ��·��
		if (cur._col == N - 1)
		{
			//�����ǰ·������С��ȫ�ֱ���������£����ȫ�ֱ���Ϊ0����ֱ�Ӹ�ֵ
			if ((StackSize(&s) < pathsize) || (pathsize == 0))
			{
				pathsize = StackSize(&s);
			}
		}
		//�ң��л�����λ��
		next = cur;
		next._col += 1;
		if (CheckAccess_E(next))
		{
			StackPush(&s, next);
			continue;
		}
		//��
		next = cur;
		next._col -= 1;
		if (CheckAccess_E(next))
		{
			StackPush(&s, next);
			continue;
		}
		//��
		next = cur;
		next._row += 1;
		if (CheckAccess_E(next))
		{
			StackPush(&s, next);
			continue;
		}
		//��
		next = cur;
		next._row -= 1;
		if (CheckAccess_E(next))
		{
			StackPush(&s, next);
			continue;
		}
		//��ǰ���겻ͨ�����ջ����,����һ����㵱����ǰλ�ü���̽��
		StackPop(&s);
	}
}
//һ����ڣ�һ�����ڣ���һ��ͨ·(����1��ͨ·������0û��ͨ·)
int GetMazePath_E(Pos entry, Pos exit)
{
	Stack s;
	Pos next;
	StackInit(&s);
	//�Ƚ��������ѹջ
	StackPush(&s, entry);
	//ջ��Ϊ��˵����������û�л����꣬��������
	while (StackEmpty(&s))
	{
		Pos cur = StackTop(&s);
		//��ǵ�ǰλ��Ϊ�Ѿ��߹�������
		maze[cur._row][cur._col] = 2;
		if ((cur._row == exit._row) && (cur._col == exit._col))
		{
			StackDestroy(&s);
			return 1;
		}
		//�ң��л�����λ��
		next = cur;
		next._col += 1;
		if (CheckAccess_E(next))
		{
			StackPush(&s, next);
			continue;
		}
		//��
		next = cur;
		next._col -= 1;
		if (CheckAccess_E(next))
		{
			StackPush(&s, next);
			continue;
		}
		//��
		next = cur;
		next._row += 1;
		if (CheckAccess_E(next))
		{
			StackPush(&s, next);
			continue;
		}
		//��
		next = cur;
		next._row -= 1;
		if (CheckAccess_E(next))
		{
			StackPush(&s, next);
			continue;
		}
		//��ǰ���겻ͨ�����ջ����,����һ����㵱����ǰλ�ü���̽��
		StackPop(&s);
	}
	return 0;
}
//�ݹ�汾
int GetMazePath_R(Pos entry)
{
	maze[entry._row][entry._col] = 2;
	if (entry._col == N - 1)
	{
		return 1;
	}
	Pos next = entry;

	next._col += 1;
	if (CheckAccess_R(next))
	{
		if (GetMazePath_R(next))
		{
			return 1;
		}
	}
	//��
	next = entry;
	next._col -= 1;
	if (CheckAccess_R(next))
	{
		if (GetMazePath_R(next))
		{
			return 1;
		}
	}
	//��
	next = entry;
	next._row += 1;
	if (CheckAccess_R(next))
	{
		if (GetMazePath_R(next))
		{
			return 1;
		}
	}
	//��
	next = entry;
	next._row -= 1;
	if (CheckAccess_R(next))
	{
		if (GetMazePath_R(next))
		{
			return 1;
		}
	}
	return 0;
}
//��ӡ�Թ�
void PrintMaze(int maze[N][N])
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
}

