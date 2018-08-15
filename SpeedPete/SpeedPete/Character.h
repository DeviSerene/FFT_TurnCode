#pragma once
#include <string>
#include <iostream>

class Character
{
public:
	Character(int _speed, std::string _name);
	~Character();
	int GetSpeed() { return speed; }
	void IncPri() { priority++; }
	void Turn() { priority = 0; std::cout << name + " takes their turn. \n"; }
	int GetPri() { return priority; }

	std::string GetName() { return name; }

private:
	std::string name;
	int speed;
	int priority;
};

