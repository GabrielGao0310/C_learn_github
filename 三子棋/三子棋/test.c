#define _CRT_SECURE_NO_WARNINGS



#include "game.h"

void menu()
{

	printf("*************************************\n");
	printf("***********1.game 0.exit*************\n");
	printf("*************************************\n");
}


void game()
{
	char board[ROW][COL] = { 0 };
	char ret = 0;
	//初始化
	InitBoard(board,ROW,COL);
	DisplayBoard(board, ROW, COL);
	//下棋
	while (1)
	{

		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢	
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}


}


int main()
{
	srand((unsigned int)time(NULL));//设置时间戳，获取随机数的起点
	
	int input = 0;
	do {
		menu();//打印菜单
		printf("请选择：");
		scanf("%d", &input);
		
		switch (input)
		{
		case 1:
			printf("三子棋,三子相连即为胜利\n");
			game();
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("输入错误\n");
			break;

		}

	}while(input);
	return 0;
}