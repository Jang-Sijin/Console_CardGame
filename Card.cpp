#include "Card.h"

Card::Card()
{
	for (int index = 0; index < MAX_COUNT_CARD_NUMBER; ++index)
	{
		card_number[index].value = index + 1;
		card_number[index].selected = false;
	}

	card_operator[0].value = '*';
	card_operator[1].value = '/';
	card_operator[2].value = '+';
	card_operator[3].value = '-';

	for (int index = 0; index < MAX_COUNT_CARD_OPERATOR; ++index)
	{
		card_operator[index].selected = false;
	}
}

int Card::SelectNumberCard(int index)
{
	if (card_number[index].selected == false)
		return card_number[index].value;
	else
		return 0;
}

void Card::AllCardShuffle()
{
	ShuffleCard(card_number, MAX_COUNT_CARD_NUMBER);
	ShuffleCard(card_operator, MAX_COUNT_CARD_OPERATOR);
}

void Card::AllPrint()
{
	cout << "[숫자 카드 인덱스 순으로 출력]" << endl;

	for (int index = 0; index < MAX_COUNT_CARD_NUMBER; ++index)
		cout << card_number[index].value << "\t";

	cout << endl << endl;

	cout << "[연산 카드 인덱스 순으로 출력]" << endl;

	for (int index = 0; index < MAX_COUNT_CARD_OPERATOR; ++index)
		cout << card_operator[index].value << "\t";

	cout << endl << endl;
}