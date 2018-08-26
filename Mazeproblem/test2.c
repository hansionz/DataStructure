#include"Maze.h"

int maze[N][N];
int stacksize;
int pathsize;

void TestMazeProblem()
{
	Pos entry, exit;
	entry._row = 5;
	entry._col = 2;
	exit._row = 4;
	exit._col = 5;
	PrintMaze(maze);
	GetMazePath_C(entry);
	printf("最短路径为%d\n", stacksize);

	/*if (0 == GetMazePath_E(entry,exit))
	{
		printf("没有通路\n");
	}
	else
	{
		printf("有通路\n");
	}*/
	PrintMaze(maze);
}
int main()
{
	TestMazeProblem();
	return 0;
}