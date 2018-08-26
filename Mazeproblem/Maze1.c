#include "Maze.h"
//初始化栈
void InitMazeStack(pMazeStack sm)
{
	sm->top = -1;
}
//出栈，并将出栈元素保存
void  PushStack(pMazeStack sm, SElemType data)
{
	if (sm->top == MAXSIZE - 1)
	{
		printf("此栈已满，不能入栈\n");
	}
	else
	{
		sm->top++;
		sm->data[sm->top] = data;
	}
}
//出栈
void PopStack(pMazeStack sm, SElemType *tmp)
{
	if (sm->top == -1)
	{
		printf("栈空，不能出栈\n");
	}
	else
	{
		*tmp = sm->data[sm->top];
		sm->top--;
	}
}
//判断栈是否为空，为空返回1，非空返回0
int EmptyStack(pMazeStack sm)
{
	return sm->top == -1;
}
//走过的地方做标记‘$’
void FootPrint(PosType curpos, char maze[MAZEROW][MAZECOL])
{
	maze[curpos.x][curpos.y] = '$';
}
//走不通的地方做标记‘@’
void MarkPrint(PosType curpos, char maze[MAZEROW][MAZECOL])
{
	maze[curpos.x][curpos.y] = '@';
}
//找下一个位置作为当前位置，顺时针开始
PosType NextPos(PosType curpos, int dir)
{
	switch (dir)
	{
	case 1:
		//‘1’代表东，行号不变，列号加1
		curpos.y++;
		break;
	case 2:
		//‘2’代表南，行号加1，列号不变
		curpos.x++;
		break;
	case 3:
		//‘3’代表西，行号不变，列号减1
		curpos.y--;
		break;
	case 4:
		//‘4’代表北，行号减1，列号不变
		curpos.x--;
		break;
	default:
		printf("参数有误!\n");
		break;
	}
	return curpos;
}
//判断当前位置是否可以通过，既为‘0’可以通过。('$'代表已经走过、‘@’代表死胡同)
//返回1可以通过，返回0不能通过
int IsPass(PosType curpos, char maze[MAZEROW][MAZECOL])
{
	if (maze[curpos.x][curpos.y] == '0')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//求一条从入口到出口的路径
int MazePath(char maze[MAZEROW][MAZECOL], PosType start, PosType end)
{
	MazeStack sm;
	InitMazeStack(&sm);
	//设置入口坐标为当前位置
	PosType curpos = start;
	do
	{
		//如果当前位置可走
		if (IsPass(curpos, maze))
		{
			FootPrint(curpos, maze);//做一个已经走过的标记
			SElemType data;
			data.seat = curpos;
			data.dir = 1;
			PushStack(&sm, data);//将当前位置加入路径，入栈
			//如果当前位置是出口，则结束
			if (curpos.x == end.x&&curpos.y == end.y)
			{
				return 1;
			}
			//否则切换当前位置的东边为下一个位置
			curpos = NextPos(curpos, 1);
		}
		else//当前位置不能通过
		{
			//栈不为空，还有路径可查
			if (!EmptyStack(&sm))
			{
				SElemType data;
				PopStack(&sm, &data);//出栈一次，保留数据
				//判断出栈位置的四面是否全被探索，是则标记为死胡同在出栈一次
				while (data.dir == 4 && !EmptyStack(&sm))
				{
					MarkPrint(data.seat, maze);
					PopStack(&sm, &data);
				}
				//上一次出栈的位置必然是其他方向没有探索
				//换下一方向探索
				if (data.dir < 4)
				{
					data.dir++;
					PushStack(&sm, data);//将当前位置入栈纳为路径
					curpos = NextPos(data.seat, data.dir);//切换当前位置为该方向上的东邻位置
				}
			}
		}
		printf("<--------------------------------------------------------->\n");
		printf("开始探索迷宫：('$'代表路径，'@'代表探索过但是不通的地方)\n");
		printf("<--------------------------------------------------------->\n");
		PrintMaze(maze);
		Sleep(1000);//睡眠1000毫秒
		system("cls");//清屏
	} while (!EmptyStack(&sm));//栈不为空，一直存在位置探索
	return 0;
}
//遍历二维数组，打印迷宫当前的状态
void PrintMaze(char maze[MAZEROW][MAZECOL])
{
	int i = 0;
	for (i = 0; i < MAZEROW; i++)
	{
		int j = 0;
		for (j = 0; j < MAZECOL; j++)
		{
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
//打印路径
void PrintPath(char maze[MAZEROW][MAZECOL])
{
	int i = 0;
	for (i = 0; i < MAZEROW; i++)
	{
		int j = 0;
		for (j = 0; j < MAZECOL; j++)
		{
			if (i == 0 || j == 0 || i == MAZEROW - 1 || j == MAZECOL - 1 || maze[i][j] == '$')
			{
				printf("%c ", maze[i][j]);
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	printf("\n");
}
//打印通路坐标
void PrintSeat(char maze[MAZEROW][MAZECOL])
{
	int i = 0;
	printf("<--------------------------------------------------------->\n");
	for (i = 0; i < MAZEROW; i++)
	{
		int j = 0;
		for (j = 0; j < MAZECOL; j++)
		{
			if (maze[i][j] == '$')
			{
				printf("(%d,%d)-->", i, j);
			}
		}
	}
	printf("over\n");
	printf("<--------------------------------------------------------->\n");
}