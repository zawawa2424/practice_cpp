/*
 * main.cpp
 *
 *  Created on: 2022/5/12
 *      Author: y nishizawa
 *
 *the future topic which I want to 
 * 
 * 
 * 
 */


#include "Battle.hpp"
#include "Boss.hpp"
#include "Character.hpp"
#include "Skill.hpp"
#include "sub.hpp"


int main(){
	std::cout << "How many in your party? choose from 1 to 3" << endl;
	int partynum = Input(1, 3);

	std::cout << "Which level will you choose? 1 easy 2 normal 3 difficult 4 debug mode" << endl;
	int level = Input(1, 4);
	Character boss(100*partynum*level, 100*partynum*level, "Kamesan");

	//check wether standard play or debug
	if (level < 4) std::cout << partynum << " player(s) will beat " << boss.Getname()  << endl;
	else {
		std::cout << "debug" << endl;
		boss.SetHP(100000);
	}


	Character *player = new Character[partynum];  
	vector<string> names;  //for display
	vector<int> hps;
	vector<int> mps;
	


	for (int i = 0; i < partynum; i++){
		std::cout << "please input your name(s) below:" << i + 1 << endl;
		player[i].InputName();
		player[i].Showname();
		names.push_back(player[i].Getname());// next problem
		hps.push_back(player[i].GetHP());
		mps.push_back(player[i].GetMP());
	}
	Sleep(2000);

	int combatnum = 0;
	const int REDAMAGE = 10;
	int comMP = 0;
	bool defdamage = false;  //defencse damage
	bool healcommand = false;   
	player[0].SetHP(200); //for adjusting the difficulty of the game
	hps[0] = 200;
	int deathnum = 0; //use later to check whether all of members are died or not
	
	
	do{
		for (int k = 0; k < partynum; k++){
			system("cls");
			// for display
			/* it doesn't work
			hps.erase(hps.begin() + k);
			hps.insert(hps.begin() + k, player[k].GetHP());
			mps.erase(hps.begin() + k);
			mps.insert(hps.begin() + k, player[k].GetMP());
			*/
			
			display(partynum, names, hps, mps);
			player[k].Showname();
			if (player[k].GetHP() <= 0) {
				std::cout << "you can no longer fight...\nYourHP is " << player[k].GetHP() << endl;
				Sleep(1300);
			}
			else if (boss.GetHP() <= 0) break;
			else {
				std::cout << boss.GetHP() << " is " << boss.Getname() << "s HP";
				int DamageorHeal = Command(&defdamage, &comMP, &healcommand, player[k].GetMP());
				if (healcommand == true) {
					player[k].SetHP(player[k].GetHP() - DamageorHeal);
					healcommand = false;
				}
				else {
					boss.SetHP(boss.GetHP() - DamageorHeal);
				}
				Sleep(1000);
				if (boss.GetHP() <= 0) break;
	
				std::cout << "\n" << boss.Getname() << "'s attack!" << endl;
				player[k].SetMP(player[k].GetMP() - comMP);
				player[k].SetHP(player[k].GetHP() - REDAMAGE - receivedamage(&defdamage, &comMP, boss.GetMP()));
				boss.SetMP(boss.GetMP() - comMP);
				if (player[k].GetHP() < 0) player[k].SetHP(0); //you don't have to use{} when only one sentence in "if" statement
				comMP = 0;
				
				combatnum += 1;
				std::cout << "\ncombatnum: " << combatnum << endl;
				Sleep(2000);
				hps[k] = player[k].GetHP();
				mps[k] = player[k].GetMP();
				if( hps[k] == 0){
					deathnum += 1;
				}
			}
		}
	} while (deathnum < partynum && boss.GetHP() > 0);

	system("cls");
	for (int i = 0; i < partynum; i++) {
		std::cout << player[i].GetHP() << " is " << player[i].Getname() << "'s HP\n";
	}

	if (player[0].GetHP() <= 0 && boss.GetHP() <= 0){
		std::cout << "draw battle" << endl;
	}
	else if(player[0].GetHP() <= 0 && boss.GetHP() > 0){
		std::cout << "You lose..." << endl;
	}
	else {
		std::cout << "You win!!" << endl;
	}

	std::cout << "Thank you for playing!" << endl;
	Sleep(5000);

	delete[] player;

	return 0;
}
