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
	Card();                                                                 // 기본 생성자    
    void ReStart();
    int SelectNumberCard(int index);                                        // 숫자 카드 선택, 반환 값 0일 경우 선택 불가
    int SelectOperatorCard(int index);                                      // 연산 카드 선택, 반환 값 0일 경우 선택 불가
    void AllCardShuffle();                                                  // 모든 카드 셔플
    void AllPrint();                                                        // 모든 카드 출력   
    inline OneCard<int>* GetNumberCard() { return card_number; };           // 모든 숫자 카드 반환
    inline OneCard<char>* GetOperatorCard() { return card_operator; };      // 모든 연산 카드 반환
    template <typename T> void PrintCard(OneCard<T> card[], size_t count)   // 특정 카드 출력        
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
            cout << index + 1 << "번|";
        }

        cout << endl;
    }
private:
    template <typename T> void ShuffleCard(T card_type[], size_t count) // 카드 셔플
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
    OneCard<int> card_number[MAX_COUNT_CARD_NUMBER];     // 숫자 카드    
    OneCard<char> card_operator[MAX_COUNT_CARD_OPERATOR];// 연산 카드
};