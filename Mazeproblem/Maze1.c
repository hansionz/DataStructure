#include "Maze.h"
//��ʼ��ջ
void InitMazeStack(pMazeStack sm)
{
	sm->top = -1;
}
//��ջ��������ջԪ�ر���
void  PushStack(pMazeStack sm, SElemType data)
{
	if (sm->top == MAXSIZE - 1)
	{
		printf("��ջ������������ջ\n");
	}
	else
	{
		sm->top++;
		sm->data[sm->top] = data;
	}
}
//��ջ
void PopStack(pMazeStack sm, SElemType *tmp)
{
	if (sm->top == -1)
	{
		printf("ջ�գ����ܳ�ջ\n");
	}
	else
	{
		*tmp = sm->data[sm->top];
		sm->top--;
	}
}
//�ж�ջ�Ƿ�Ϊ�գ�Ϊ�շ���1���ǿշ���0
int EmptyStack(pMazeStack sm)
{
	return sm->top == -1;
}
//�߹��ĵط�����ǡ�$��
void FootPrint(PosType curpos, char maze[MAZEROW][MAZECOL])
{
	maze[curpos.x][curpos.y] = '$';
}
//�߲�ͨ�ĵط�����ǡ�@��
void MarkPrint(PosType curpos, char maze[MAZEROW][MAZECOL])
{
	maze[curpos.x][curpos.y] = '@';
}
//����һ��λ����Ϊ��ǰλ�ã�˳ʱ�뿪ʼ
PosType NextPos(PosType curpos, int dir)
{
	switch (dir)
	{
	case 1:
		//��1���������кŲ��䣬�кż�1
		curpos.y++;
		break;
	case 2:
		//��2�������ϣ��кż�1���кŲ���
		curpos.x++;
		break;
	case 3:
		//��3�����������кŲ��䣬�кż�1
		curpos.y--;
		break;
	case 4:
		//��4���������кż�1���кŲ���
		curpos.x--;
		break;
	default:
		printf("��������!\n");
		break;
	}
	return curpos;
}
//�жϵ�ǰλ���Ƿ����ͨ������Ϊ��0������ͨ����('$'�����Ѿ��߹�����@����������ͬ)
//����1����ͨ��������0����ͨ��
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
//��һ������ڵ����ڵ�·��
int MazePath(char maze[MAZEROW][MAZECOL], PosType start, PosType end)
{
	MazeStack sm;
	InitMazeStack(&sm);
	//�����������Ϊ��ǰλ��
	PosType curpos = start;
	do
	{
		//�����ǰλ�ÿ���
		if (IsPass(curpos, maze))
		{
			FootPrint(curpos, maze);//��һ���Ѿ��߹��ı��
			SElemType data;
			data.seat = curpos;
			data.dir = 1;
			PushStack(&sm, data);//����ǰλ�ü���·������ջ
			//�����ǰλ���ǳ��ڣ������
			if (curpos.x == end.x&&curpos.y == end.y)
			{
				return 1;
			}
			//�����л���ǰλ�õĶ���Ϊ��һ��λ��
			curpos = NextPos(curpos, 1);
		}
		else//��ǰλ�ò���ͨ��
		{
			//ջ��Ϊ�գ�����·���ɲ�
			if (!EmptyStack(&sm))
			{
				SElemType data;
				PopStack(&sm, &data);//��ջһ�Σ���������
				//�жϳ�ջλ�õ������Ƿ�ȫ��̽����������Ϊ����ͬ�ڳ�ջһ��
				while (data.dir == 4 && !EmptyStack(&sm))
				{
					MarkPrint(data.seat, maze);
					PopStack(&sm, &data);
				}
				//��һ�γ�ջ��λ�ñ�Ȼ����������û��̽��
				//����һ����̽��
				if (data.dir < 4)
				{
					data.dir++;
					PushStack(&sm, data);//����ǰλ����ջ��Ϊ·��
					curpos = NextPos(data.seat, data.dir);//�л���ǰλ��Ϊ�÷����ϵĶ���λ��
				}
			}
		}
		printf("<--------------------------------------------------------->\n");
		printf("��ʼ̽���Թ���('$'����·����'@'����̽�������ǲ�ͨ�ĵط�)\n");
		printf("<--------------------------------------------------------->\n");
		PrintMaze(maze);
		Sleep(1000);//˯��1000����
		system("cls");//����
	} while (!EmptyStack(&sm));//ջ��Ϊ�գ�һֱ����λ��̽��
	return 0;
}
//������ά���飬��ӡ�Թ���ǰ��״̬
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
//��ӡ·��
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
//��ӡͨ·����
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