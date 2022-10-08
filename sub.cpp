/*
 * sub.cpp
 *
 *  Created on: May 17, 2022
 *      Author: y nishizawa
 */

#include "sub.hpp"


int Input(int min, int max) {
	int defvalue = 0;
	while (defvalue == 0) {
		cin >> defvalue;
		if (defvalue < min || defvalue > max || cin.fail()) {
			cout << "I'm afraid to say your number is wrong" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			defvalue = 0;
		}
	}
	const int retvalue = defvalue;
	return retvalue;
}


int Combat(int* _damage, bool **_healcommand, int currentMP, int _command) {
	int const NumberofSkill = 6;
	static Skill plskills[NumberofSkill] = {
		Skill(50, 30, 80, "fire"),
		Skill(80, 30, 40, "storn"),
		Skill(30, 0, 80, "body attach"),
		Skill(100, 60, 50, "final attack"),
		Skill(-100, 10, 100, "heal"),
		Skill(10, 30, 10, "Slash-All")   //skill for practice "do-while function"
	};


	int conMP = 0;    //MP consumed
	int hitting = 0;  //hit probability
	int power = 0;  //assumed damage. 
	int command = _command;
	 //The types of these three variable does't have specific reason. "int" is fine. I just try to use


	while (true) {
		power = plskills[command - 1].GetHP();
		hitting = plskills[command - 1].GetHit();
		conMP = plskills[command - 1].GetMP();

		std::srand(time(NULL));
		int random = rand() % 100;

		if (conMP > currentMP) {
			cout << "your MP is not enough!!\n";
			conMP = -1;
			break;
		}
		else if (power < 0) {
			cout << "You try to heal your damage...\nYou recover ";
			cout << -power << " points!\n";

			*_damage = power;
			**_healcommand = true;
			break;
		}
		else if (command == 6) { //specialized Slash-all Skill
			int i = 1;
			cout << "try " << i << endl;
			do {
				i++;
				Sleep(1000);
				hitting += 10;
				power += 10;
				cout << "hit!\n";
				Sleep(500);
				cout << "try " << i << endl;
			} while (hitting < random);
			Sleep(500);
			cout << "Miss!\nThe damage comes to " << (i - 1)*10 << " points!!";
			Sleep(1000);
			*_damage = power;
			break;
		}
		else if (random <= hitting) {
			cout << "Hit! The damage is " << power << " point!" << endl;
			*_damage = power;
			break;
		}
		else {
			cout << "Miss!" << endl;
			break;
		}
	}

	return conMP;
}

int Command(bool* defdamage, int* comMP, bool* healcommand, int currentMP) {
	
	int num1;
	int a = 0;
	int damage2 = 0;
	bool* _healcommand = healcommand;
	while (true) {
		cout << endl << "command?: 1 combat 2 defence 3 run away" << endl;
		num1 = Input(1, 3);
		switch (num1) {
		case 1:
			cout << endl << "skill?: 1 fire 2 storn 3 body attack 4 final attack 5 heal 6 Slash-All 7 cancel" << endl;
			{    //WHen using "switch-case function, you should declare variables in a scope. Otherwise, these variables still remain in onthe label
				int command = Input(1, 7);
				if (command == 7) continue;				
				else {
					*comMP = Combat(&damage2, &_healcommand, currentMP, command);
					if (*comMP < 0) continue;					
				} 
			}			
			break;
		case 2:
			*defdamage = true;
			break;
		case 3:
			cout << "You can't run away!" << endl;
			continue;
		default:
			cout << "Your input was wrong: command again!" << endl;
			continue;
		}
		break;
	}
	return damage2;

}

//(want to) change boss skills

int receivedamage(bool* defdamage, int* comMP, int currentMP) {
	int const NumberofSkill = 4;
	static Skill skills[NumberofSkill] = {              //I intensionally changed the way to make instance from the one I did in the function "Combat" (I wanted to practice switch method before)
		Skill(40, 40, 60, " "),
		Skill(80, 60, 40, " "),
		Skill(30, 20, 100, " "),
		Skill(20, 0, 100, " ")
	};

	int power = 0;
	int hitting = 0;
	int random = 0;
	int randomnumber = 0;    //implement this in order to create random nunmer more randomly even within a second
//	bool defdamage = _defdamage;

	while (true) {
		std::srand(time(NULL));
		random = (rand() % 100) + randomnumber;
		int selectskill = random % 4;
		power = skills[selectskill].GetHP();
		hitting = skills[selectskill].GetHit();
		*comMP = skills[selectskill].GetMP();
		if (currentMP < *comMP) {   //I can also fix to "if(currentMP >= *comMP){break;}. I want to use "continue" so I wroted like this
			randomnumber++;
			continue;
		}
		else break;
	}


	if (*defdamage == true) {
		power = power / 2;
		*defdamage = false;
		cout << "You focus on your defense!" << endl;
	}

	if (random <= hitting) {
		cout << "Critical Hit!" << endl;
	}
	else {
		power = 0;
		cout << "Small Hit!" << endl;
	}

	cout << "You got " << power + 10 << " points damage!" << endl; // the number of "10" is constant damage from every combat. this is magic number, so I will fix later...
	return power;
}

void display(int partynum, vector<string> name, vector<int> hp, vector<int> mp) {
	printf(
		"+----------------------------------------------Your Party----------------------------------------+\n\n"
	);
	for (int i = 0; i < partynum; i++) {
		std::cout << "|| Name " << name[i] << " | HP " << hp[i] << " |  MP " << mp[i] << " ";
	}
	printf(
		"||\n\n+----------------------------------------------Your Party----------------------------------------+\n"
	);
}

		/* failed try (I guess c++ doesn't expect string type?
		printf(
			"| name %8s HP %3d MP %3d |",
			name[i], //player[i].Getname()
			hp[i],  //player[i].GetHP()
			mp[i]  //player[i].GetMP()
		);		
		*/