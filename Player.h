#pragma once

#define MAX_PLAYER_CARD_OPERATOR_COUNT 1
#define MAX_PLAYER_CARD_VALUE_COUNT 2
#define INIT_MONEY 10000 // 초기 소지한 배팅 금액

class Player
{
public:
	Player() {};
public:
	virtual bool SelectGetCard(int turn, int get_card_number);
	virtual bool InputBettingMoney(int betting_money, int& total_betting_money);
protected:
	char selected_operator_card[MAX_PLAYER_CARD_OPERATOR_COUNT];
	int selected_value_card[MAX_PLAYER_CARD_VALUE_COUNT];
	int money{ INIT_MONEY };
};

