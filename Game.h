/*
 * Game.h
 *
 *  Created on: Dec 20, 2016
 *      Author: helarabawy
 */

#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <string>

using namespace std;


class Game
{
	public:
		// Constructor
		Game();

		// Destructor
		~Game();

		// Public function
		void start();

	private:
		// Private functions
		bool getAttributes();
		void play();

		// Private variables
		Battlefield field;
};

#endif /* GAME_H_ */
