#pragma once
#include <iostream>

class BaseActor
{
public:
	BaseActor();
	BaseActor(int damage, int hp, std::string name) : m_damage(damage), m_hp(hp), m_name(name) {};
public:
	inline std::string GetName() { return m_name; };
	inline int GetDamage() { return m_damage; };
	inline int GetHp() { return m_hp; };
	inline void SetHp(int hp) { m_hp - hp > 0 ? m_hp -= hp : m_hp = 0; };
	inline bool CheckDie() { return m_hp <= 0 ? true : false; };
protected:
	int m_damage;			// 공격력
	int m_hp;				// 체력
	std::string m_name;		// 이름
};