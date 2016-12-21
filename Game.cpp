/*
 * Game.cpp
 *
 *  Created on: Dec 19, 2016
 *      Author: helarabawy
 */

#include "Battlefield.h"
#include "Game.h"

// Constructor implementation
Game::Game()
{
	cout << "Hey User! Welcome to this game of Mines!" << endl << endl;
}

// Destructor implementationn
Game::~Game()
{}

// Function to start game
void Game::start()
{
	bool isValidEntry = getAttributes();

	while (!isValidEntry)
	{
		cout << "You entered an invalid input, try again!" << endl << endl;
		isValidEntry = getAttributes();
	}

	play();

	return;
}

// to get valid battlefield attributes
bool Game::getAttributes()
{
	int rows, cols, mines;

	cout << "How many rows should the battlefield be? ";
	cin >> rows;

	cout << "How many columns should the battlefield be? ";
	cin >> cols;

	cout << "How many mines should this battlefield have? ";
	cin >> mines;

	cin.ignore(10000, '\n');

	return field.setAttributes(rows, cols, mines);
}

// play game
void Game::play()
{
	string input;
	int testVal;
	while (!(field.hasDied()) && !(field.hasWon()) )
	{

		// display battlefield
		cout << endl;
		field.display();
		cout << endl;

		// prompt user
		cout << "What cell would you like to test? (ex. \"C E\") : ";
		getline(cin, input);

		// test user's input
		testVal = field.testCell(input);

		switch(testVal)
		{
			case TEST_SUCCESS:
			{
				cout << endl  << "Valid pick!" << endl;
				break;
			}
			case TEST_INVALID_ENTRY:
			{
				cout << endl << "These are invalid coordinates! Try again." << endl;
				break;
			}
			case TEST_ALREADY_UNCOVERED:
			{
				cout << endl << "You have already uncovered this cell! Try again." << endl;
				break;
			}
			default:
			{
				cout << endl << "Invalid entry." << endl;
				break;
			}
		}
	}

	// user lost
	if (field.hasDied())
	{
		cout << endl << "GAME OVER" << endl <<
				"-----------------------------------------------------" << endl;
		exit(1);
	}

	// user won
	if (field.hasWon())
	{
		cout << endl << "YOU WON!!!" << endl <<
				"-----------------------------------------------------" << endl;
		exit(1);
	}

}
