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
	//��ʼ��
	InitBoard(board,ROW,COL);
	DisplayBoard(board, ROW, COL);
	//����
	while (1)
	{

		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ	
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}


}


int main()
{
	srand((unsigned int)time(NULL));//����ʱ�������ȡ����������
	
	int input = 0;
	do {
		menu();//��ӡ�˵�
		printf("��ѡ��");
		scanf("%d", &input);
		
		switch (input)
		{
		case 1:
			printf("������,����������Ϊʤ��\n");
			game();
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("�������\n");
			break;

		}

	}while(input);
	return 0;
}