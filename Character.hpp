/*
 * character.cpp
 *
 *  Created on: 2022/04/20
 *      Author: y nishizawa
 */

#include <iostream>
#include <string>
#include <cstdio>

#ifndef H_CHARACTER
#define H_CHARACTER

using namespace std;

class Character{
    public:
		Character(int HP, int MP, string name);//constructor
		Character();
        ~Character(); //destructor

        int InputName();
        int GetHP();

        void SetHP(int _HP);

        int GetMP();
        void Showname();

        void SetMP(int _MP);

        string Getname();
        Character(const Character &obj); //copy constructor. it isn't used yet


    private: //    next time topic"where should i put there three variables; private or public
        int HP;
        int MP;
        string name;


};

#endif /* H_CHARACTER */


