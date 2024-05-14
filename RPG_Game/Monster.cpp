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
	std::cout << "몬스터 이름: " << base_actor.GetName() << " / 몬스터 HP: " << base_actor.GetHp() << " / 몬스터 대미지: " << base_actor.GetDamage() << std::endl;
}