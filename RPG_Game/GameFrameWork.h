#pragma once
#define NOMINMAX
#include <string>
#include <iostream>
#include <Windows.h>
#include "Monster.h"
#include "Player.h"

enum e_Battle_Message
{
	ePlayer,
	eMonster,
	MaxValue
};

class GameFrameWork
{
public:
	GameFrameWork() {};
public:
	void Start();
	void Update();
	inline bool GetGameState() { return is_play; };
private:    
	void GotoScreenXY(int x, int y);
	void ShuffleMonsterArray(Monster monster[], int size);
	void PrintBattleInfomation();
	void AttackPlayerToMonster();
	void AttackMonsterToPlayer();
	void AttackSystemMessage();
private:
	bool is_play{ true };
	int battle_monster_index{ 0 };	
	std::string battle_massage[e_Battle_Message::MaxValue];
};
