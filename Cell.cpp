/*
 * Cell.cpp
 *
 *  Created on: Dec 19, 2016
 *      Author: helarabawy
 */

#include "Cell.h"

// Constructor implementation
Cell::Cell()
{
	m_hasMine = false;
	m_isCovered = true;
	m_adjCount = -1;
}

// Destructor implementation
Cell::~Cell()
{
	//Cleanup code here
}

// Uncovers cell
bool Cell::uncoverCell()
{
	if (m_isCovered == true)
	{
		m_isCovered = false;
		return true;
	} else
	{
		m_isCovered = false;
		return false;
	}
}

// Add mine to the cell
void Cell::setMine()
{
	m_hasMine = true;
}

// Sets count of adjacent mines
void Cell::setAdjCount(int n)
{
	m_adjCount = n;
}

// Returns whether cell is covered
bool Cell::isCovered()
{
	return m_isCovered;
}

// Returns whether cell has a mine
bool Cell::containsMine()
{
	return m_hasMine;
}

// Returns count of adjacent mines
int Cell::getAdjCount()
{
	return m_adjCount;
}

