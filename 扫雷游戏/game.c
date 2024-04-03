#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= rows - 1; i++)
	{
		for (j = 0; j <= cols - 1; j++)
		{
			board[i][j] = set;
		}
	}
}


void DisplayBoard(char board[ROWS][COLS], int row, int col)
{

	int i = 0;
	int j = 0;
	printf("----------------扫雷游戏--------------------\n");

	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("----------------扫雷游戏--------------------\n");

}


void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;

	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}

}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 1;
	
	while (win <= row * col - EASY_COUNT)
	{
		printf("请输入要探测的坐标（例如：1 1）>>");
		scanf("%d%d", &x, &y);

		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("该坐标已被排查过了，不要重复排查.\n");
			}
			else
			{
				if (mine[x][y] == '1')//如果是雷
				{
					printf("很遗憾，你被炸死了，游戏结束\n");
					DisplayBoard(mine, ROW, COL);
					break;
				}
				else
				{
					win++;
					show[x][y] = Get_MineCount(mine, x, y) + '0';//转换成数字字符
					DisplayBoard(show, ROW, COL);
				}
			}
			
			
			
			
		}
		else
		{
			printf("输入非法坐标，请重新输入。\n");
		}
	}

	if (win == row * col - EASY_COUNT + 1)
	{
		printf("恭喜你，获得胜利。\n");
		DisplayBoard(mine, ROW, COL);

	}



}


int Get_MineCount(char board[ROWS][COLS], int x, int y)
{
	int r = 0;
	int i = 0;
	int j = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			r += board[i][j] - '0';
		}
	}
	return r;
}
