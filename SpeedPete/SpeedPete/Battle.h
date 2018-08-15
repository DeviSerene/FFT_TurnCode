#pragma once
#include <vector>
#include "Character.h"
#include <iostream>

class Battle
{
public:
	Battle();
	~Battle();

	void Process(); //Forcast the turn order

private:
	std::vector <Character*> characters; //the characters in the battle
	std::vector <int> BT; //the BattleTime, each assigned to a character. Determines turn order.


};

