#pragma once
#include "GameFrameWork.h"
#include <iostream>

#define MIN_COUNT_CARD_NUMBER 1
#define MAX_COUNT_CARD_NUMBER 10
#define MIN_COUNT_CARD_OPERATOR 1
#define MAX_COUNT_CARD_OPERATOR 4

#define MAX_PLAYER_CARD_OPERATOR_COUNT 1
#define MAX_PLAYER_CARD_VALUE_COUNT 2

enum Turn
{
	UNKNOWN,
	INIT,	// 1��°
	SECOND,	// 2��°
	THIRD,	// 3��°
	FINAL	// 4��°
};