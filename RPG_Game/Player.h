#pragma once
#include "BaseActor.h"
#include "BaseSkill.h"

#define PLAYER_SKILL_MAX_COUNT 4

class Player : public BaseActor
{	
public:
	Player();
	Player(int damage, int hp, std::string name);
public:
	void PrintMonsterInfo();
	BaseSkill GetSkill(char get_key_down);
public:
	BaseActor base_actor;
private:
	BaseSkill base_skills[PLAYER_SKILL_MAX_COUNT];
};

