#define _CRT_SECURE_N0_WARNINGS 1
#include"Game_1.h"

void InitBoard(char Board[ROW][COL], int row, int col)
{
	for (row = 0; row < ROW; row++)
	{
		for (col = 0; col < COL; col++)
		{
			Board[row][col] = ' ';
		}
	}
}

void Display(char Board[ROW][COL], int row, int col)
{

	for (row = 0; row < ROW; row++)
	{
		for (col = 0; col <= COL; col++)
		{
			if (col < COL)
				printf("+---");
			else
				printf("+");
		}
		printf("\n");
		for (col = 0; col <= COL; col++)
		{
			if (col < COL)
				printf("| %c ", Board[row][col]);
			else
				printf("|");
		}
		printf("\n");
		if (row == ROW - 1)
		{
			for (col = 0; col < COL; col++)
				printf("+---");
		}
	}
	if (row == ROW && col == COL)
		printf("+");
	printf("\n");
}

void PlayerMove(char Board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = 0, y = 0;
		printf("请玩家输入坐标（x , y）:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (Board[x - 1][y - 1] != ' ')
			{
				printf("你输入的坐标已有棋子！\n");
			}
			else
			{
				Board[x - 1][y - 1] = 'x';
				break;
			}
		}
		printf("请按规定范围内输入坐标：\n");
	}
}

void ComputerMove(char Board[ROW][COL], int row, int col)
{
	printf("电脑走棋\n");

	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (Board[x][y] == ' ')
		{
			Board[x][y] = 'o';
			break;
		}
	}
}

int CheckFull(char Board[ROW][COL], int row, int col)
{
	for (row = 0; row < ROW; row++)
	{
		for (col = 0; col < COL; col++)
		{
			if (Board[row][col] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char CheckWin(char board[ROW][COL], int row, int col)
{
	for (row = 0; row < ROW; row++)
	{
		if (board[row][0] != ' '
			&& board[row][0] == board[row][1]
			&& board[row][1] == board[row][2]
			)
		{
			return board[row][0];
		}
	}

	for (col = 0; col < COL; col++)
	{
		if (board[0][col] != ' '
			&& board[0][col] == board[1][col]
			&& board[0][col] == board[2][col])
		{
			return board[0][col];
		}
	}

	if (board[0][0] != ' '
		&& board[0][0] == board[1][1]
		&& board[1][1] == board[2][2])
	{
		return board[0][0];
	}

	if (board[2][0] != ' '
		&& board[2][0] == board[1][1]
		&& board[1][1] == board[0][2])
	{
		return board[2][0];
	}

	if (CheckFull(board, row, col) == 1)
	{
		return 'Q';
	}
	return 'C';
}

//char CheckWin(char Board[ROW][COL], int row, int col)
//{
//	int i = 0, j = 0, flag = 0;
//	for (i = 0; i < ROW; i++)
//	{
//		flag = 0;
//		for (j = 0; j <	COL - 1; j++)
//		{
//			if (Board[i][j] == Board[i][j + 1] && Board[i][j] != ' ')
//			{
//				flag++;
//			}
//			else if (flag == ChessNumber - 1)
//			{
//				return Board[i][j];
//			}
//			else
//			{
//				flag = 0;
//			}
//		}
//
//	}
//
//	for (i = 0; i < ROW - 1; i++)
//	{
//		for (j = 0; j < COL; j++)
//		{
//			if (Board[i][j] == Board[i + 1][j] && Board[i][j] != ' ')
//			{
//				flag++;
//			}
//			else
//			{
//				flag = 0;
//			}
//			if (flag == ChessNumber - 1)
//				return Board[i][j];
//		}
//
//	}
//
//	flag = 0;
//	for (i = 0; i < ROW - 1; i++)
//	{
//		for (j = 0; j < COL - 1; j++)
//		{
//			if (Board[i][j] == Board[i + 1][j + 1] && Board[i][j] != ' ')
//			{
//				flag++;
//			}
//			else
//			{
//				flag = 0;
//			}
//		}
//		if (flag == ChessNumber - 1)
//			return Board[i][j];
//	}
//
//	flag = 0;
//	for (i = 0; i < ROW - 1; i++)
//	{
//		for (j = COL - 1; j > 0; j--)
//		{
//			if (Board[i][j] == Board[i + 1][j - 1] && Board[i][j] != ' ')
//			{
//				flag++;
//			}
//			else
//			{
//				flag = 0;
//			}
//
//		}
//		if (flag == ChessNumber - 1)
//			return Board[i][j];
//	}
//
//	if (CheckFull(Board, ROW, COL) == 1)
//	{
//		return 'Q';
//	}
//	return 'C';
//}