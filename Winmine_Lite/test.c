#define _CRT_SECURE_N0_WARNINGS 1
#define _CRT_SECURE_N0_WARNINGS 1
#include"Winmine.h"
void menu()
{
	printf("######################\n");
	printf("######  1.GAME	######\n");
	printf("######  0.EXIT	######\n");
	printf("######################\n");
}
void game()
{
	srand((unsigned)time(NULL));
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	DisplayBoard(show, ROW, COL);
	SetBoard(mine, ROW, COL);
	CheckBoard(mine, show, ROW, COL);
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择菜单选项:");
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
			printf("请输入菜单选项\n");
			break;
		}
	} while (input);
	return 0;
}