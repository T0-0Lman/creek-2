#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
#define ChessNumber 3
char Board[ROW][COL];
void InitBoard(char Board[ROW][COL], int row, int col);
void Display(char Board[ROW][COL], int row, int col);
void PlayerMove(char Board[ROW][COL], int row, int col);
void ComputerMove(char Board[ROW][COL], int row, int col);
char CheckWin(char Board[ROW][COL], int row, int col);
int CheckFull(char Board[ROW][COL], int row, int col);