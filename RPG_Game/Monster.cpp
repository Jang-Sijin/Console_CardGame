#include "Monster.h"

// int Monster::monster_index = 0;

Monster::Monster()
{

}

Monster::Monster(int damage, int hp, std::string name) : base_actor(damage, hp, name)
{

}

void Monster::PrintMonsterInfo()
{
	std::cout << "���� �̸�: " << base_actor.GetName() << " / ���� HP: " << base_actor.GetHp() << " / ���� �����: " << base_actor.GetDamage() << std::endl;
}