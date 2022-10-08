/*
 * Skill.hpp
 *
 *  Created on: May 5, 2022
 *      Author: y nishizawa
 */

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>


#ifndef SKILL_HPP_
#define SKILL_HPP_

class Skill{
	public:
		Skill(int cHP, int cMP, int chit, std::string cname);
		~Skill();

		int GetHP();
		int GetMP();
		int GetHit();
		std::string Getname();

/*
		void SetHP();
		void SetMP();
		void SetHit();
		void Setname();
*/

	private:
		int HP;
		int MP;
		int hit;
		std::string name;


};

/* practise for "typedef struct" ... possibly I will add the function
typedef struct{
	int attack;
	int hit;
}Bossskill;

*/

#endif /* SKILL_HPP_ */
