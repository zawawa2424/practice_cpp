/*
 * character.cpp
 *
 *  Created on: 2022/04/21
 *      Author: y nishizawa
 */

#include "Character.hpp"

Character::Character(int _HP, int _MP, string _name){
	this->HP = _HP;
	this->MP = _MP;
	this->name = _name;
}

Character::Character(){
	this->HP = 100;
	this->MP = 100;
	this->name = " ";
}


Character::~Character(){

}

void Character::SetHP(int _HP){
	this->HP = _HP;
}

void Character::SetMP(int _MP){
	this->MP = _MP;
}
int Character::GetHP(){
		return HP;
}

int Character::GetMP(){
		return MP;
}

string Character::Getname(){
		return name;
}

void Character::Showname(){
	cout << "your name is " << name << endl;
	cout << "your current HP is " << HP << endl;
	cout << "your current MP is " << MP << endl;
}

int Character::InputName(){
	string new_name;
	cin >> new_name;
    name = new_name;
    return 0;
}

Character::Character(const Character &obj){
	this->HP = 100;
	this->MP = 100;
}

