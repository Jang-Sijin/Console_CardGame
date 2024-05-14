#pragma once
#include <random>
#include <iostream>
using namespace std;

#define MIN_COUNT_CARD_NUMBER 1
#define MAX_COUNT_CARD_NUMBER 10
#define MIN_COUNT_CARD_OPERATOR 1
#define MAX_COUNT_CARD_OPERATOR 4

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
    void ReStart();
    int SelectNumberCard(int index);                                        // ���� ī�� ����, ��ȯ �� 0�� ��� ���� �Ұ�
    int SelectOperatorCard(int index);                                      // ���� ī�� ����, ��ȯ �� 0�� ��� ���� �Ұ�
    void AllCardShuffle();                                                  // ��� ī�� ����
    void AllPrint();                                                        // ��� ī�� ���   
    inline OneCard<int>* GetNumberCard() { return card_number; };           // ��� ���� ī�� ��ȯ
    inline OneCard<char>* GetOperatorCard() { return card_operator; };      // ��� ���� ī�� ��ȯ
    template <typename T> void PrintCard(OneCard<T> card[], size_t count)   // Ư�� ī�� ���        
    {
        cout << "|";

        for (int index = 0; index < count; ++index)
        {
            if (card[index].selected == false)
                cout << " X |";
            else
                cout << card[index].value << "|";
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