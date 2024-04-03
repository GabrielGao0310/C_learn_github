#define _CRT_SECURE_NO_WARNINGS

// 猜数字游戏 2024/2/3

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void menu()
{
	printf("################\n");
	printf("####输入1开始###\n");
	printf("####输入0退出###\n");
	printf("################\n");

}

void game()
{
	//生成一个随机数1-100

	int guess = 0;
	int ret = rand() % 100 + 1;

	while (1)
	{
		printf("请猜数字\n");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了\n");
		}
		else if (guess < ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("猜对了\n");
			break;
		}
	}
}

int main()
{

	//输入
	int input = 0;
	srand((unsigned int)time(NULL));//生成随机数所需要的种子 *p = NULL空指针，0的意思
	do
	{
		menu();
		printf("请输入：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏.\n");
			break;
		default:
			printf("输入错误，请重试。\n");
			break;

		}
	} while (input);
	return 0;
}

