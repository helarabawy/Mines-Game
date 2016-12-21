/*
 * Battlefield.h
 *
 *  Created on: Dec 20, 2016
 *      Author: helarabawy
 */

#ifndef BATTLEFIELD_H_
#define BATTLEFIELD_H_

#include <string>
#include <iostream>
#include <random>
#include <cctype>

#include "Cell.h"
using namespace std;


// Constants
const int MAXROWS = 28;
const int MAXCOLS = 28;

const int TEST_SUCCESS = 0;
const int TEST_INVALID_ENTRY = 1;
const int TEST_ALREADY_UNCOVERED = 2;

class Battlefield
{
	public:
		// Constructor
		Battlefield();

		// Destructor
		~Battlefield();

		// Public functions
		bool setAttributes(int r, int c, int mines);
		int testCell(string input);
		void display();
		bool hasDied();
		bool hasWon();

	private:
		// Private functions
		void uncoverAdjCells(int r, int c);
		int adjMines(int r, int c);
		int randInt(int min, int max);

		// Variables
		Cell field[MAXROWS + 2][MAXCOLS + 2];
		int m_row;
		int m_col;
		int m_mines;
		int m_uncoveredCount;
		bool m_hasDied;

};

#endif /* BATTLEFIELD_H_ */
