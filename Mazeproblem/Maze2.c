#include"Maze.h"
//记录最小值
int stacksize = 0;
int pathsize = 0;
//迷宫地图
int maze[N][N] =
{
	{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 1 },
	{ 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 1, 1, 1, 1 },
	{ 0, 0, 1, 0, 0, 0 },
};
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

	ps->_top--;
}
//取栈顶
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
//栈的大小
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}
//通路存在环，换一种标记方式，也要换一种检查是否可通的方式
int CheckAccess(Pos cur, Pos next)
{
	//坐标不能越界
	//必须为1(路)才能通过
	//下一坐标的标记必须大于当前坐标标记加1才能通过
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
//给定一个终点，确定下一个结点是否可通
int CheckAccess_E(Pos cur)
{
	//如果坐标没有越界，并且当前坐标为‘1’(代表路)才可以通过
	//可以通过返回1，不可以通过返回0
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
//通路之间带环
void GetMazePath_C(Pos entry)
{
	Stack s;
	Pos next;
	StackInit(&s);
	StackPush(&s, entry);
	//从入口标记为2
	maze[entry._row][entry._col] = 2;
	while (StackEmpty(&s))
	{
		Pos cur = StackTop(&s);
		//确定最短路径
		if (cur._col == N-1)
		{
			if ((StackSize(&s) < stacksize) || (stacksize == 0))
			{
				stacksize = StackSize(&s);
			}
		}
		//右，切换当前位置
		next = cur;
		next._col += 1;
		if (CheckAccess(cur, next))
		{
			//下一个位置的标记值为上一个位置的标记值加1
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&s, next);
			continue;
		}
		//左
		next = cur;
		next._col -= 1;
		if (CheckAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&s, next);
			continue;
		}
		//下
		next = cur;
		next._row += 1;
		if (CheckAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&s, next);
			continue;
		}
		//上
	    next = cur;
		next._row -= 1;
		if (CheckAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&s, next);
			continue;
		}
		//当前坐标不通，则回溯出栈
		StackPop(&s);
	}
}
//一个入口，多个出口，求一条最短通路
void GetMazePath_M(Pos entry)
{
	Stack s;
	Pos next;
	StackInit(&s);
	//先将入口坐标压栈
	StackPush(&s, entry);
	//栈不为空说明还有坐标没有回溯完，继续回溯
	while (StackEmpty(&s))
	{
		Pos cur = StackTop(&s);
		//标记当前位置为已经走过的坐标
		maze[cur._row][cur._col] = 2;
		//出口都在列等5那列上，当前位置在出口上，不停止程序，继续回溯找下一条路径
		if (cur._col == N - 1)
		{
			//如果当前路径长度小于全局变量，则更新；如果全局变量为0，则直接赋值
			if ((StackSize(&s) < pathsize) || (pathsize == 0))
			{
				pathsize = StackSize(&s);
			}
		}
		//右，切换坐标位置
		next = cur;
		next._col += 1;
		if (CheckAccess_E(next))
		{
			StackPush(&s, next);
			continue;
		}
		//左
		next = cur;
		next._col -= 1;
		if (CheckAccess_E(next))
		{
			StackPush(&s, next);
			continue;
		}
		//下
		next = cur;
		next._row += 1;
		if (CheckAccess_E(next))
		{
			StackPush(&s, next);
			continue;
		}
		//上
		next = cur;
		next._row -= 1;
		if (CheckAccess_E(next))
		{
			StackPush(&s, next);
			continue;
		}
		//当前坐标不通，则出栈回溯,把上一个结点当做当前位置继续探索
		StackPop(&s);
	}
}
//一个入口，一个出口，求一条通路(返回1有通路，返回0没有通路)
int GetMazePath_E(Pos entry, Pos exit)
{
	Stack s;
	Pos next;
	StackInit(&s);
	//先将入口坐标压栈
	StackPush(&s, entry);
	//栈不为空说明还有坐标没有回溯完，继续回溯
	while (StackEmpty(&s))
	{
		Pos cur = StackTop(&s);
		//标记当前位置为已经走过的坐标
		maze[cur._row][cur._col] = 2;
		if ((cur._row == exit._row) && (cur._col == exit._col))
		{
			StackDestroy(&s);
			return 1;
		}
		//右，切换坐标位置
		next = cur;
		next._col += 1;
		if (CheckAccess_E(next))
		{
			StackPush(&s, next);
			continue;
		}
		//左
		next = cur;
		next._col -= 1;
		if (CheckAccess_E(next))
		{
			StackPush(&s, next);
			continue;
		}
		//下
		next = cur;
		next._row += 1;
		if (CheckAccess_E(next))
		{
			StackPush(&s, next);
			continue;
		}
		//上
		next = cur;
		next._row -= 1;
		if (CheckAccess_E(next))
		{
			StackPush(&s, next);
			continue;
		}
		//当前坐标不通，则出栈回溯,把上一个结点当做当前位置继续探索
		StackPop(&s);
	}
	return 0;
}
//递归版本
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
	//左
	next = entry;
	next._col -= 1;
	if (CheckAccess_R(next))
	{
		if (GetMazePath_R(next))
		{
			return 1;
		}
	}
	//下
	next = entry;
	next._row += 1;
	if (CheckAccess_R(next))
	{
		if (GetMazePath_R(next))
		{
			return 1;
		}
	}
	//上
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
//打印迷宫
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

