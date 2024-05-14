#include "Player.h"

Player::Player() : base_actor(2, 100, "�����")
{
	base_skills[0] = BaseSkill(
		"�ź��� ȭ��", 
		"������� ������ ȭ���� �߻��Ͽ� ó�� ������ ������ ���� ���ظ� ������, ������� ��ų ���� ���ð��� 1.5�� ���ҽ�ŵ�ϴ�.",
		5);
	base_skills[1] = BaseSkill(
		"������ �帧",
		"������� ������ ��ü�� �߻��� ó������ ������ è�Ǿ��̳� ������, ���� ���� ���Ϳ��� 4�� ���� ���� �ְ� �մϴ�.",
		10);
	base_skills[2] = BaseSkill(
		"���� �̵�",
		"������� �����̵� �� ���� �����̿� �ִ� ������ ȭ���� �߻��Ͽ� ���� ���ظ� �����ϴ�.",
		3);
	base_skills[PLAYER_SKILL_MAX_COUNT - 1] = BaseSkill("������ �ϰ�",
		"������� �Ŵ��� �������ĸ� �߻��Ͽ� ���� ���ظ� �����ϴ�.",
		15);
}

Player::Player(int damage, int hp, std::string name) : base_actor(damage, hp, name)
{
	base_skills[0] = BaseSkill(
		"�ź��� ȭ��",
		"������� ������ ȭ���� �߻��Ͽ� ó�� ������ ������ ���� ���ظ� ������, ������� ��ų ���� ���ð��� 1.5�� ���ҽ�ŵ�ϴ�.",
		5);
	base_skills[1] = BaseSkill(
		"������ �帧",
		"������� ������ ��ü�� �߻��� ó������ ������ è�Ǿ��̳� ������, ���� ���� ���Ϳ��� 4�� ���� ���� �ְ� �մϴ�.",
		10);
	base_skills[2] = BaseSkill(
		"���� �̵�",
		"������� �����̵� �� ���� �����̿� �ִ� ������ ȭ���� �߻��Ͽ� ���� ���ظ� �����ϴ�.",
		3);
	base_skills[PLAYER_SKILL_MAX_COUNT - 1] = BaseSkill("������ �ϰ�",
		"������� �Ŵ��� �������ĸ� �߻��Ͽ� ���� ���ظ� �����ϴ�.",
		15);
}

void Player::PrintMonsterInfo()
{
	std::cout << "�÷��̾� �̸�: " << base_actor.GetName() << " / �÷��̾� HP: " << base_actor.GetHp() << std::endl;
	for (int index = 0; index < PLAYER_SKILL_MAX_COUNT; ++index)
	{
		switch (index)
		{
		case 0:
			std::cout << "Q";
			break;
		case 1:
			std::cout << "W";
			break;
		case 2:
			std::cout << "E";
			break;
		case 3:
			std::cout << "R";
			break;
		default:
			std::cout << "PrintMonsterInfo: index error" << std::endl;
			break;
		}
		std::cout << " ��ų��: " << base_skills[index].GetName() << " / �����: " << base_skills[index].GetDamage() << std::endl;
	}
	std::cout << std::endl;
}

BaseSkill Player::GetSkill(char get_key_down)
{
	BaseSkill return_skill;

	switch (get_key_down)
	{
	case 'q':
	case 'Q':
		return_skill = base_skills[0];
		break;
	case 'w':
	case 'W':
		return_skill = base_skills[1];
		break;
	case 'e':
	case 'E':
		return_skill = base_skills[2];
		break;
	case 'r':
	case 'R':
		return_skill = base_skills[3];
		break;
	default:
		std::cout << "GetSkill: get_key_down input value error" << std::endl;
		break;
	}

	return return_skill;
}