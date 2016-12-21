/*
 * Battlefield.cpp
 *
 *  Created on: Dec 19, 2016
 *      Author: helarabawy
 */

#include "Battlefield.h"

// Constructor
Battlefield::Battlefield()
{
	m_row = 0;
	m_col = 0;
	m_mines = 0;
	m_uncoveredCount = 0;
	m_hasDied = false;
}


// Destructor
Battlefield::~Battlefield()
{
	//Cleanup code here
}

// Returns whether user's inputted attributes are valid
bool Battlefield::setAttributes(int r, int c, int mines)
{
	// returning false if invalid parameters
	if ((r < 1) || (r > MAXROWS) || (c < 1) || (c > MAXCOLS) || (mines < 0) || (mines >= (r*c)))
		return false;

	// saving valid parameters
	m_row = r;
	m_col = c;
	m_mines = mines;

	// randomly distribute mines
	while(mines > 0)
	{
		int mr = randInt(1, r);
		int mc = randInt(1, c);
		if (field[mr][mc].containsMine())
			continue;
		field[mr][mc].setMine();
		mines--;
	}

	// setting adjacent count for each cell
	for (int i = 1; i <= m_row; i++)
	{
		for (int j = 1; j <= m_col; j++)
		{
			field[i][j].setAdjCount(adjMines(i, j));
		}
	}

	return true;
}


// Function to test the cell that the user inputted
int Battlefield::testCell(string input)
{
	// testing if string format was correct
	if (input.size() != 3 || !isalpha(input.at(0)) || !isalpha(input.at(2)))
	{
		return TEST_INVALID_ENTRY;
	}

	// decoding into grid coordinates
	int r = toupper(input.at(0)) - 'A' + 1;
	int c = toupper(input.at(2)) - 'A' + 1;

	// testing if given coordinates are in the battlefield
	if (r < 1 || r > m_row || c < 1 || c > m_col)
	{
		return TEST_INVALID_ENTRY;
	}

	// checking if testing already tested cell.
	if (!(field[r][c].isCovered()))
	{
		return TEST_ALREADY_UNCOVERED;
	}

	// uncovering covered cell
	field[r][c].uncoverCell();
	m_uncoveredCount++;

	// hit a mine
	if (field[r][c].containsMine())
	{
		m_hasDied = true;
	} else if (field[r][c].getAdjCount() == 0)
	{
		uncoverAdjCells(r, c);
	}
	return TEST_SUCCESS;
}

// displays battlefield
void Battlefield::display()
{
	char index;
	// top row;
	cout << "  ";
	for (int i = 0; i < m_col; i++)
	{
		index = 'A' + i;
		cout << index << " ";
	}

	cout << endl;

	for (int i = 1; i <= m_row; i++)
	{
		index = 'A' + i - 1;
		cout << index;
		for (int j = 1; j <= m_col; j++)
		{
			if (field[i][j].isCovered())
				cout << " *";
			else
				cout << " " << field[i][j].getAdjCount();
		}
		cout << endl;
	}
}

// returns if user is now dead
bool Battlefield::hasDied()
{
	return m_hasDied;
}

// returns if user won
bool Battlefield::hasWon()
{
	int gridSize = m_row * m_col;

	if ((gridSize - m_mines) == m_uncoveredCount)
		return true;
	else
		return false;
}

// uncover adjacent cells
void Battlefield::uncoverAdjCells(int r, int c)
{
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0) continue;

			if (field[r + i][c + j].uncoverCell() == false) continue;

			m_uncoveredCount++;

			if (field[r+i][c+j].getAdjCount() == 0)
			{
				uncoverAdjCells(r + i, c + j);
			}
		}
	}
}

// open up adjacent cells
int Battlefield::adjMines(int r, int c)
{
	int mineCount = 0;

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			mineCount += field[r + i][c + j].containsMine();
		}
	}

	return mineCount;
}

// returns a uniformly distributed rand int from min to max, inclusive
int Battlefield::randInt(int min, int max)
{
	if (max < min)
		swap(max, min);
	static random_device rd;
	static mt19937 generator(rd());
	uniform_int_distribution<> distro(min, max);
	return distro(generator);
}
