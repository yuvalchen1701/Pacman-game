#pragma once
#include "Game.h"
#include "Board.h"
#include "BestGhost.h"
#include "GoodGhosts.h"
#include "NoviceGhost.h"
#include "Ghosts.h"
#include "Position.h"
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <filesystem>
#include <fstream>
#include <windows.h>

using std::vector;
using std::fstream;
using std::filesystem::directory_iterator;

/*This function return vector of screens names */
vector<string> getScreensName()
{
	vector<string> filesVector;

	for (const auto& file : directory_iterator("."))
	{
		if (file.path().extension() == ".screen")
			filesVector.push_back(file.path().filename().string());
	}
	filesVector.shrink_to_fit();
	return filesVector;
}

/* Function prints the menu of the game */
int printMenu();

/* Function gets user's choice and reference of the board.
   The function implements what is required of the user according to the menu */
void setUserChoice(int choice, vector<string> Array_Files);

void creatGhost(char level, vector<Position>ArrayGhostPos, vector<Ghosts*>& arr_Ghost);

void initBoard(bool& flag, string line, Board& Board, int& row, Position& PacmanPosition, 
	           Position& PosPL, vector<Position>& ArrayGhostPos, int& countBread);

void getDetailsFromScreenFile(vector<string> Array_Files, char level);

int main()
{
	vector<string> Array_Files;
	Array_Files = getScreensName();
	int userChoice = printMenu();
	setUserChoice(userChoice, Array_Files);
}

int printMenu()
{
	int choice;

	cout << "   WELCOME TO PACMAN GAME" << endl;
	cout << endl;
	cout << "   (1) Start a new game" << endl;
	cout << "   (8) Present instructions and keys " << endl;
	cout << "   (9) EXIT" << endl;
	cout << endl;
	cout << "   Please enter your choice: ";
	cin >> choice;

	while (choice != 1 && choice != 8 && choice != 9)
	{
		cout << "Please enter a valid choice!" << endl;
		cin >> choice;
	}

	return choice;
}

void setUserChoice(int choice, vector<string> Array_Files)
{
	char level;
	switch (choice)
	{
	case 1:
		system("cls");
		cout << "Select level of Game!" << endl;
		cout << "(a) BEST (b) GOOD and (c) NOVICE" << endl;
		cout << "Your choice: ";
		cin >> level;

		getDetailsFromScreenFile(Array_Files, level);
		break;
	case 8:
		system("cls");
		cout << "Pacman move around the maze and eats all the little white dots while avoiding those nasty ghosts." << endl;
		cout << "Press w or W to move UP" << endl;
		cout << "Press a or A to move RIGHT" << endl;
		cout << "Press d or D to move LEFT" << endl;
		cout << "Press x or X to move DOWN" << endl;
		cout << "EAT ALL THE LITTLE WHITE DOTS AND YOU WIN! BE CAREFUL YOU HAVE ONLY 3 LIFES." << endl;
		cout << endl;
		setUserChoice(printMenu(), Array_Files);
		break;
	case 9:
		system("cls");
		cout << "GoodBye!!!" <<endl;
		break;
	default:
		break;
	}
}

void creatGhost(char level, vector<Position>ArrayGhostPos, vector<Ghosts*>& arr_Ghost)
{
	switch (level)
	{
	case 'a':
		for (int i = 0; i < ArrayGhostPos.size(); i++)
		{
			BestGhost ghost(ArrayGhostPos[i]);
			arr_Ghost.push_back(new BestGhost(ghost));
		}

		break;
	case 'b':
		for (int i = 0; i < ArrayGhostPos.size(); i++)
		{
			GoodGhost ghost(ArrayGhostPos[i]);
			arr_Ghost.push_back(new GoodGhost(ghost));
		}

		break;

	case 'c':
		for (int i = 0; i < ArrayGhostPos.size(); i++)
		{
			NoviceGhost ghost(ArrayGhostPos[i]);
			arr_Ghost.push_back(new NoviceGhost(ghost));
		}

		break;

	default:
		cout << "Wrong level, please select again: " << endl;
		cout << "(a) BEST (b) GOOD and (c) NOVICE" << endl;
		cout << "Your choice: ";
		cin >> level;
		creatGhost(level, ArrayGhostPos, arr_Ghost);
		break;

	}

}

void initBoard(bool& flag, string line, Board& Board, int& row, Position& PacmanPosition, 
			   Position& PosPL, vector<Position>& ArrayGhostPos, int& countBread)
{
	for (int col = 0; col < line.size(); col++)
	{
		if (line.at(col) == PACKMAN_CH)
		{
			PacmanPosition.setX(row);
			PacmanPosition.setY(col);
			Board.setCell(row, col, EMPTY_CH);
		}

		else if (line.at(col) == GHOST_CH)
		{
			Position GhostPosition;
			GhostPosition.setX(row);
			GhostPosition.setY(col);
			ArrayGhostPos.push_back(GhostPosition);
			Board.setCell(row, col, BREADCRUMBS);
			countBread++;
		}

		else if (line.at(col) == BORDER_CH)
			Board.setCell(row, col, BORDER_CH);

		else if (line.at(col) == '%')
			Board.setCell(row, col, EMPTY_CH);

		else if (line.at(col) == '&')
		{
			PosPL.setX(row);
			PosPL.setY(6);
			col = line.size();
			for (int i = row; i <= row + 2; i++)
			{
				for (int j = 0; j < line.size(); j++)
					Board.setCell(i, j, EMPTY_CH);
			}

			flag = true;
			row += 2;
		}

		else if (line.at(col) == EMPTY_CH)
		{
			Board.setCell(row, col, BREADCRUMBS);
			countBread++;
		}
	}
}

void getDetailsFromScreenFile(vector<string> Array_Files, char level)
{
	Board Board;
	Position PacmanPos, PosPL;
	vector<Position>ArrayGhostPos;
	vector<Ghosts*> arr_Ghost;
	string line;
	int maxRows = 0, maxCols = 0, countBread = 0;
	bool flag = false, GameOver = false;
	int currLife = 3;
	

	for (int i = 0; i < Array_Files.size() && !GameOver; i++)
	{
		ifstream file(Array_Files[i]);
		getline(file, line);
		initBoard(flag, line, Board, maxRows, PacmanPos, PosPL, ArrayGhostPos, countBread);
		maxCols = line.size();

		while (getline(file, line))
		{
			maxRows++;
			initBoard(flag, line, Board, maxRows, PacmanPos, PosPL, ArrayGhostPos, countBread);
			if (flag)
			{
				for (int i = 0; i < 2; i++)
					getline(file, line);
			}
		}

		creatGhost(level, ArrayGhostPos, arr_Ghost);
		system("cls");
		Board.setRows(maxRows);
		Board.setCols(maxCols);

		Game newGame(PosPL, countBread);
		newGame.initCurrLife(currLife);
		newGame.setGame(arr_Ghost, PacmanPos, Board);
		if (newGame.getLife() == 0)
			GameOver = true;
		else
			currLife = newGame.getLife();
	}

}