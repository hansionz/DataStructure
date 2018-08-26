#include "Maze.h"
//菜单
void menu()
{
	printf("****************************************************\n");
	printf("**************★欢迎来到迷宫探索★******************\n");
	printf("****************  ●0.退出探索  ********************\n");
	printf("****************  ●1.迷宫地图  ********************\n");
	printf("****************  ●2.迷宫探索  ********************\n");
	printf("****************************************************\n");
}
//探索路径
void Exploration(char maze[MAZEROW][MAZECOL], PosType start, PosType end)
{
	printf("迷宫地图：\n");
	PrintMaze(maze);//打印迷宫初态
	Sleep(2000);
	system("cls");
	if (MazePath(maze,start, end))
	{
		printf("<--------------------------------------------------------->\n");
		printf("探索成功!\n");
		printf("<--------------------------------------------------------->\n");
		printf("迷宫的现态(包括通路‘$’和已经探索过的位置'@')：\n");
		PrintMaze(maze);//打印迷宫当前状态
		printf("探索到迷宫的一条通路：\n");
		PrintPath(maze);//打印迷宫的一条通路
		printf("迷宫通路坐标：\n");
		PrintSeat(maze);//打印通路坐标
	}
	else
	{
		printf("此迷宫不存在通路!\n");
		PrintMaze(maze);
	}
}
int main()
{
	int input = 0;
	PosType start = { 0, 0 };//入口坐标
	PosType end = { 0, 0 };//出口坐标
	do
	{
		//二维数组设置迷宫地图('#'代表墙，'0'代表路)
		char maze[MAZEROW][MAZECOL] = {
			{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
			{ '#', '0', '0', '#', '0', '0', '0', '#', '0', '#' },
			{ '#', '0', '0', '#', '0', '0', '0', '#', '0', '#' },
			{ '#', '0', '0', '0', '0', '#', '#', '0', '0', '#' },
			{ '#', '0', '#', '#', '#', '0', '0', '0', '0', '#' },
			{ '#', '0', '0', '0', '#', '0', '0', '0', '0', '#' },
			{ '#', '0', '#', '0', '0', '0', '#', '0', '0', '#' },
			{ '#', '0', '#', '#', '#', '0', '#', '#', '0', '#' },
			{ '#', '#', '0', '0', '0', '0', '0', '0', '0', '#' },
			{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' } };
		menu();
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
				  int count = 3;
				  fflush(stdin);//刷新缓冲区
				  printf("地图读取中");
				  while (count--)
				  {
					  Sleep(500);
					  printf(".");
				  }
				  printf("\n");
				  printf("迷宫地图：\n");
				  PrintMaze(maze);
		}
			break;
		case 2:
			fflush(stdin);//刷新缓冲区
			printf("请输入入口坐标((1,1)-(8,8)):");
			scanf("%d,%d", &start.x, &start.y);
			printf("请输入出口坐标((1,1)-(8,8)):");
			scanf("%d,%d", &end.x, &end.y);
			Exploration(maze, start, end);
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("输入有误，请重新输入：\n");
			break;
		}
	} while (input);
	return 0;
}