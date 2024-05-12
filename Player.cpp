#include "Player.h"
#include <iostream>
using namespace std;

bool Player::SelectGetCard(int turn, int get_card_number)
{
	switch (turn)
	{
	case 1:
		selected_value_card[0] = get_card_number;
		break;
	case 2:
		selected_operator_card[0] = get_card_number;
		break;
	case 3:
		selected_value_card[1] = get_card_number;
		break;
	default:
		return false;
	}

	return true;
}

bool Player::InputBettingMoney(int betting_money, int& total_betting_money)
{
	if (money >= betting_money)
	{
		cout << betting_money << "원 배팅했습니다." << endl;
		total_betting_money += betting_money;
		money -= betting_money;
		return true;
	}
	else
	{
		cout << "현재 " << money << "원 소지하여 배팅 금액이 부족합니다." << endl;
		return false;
	}
}