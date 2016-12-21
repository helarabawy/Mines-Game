/*
 * Cell.h
 *
 *  Created on: Dec 20, 2016
 *      Author: helarabawy
 */

#ifndef CELL_H_
#define CELL_H_

using namespace std;

class Cell
{
	public:
		// Constructor
		Cell();
		~Cell();

		// Mutators
		bool uncoverCell();
		void setMine();
		void setAdjCount(int n);

		// Accessors
		bool isCovered();
		bool containsMine();
		int getAdjCount();

	private:
		// Declare variables
		bool m_hasMine;
		bool m_isCovered;
		int m_adjCount;
};

#endif /* CELL_H_ */
