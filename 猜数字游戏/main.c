#define _CRT_SECURE_NO_WARNINGS

// ��������Ϸ 2024/2/3

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void menu()
{
	printf("################\n");
	printf("####����1��ʼ###\n");
	printf("####����0�˳�###\n");
	printf("################\n");

}

void game()
{
	//����һ�������1-100

	int guess = 0;
	int ret = rand() % 100 + 1;

	while (1)
	{
		printf("�������\n");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("�´���\n");
		}
		else if (guess < ret)
		{
			printf("��С��\n");
		}
		else
		{
			printf("�¶���\n");
			break;
		}
	}
}

int main()
{

	//����
	int input = 0;
	srand((unsigned int)time(NULL));//�������������Ҫ������ *p = NULL��ָ�룬0����˼
	do
	{
		menu();
		printf("�����룺");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ.\n");
			break;
		default:
			printf("������������ԡ�\n");
			break;

		}
	} while (input);
	return 0;
}

