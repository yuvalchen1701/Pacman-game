#include "Board.h"

int Board::ROWS = 0;
int Board::COLS = 0;

void gotoxy(int x, int y)
{
	static HANDLE hConsoleOutput = NULL;
	if (NULL == hConsoleOutput)
		hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwCursorPosition = { x, y };
	cout.flush();
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}


/* This function gets a column and row and returns true in case the position is a tunel */
bool Board::isATunel(int row, int col) 
{
	if (row == 0 && (BoardArray[row][col] == EMPTY_CH))
		return true;
	else if (col == 0 && (BoardArray[row][col] == EMPTY_CH))
		return true;
	if (row == ROWS && (BoardArray[row-1][col] == EMPTY_CH))
		return true;
	else if (col == COLS && (BoardArray[row][col-1] == EMPTY_CH))
		return true;
	else 
		return false;
}

/* This function prints the board */
void Board::printBoard(int rowPL)
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
			cout << BoardArray[row][col];
		cout << endl;
	}

	gotoxy(0, rowPL);
	cout << "SCORE:" << endl;
	cout << "LIFE: 3 ";
}


/* This function gets a column, row and sign. Function set the sign in the position of the board */
void Board::setCell(int row, int col ,char ch)
{
	BoardArray[row][col] = ch;
}

bool Board::isFrameBoard(int row, int col)
{
	if (row == 0 || row == ROWS-1 || col == 0 || col == COLS-1)
		return true;
	return false;
}