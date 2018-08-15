#include "Character.h"



Character::Character(int _speed, std::string _name)
{
	speed = _speed;
	name = _name;


	std::cout << name + " with Speed " + std::to_string(speed) + ". \n";
}


Character::~Character()
{
}
