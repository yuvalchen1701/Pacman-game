#ifndef __BOARD_H
#define __BOARD_H

#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;

const char LEFT_KEY_LITTLE = 'a';
const char LEFT_KEY_CAPITAL = 'A';
const char RIGHT_KEY_LITTLE = 'd';
const char RIGHT_KEY_CAPITAL = 'D';
const char UP_KEY_LITTLE = 'w';
const char UP_KEY_CAPITAL = 'W';
const char DOWN_KEY_LITTLE = 'x';
const char DOWN_KEY_CAPITAL = 'X';
const char STAY_KEY_LITTLE = 's';
const char STAY_KEY_CAPITAL = 'S';
const char ESC = 27;

const int MAX_ROWS = 25;
const int MAX_COLS = 80;
const char PACKMAN_CH = '@';
const char GHOST_CH = '$';
const char BREADCRUMBS = '.';
const char EMPTY_CH = ' ';
const char BORDER_CH = '#';

void gotoxy(int x, int y);


class Board
{
	private:
		static int	ROWS;
		static int	COLS;
		char	BoardArray[25][80];
	
	public:
		static int getRows() { return ROWS; }
		static int getCols() { return COLS; }
		static void setRows(int row) { ROWS = row; }
		static void setCols(int col) { COLS = col; }
		void		printBoard(int rowPL); /* Position of '&' */
		/* This function gets a column and row and returns the sign in the position of the board */
		char		getCell(int row, int col) { return BoardArray[row][col]; }
		void		setCell(int row, int col, char ch);
		bool		isATunel(int row, int col);
		bool		isFrameBoard(int row, int col);


};




#endif // __BOARD_H