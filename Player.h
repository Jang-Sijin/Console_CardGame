#pragma once
#include "Define.h"

class Player
{
public:
	bool SelectGetCard(int turn, int get_card_number);
protected:
	char selected_operator_card[MAX_PLAYER_CARD_OPERATOR_COUNT];
	int selected_value_card[MAX_PLAYER_CARD_VALUE_COUNT];
	int money{ 10000 };
};