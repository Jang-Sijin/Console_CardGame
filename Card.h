#pragma once

#include "Define.h"
#include <random>
using namespace std;

template <typename T>
struct OneCard
{
public:
    T value;
    bool selected{ false };
};

class Card
{
public:
	Card();                                                                 // �⺻ ������    
    int SelectNumberCard(int index);                                        // ���� ī�� ����, ��ȯ 0�Ͻ� ���� �Ұ� index
    void AllCardShuffle();                                                  // ��� ī�� ����
    void AllPrint();                                                        // ��� ī�� ���   
    inline OneCard<int>* GetNumberCard() { return card_number; };           // ��� ���� ī�� ��ȯ
    inline OneCard<char>* GetOperatorCard() { return card_operator; };      // ��� ���� ī�� ��ȯ
    template <typename T> void PrintCard(OneCard<T> card[], size_t count)   // Ư�� ī�� ���        
    {
        cout << "|";

        for (int index = 0; index < count; ++index)
        {
            if (card->selected == false)
                cout << " X |";
            else
                cout << card->value << "|";
        }
        cout << endl;

        cout << "|";
        for (int index = 0; index < count; ++index)
        {
            cout << index + 1 << "��|";
        }

        cout << endl;
    }
private:
    template <typename T> void ShuffleCard(T card_type[], size_t count) // ī�� ����
    {
        random_device rd;
        mt19937 mt(rd());

        for (int index = count - 1; index > 0; --index)
        {
            uniform_int_distribution<int> uid(0, index);
            int random_value = uid(mt);

            T temp = card_type[index];
            card_type[index] = card_type[random_value];
            card_type[random_value] = temp;
        }
    }
private:
    OneCard<int> card_number[MAX_COUNT_CARD_NUMBER];     // ���� ī��    
    OneCard<char> card_operator[MAX_COUNT_CARD_OPERATOR];// ���� ī��
};