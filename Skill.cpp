/*
 * Skill.cpp
 *
 *  Created on: May 5, 2022
 *      Author: y nishizawa
 */

#include "Skill.hpp"

Skill::Skill(int cHP, int cMP, int chit, std::string cname){
	this->HP = cHP;
	this->MP = cMP;
	this->hit = chit;
	this->name = cname;
}

Skill::~Skill(){

}

int Skill::GetHP(){
	return HP;
}

int Skill::GetMP(){
	return MP;
}

int Skill::GetHit(){
	return hit;
}

std::string Skill::Getname(){
	return name;
}




