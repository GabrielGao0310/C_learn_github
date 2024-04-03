#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void menu()
{
	printf("******************************\n");
	printf("**********  1:play   *********\n");
	printf("**********  0:exit   *********\n");
	printf("******************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//初始化雷的遍布信息，全0表示无雷
	char show[ROWS][COLS] = { 0 };//初始化排查出来雷的信息（邻域个数），初始化全为“*”保持神秘

	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//埋雷
	SetMine(mine, ROW, COL);

	//DisplayBoard(mine, ROW, COL);//只打印中间9*9,	且游戏中不打印mine
	DisplayBoard(show, ROW, COL);

	//找雷
	FindMine(mine, show, ROW, COL);

}


int main()

{
	//设置随机数生成起点
	srand((unsigned int)time(NULL));
	int input = 0;

	do {
		menu();
		printf("请输入:>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			printf("扫雷，启动\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}

	} while (input);

	return 0;
}