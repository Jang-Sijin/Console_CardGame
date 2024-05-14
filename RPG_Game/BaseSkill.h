#pragma once
#include <iostream>

class BaseSkill
{
public:
	BaseSkill();
	BaseSkill(std::string name, std::string decription, int damage) : m_name(name), m_description(m_description), m_damage(damage) {};
public:
	inline std::string GetName() { return m_name; };
	inline std::string GetDescription() { return m_description; };
	inline int GetDamage() { return m_damage; };
protected:
	std::string m_name;			// 스킬 이름
	std::string m_description;	// 스킬 설명
	int m_damage;				// 스킬 대미지
};

