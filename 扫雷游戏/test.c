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
	char mine[ROWS][COLS] = { 0 };//��ʼ���׵ı鲼��Ϣ��ȫ0��ʾ����
	char show[ROWS][COLS] = { 0 };//��ʼ���Ų�����׵���Ϣ���������������ʼ��ȫΪ��*����������

	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//����
	SetMine(mine, ROW, COL);

	//DisplayBoard(mine, ROW, COL);//ֻ��ӡ�м�9*9,	����Ϸ�в���ӡmine
	DisplayBoard(show, ROW, COL);

	//����
	FindMine(mine, show, ROW, COL);

}


int main()

{
	//����������������
	srand((unsigned int)time(NULL));
	int input = 0;

	do {
		menu();
		printf("������:>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			printf("ɨ�ף�����\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������\n");
			break;
		}

	} while (input);

	return 0;
}