#pragma once
#include "Card.h"
#include "Player.h"
#include "Computer.h"
#include "User.h"

class GameFrameWork
{
public:
	GameFrameWork() : turn(Turn::INIT) {}
public:
	void virtual Start();
	void virtual Update();
private:
	void SelectCard(Player player);
private:
	int turn;
};

