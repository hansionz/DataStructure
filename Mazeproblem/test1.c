#include "Maze.h"
//�˵�
void menu()
{
	printf("****************************************************\n");
	printf("**************�ﻶӭ�����Թ�̽����******************\n");
	printf("****************  ��0.�˳�̽��  ********************\n");
	printf("****************  ��1.�Թ���ͼ  ********************\n");
	printf("****************  ��2.�Թ�̽��  ********************\n");
	printf("****************************************************\n");
}
//̽��·��
void Exploration(char maze[MAZEROW][MAZECOL], PosType start, PosType end)
{
	printf("�Թ���ͼ��\n");
	PrintMaze(maze);//��ӡ�Թ���̬
	Sleep(2000);
	system("cls");
	if (MazePath(maze,start, end))
	{
		printf("<--------------------------------------------------------->\n");
		printf("̽���ɹ�!\n");
		printf("<--------------------------------------------------------->\n");
		printf("�Թ�����̬(����ͨ·��$�����Ѿ�̽������λ��'@')��\n");
		PrintMaze(maze);//��ӡ�Թ���ǰ״̬
		printf("̽�����Թ���һ��ͨ·��\n");
		PrintPath(maze);//��ӡ�Թ���һ��ͨ·
		printf("�Թ�ͨ·���꣺\n");
		PrintSeat(maze);//��ӡͨ·����
	}
	else
	{
		printf("���Թ�������ͨ·!\n");
		PrintMaze(maze);
	}
}
int main()
{
	int input = 0;
	PosType start = { 0, 0 };//�������
	PosType end = { 0, 0 };//��������
	do
	{
		//��ά���������Թ���ͼ('#'����ǽ��'0'����·)
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
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
				  int count = 3;
				  fflush(stdin);//ˢ�»�����
				  printf("��ͼ��ȡ��");
				  while (count--)
				  {
					  Sleep(500);
					  printf(".");
				  }
				  printf("\n");
				  printf("�Թ���ͼ��\n");
				  PrintMaze(maze);
		}
			break;
		case 2:
			fflush(stdin);//ˢ�»�����
			printf("�������������((1,1)-(8,8)):");
			scanf("%d,%d", &start.x, &start.y);
			printf("�������������((1,1)-(8,8)):");
			scanf("%d,%d", &end.x, &end.y);
			Exploration(maze, start, end);
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("�����������������룺\n");
			break;
		}
	} while (input);
	return 0;
}