#pragma once
#define NOMINMAX
#include "Define.h"
#include <iostream>
#include <windows.h>

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
	void GotoScreenXY(int x, int y);
private:
	int turn{UNKNOWN};
	int total_betting_money{ 0 };
};

