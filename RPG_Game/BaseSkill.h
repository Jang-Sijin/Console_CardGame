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
	std::string m_name;			// ��ų �̸�
	std::string m_description;	// ��ų ����
	int m_damage;				// ��ų �����
};

