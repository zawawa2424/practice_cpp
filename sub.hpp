/*
 * sub.hpp
 *
 *  Created on: May 17, 2022
 *      Author: y nishizawa
 */

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <vector>
#include "Skill.hpp"

#ifndef SUB_HPP_
#define SUB_HPP_

using namespace std;

int Input(int min, int max);

int Combat(int *_damage, bool **_healcommand,int currentMP, int command); //this prototype isn't necesarry. It isn't called in main function. But just in case.

int Command(bool *defdamage, int *comMP, bool *healcommand, int currentMP);

int receivedamage(bool *defdamage, int *comMP, int currentMP);

void display(int partynum, vector<string> name, vector<int> hp, vector<int> mp);





#endif /* SUB_HPP_ */
