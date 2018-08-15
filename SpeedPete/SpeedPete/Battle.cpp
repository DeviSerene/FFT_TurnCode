#include "Battle.h"



Battle::Battle()
{
	//add the characters (speed, name)


	characters.push_back(new Character(15, "Gina"));
	BT.push_back(0);

	characters.push_back(new Character(11, "Pete"));
	BT.push_back(0);

	characters.push_back(new Character(25, "Sam"));
	BT.push_back(0);

	characters.push_back(new Character(22, "Ieuan"));
	BT.push_back(0);

}


Battle::~Battle()
{
	//clean up
	for each (Character* var in characters)
	{
		delete var;
	}
	characters.clear();
	BT.clear();
}


void Battle::Process()
{
	//the number of turns to forcast
	int TurnsToProcess = 10;
	std::vector <int> toTurn;

	while (TurnsToProcess >= 0)
	{
		for (int i = 0; i < BT.size(); i++)
		{
			//if BT gets over 100, a character will take their turn. (100 can be changed, but that is FFt default. Speed had a max of 30 in FFT.)
			//If multiple characters reach over 100 in a tick, then whoever has highest priority goes first
			if (BT[i] >= 100)
			{
				toTurn.push_back(i);
			}
		}

		while (!toTurn.empty()) //if characters are waiting to take their turn
		{
			int go = toTurn[0];
			for (int i = 0; i < toTurn.size(); i++) //set who should take their turn
			{
				if (characters[toTurn[i]]->GetPri() > characters[go]->GetPri())
				{
					//characters with highest priority should go first.
					//when a character takes a turn, their priority is reduced to 0, while everyone elses increments
					go = toTurn[i];
				}
			}

			//person at go gets their action 
			for (int i = 0; i < toTurn.size(); i++)
			{
				if (toTurn[i] == go)
				{
					toTurn.erase(toTurn.begin() + i);
					//remove this person from the turn orders
				}
			}
			characters[go]->Turn(); //chara takes their turn, BT resets
			BT[go] = 0;
			TurnsToProcess--;
			//every other character now gets an increase in priority
			for (int i = 0; i < characters.size(); i++)
			{
				if (i != go)
				{
					characters[i]->IncPri();
				}
			}
		}

		for (int i = 0; i < BT.size(); i++)
		{
			BT[i] += characters[i]->GetSpeed(); //increase the BT of a character by their speed
			
		}
	}


}
