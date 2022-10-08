/*
 * battle.cpp
 *
 *  Created on: 2022/04/21
 *      Author: y nishizawa
*/

#include "Battle.hpp"

Battle::Battle(){
	this->damage = 0;
}

int Battle::GetRandom(){
			std::srand( time(NULL) );
			int random = rand () % 100;
			return random;
		}





