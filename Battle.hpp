/*
 * battle.cpp
 *
 *  Created on: 2022/04/21
 *      Author: y nishizawa
*/

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "Character.hpp"


#ifndef H_BATTLE
#define H_BATTLE

using namespace std;

class Battle{
	public:
		int GetRandom();
		Battle();
		~Battle();


	private:
		int damage;


};

int GetRandom();
/*
int attack(){
	void Character::SetHP(500);
	int mario_HP = Character::GetHP();
	int percent = GetRandom();
	if (percent <= 90){
		mario_HP -= 100;
	}


	return mario_HP;

}
*/






#endif /* H_BATTLE */
