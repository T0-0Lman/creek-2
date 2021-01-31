#define _CRT_SECURE_N0_WARNINGS 1
#include"Game_1.h"

void menu()
{
	printf("######################\n");
	printf("#####	1.PLAY   #####\n");
	printf("#####	0.EXIT	 #####\n");
	printf("######################\n");
}

void game()
{
	printf("��Ϸ��ʼ\n");
	char Board[ROW][COL];
	InitBoard(Board, ROW, COL);
	char ret = ' ';
	CheckFull(Board, ROW, COL);
	while (1)
	{
		Display(Board, ROW, COL);
		PlayerMove(Board, ROW, COL);
		ret = CheckWin(Board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(Board, ROW, COL);
		ret = CheckWin(Board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == 'x')
	{
		printf("��һ�ʤ! \n");
	}
	if (ret == 'o')
	{
		printf("���Ի�ʤ! \n");
	}
	if (ret == 'Q')
	{
		printf("��һ�ʤ! \n");
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ...\n");
			break;
		default:
			printf("�밴�˵�ѡ��ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}