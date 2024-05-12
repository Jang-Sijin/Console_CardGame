#pragma once
#include "Define.h"
#include <iostream>

enum Turn
{
	UNKNOWN,
	INIT,	// 1��°
	SECOND,	// 2��°
	THIRD,	// 3��°
	FINAL	// 4��°
};

class GameFrameWork
{
public:
	GameFrameWork() : turn(Turn::INIT) {}
public:
	void virtual Start();
	void virtual Update();
private:
	//void SelectCard(Player player);
private:
	int turn{UNKNOWN};
	int total_betting_money{ 0 };
};

