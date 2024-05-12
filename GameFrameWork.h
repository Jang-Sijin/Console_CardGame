#pragma once
#include "Define.h"
#include <iostream>

enum Turn
{
	UNKNOWN,
	INIT,	// 1번째
	SECOND,	// 2번째
	THIRD,	// 3번째
	FINAL	// 4번째
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

