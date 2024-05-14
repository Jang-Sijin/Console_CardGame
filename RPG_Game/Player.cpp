#include "Player.h"

Player::Player() : base_actor(2, 100, "이즈리얼")
{
	base_skills[0] = BaseSkill(
		"신비한 화살", 
		"이즈리얼이 에너지 화살을 발사하여 처음 적중한 적에게 물리 피해를 입히고, 이즈리얼의 스킬 재사용 대기시간을 1.5초 감소시킵니다.",
		5);
	base_skills[1] = BaseSkill(
		"정수의 흐름",
		"이즈리얼이 마법의 구체를 발사해 처음으로 적중한 챔피언이나 구조물, 에픽 정글 몬스터에게 4초 동안 남아 있게 합니다.",
		10);
	base_skills[2] = BaseSkill(
		"비전 이동",
		"이즈리얼이 순간이동 후 가장 가까이에 있는 적에게 화살을 발사하여 마법 피해를 입힙니다.",
		3);
	base_skills[PLAYER_SKILL_MAX_COUNT - 1] = BaseSkill("정조준 일격",
		"이즈리얼이 거대한 에너지파를 발사하여 마법 피해를 입힙니다.",
		15);
}

Player::Player(int damage, int hp, std::string name) : base_actor(damage, hp, name)
{
	base_skills[0] = BaseSkill(
		"신비한 화살",
		"이즈리얼이 에너지 화살을 발사하여 처음 적중한 적에게 물리 피해를 입히고, 이즈리얼의 스킬 재사용 대기시간을 1.5초 감소시킵니다.",
		5);
	base_skills[1] = BaseSkill(
		"정수의 흐름",
		"이즈리얼이 마법의 구체를 발사해 처음으로 적중한 챔피언이나 구조물, 에픽 정글 몬스터에게 4초 동안 남아 있게 합니다.",
		10);
	base_skills[2] = BaseSkill(
		"비전 이동",
		"이즈리얼이 순간이동 후 가장 가까이에 있는 적에게 화살을 발사하여 마법 피해를 입힙니다.",
		3);
	base_skills[PLAYER_SKILL_MAX_COUNT - 1] = BaseSkill("정조준 일격",
		"이즈리얼이 거대한 에너지파를 발사하여 마법 피해를 입힙니다.",
		15);
}

void Player::PrintMonsterInfo()
{
	std::cout << "플레이어 이름: " << base_actor.GetName() << " / 플레이어 HP: " << base_actor.GetHp() << std::endl;
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
		std::cout << " 스킬명: " << base_skills[index].GetName() << " / 대미지: " << base_skills[index].GetDamage() << std::endl;
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