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
	printf("游戏开始\n");
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
		printf("玩家获胜! \n");
	}
	if (ret == 'o')
	{
		printf("电脑获胜! \n");
	}
	if (ret == 'Q')
	{
		printf("玩家获胜! \n");
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
			printf("退出游戏...\n");
			break;
		default:
			printf("请按菜单选项选择！\n");
			break;
		}
	} while (input);
	return 0;
}