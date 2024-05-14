#pragma once
#include "BaseActor.h"
#include <string>

#define MONSTER_MAX_COUNT 3

class Monster
{	
public:
	Monster();
	Monster(int damage, int hp, std::string name);
public:	
	void PrintMonsterInfo();
public:
	BaseActor base_actor;
};

