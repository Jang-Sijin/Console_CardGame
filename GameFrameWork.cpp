#include "GameFrameWork.h"
using namespace std;

static Card g_Card{};
static User g_User{};
static Computer g_Computer{};

void GameFrameWork::Start()
{
	cout << "[게임을 시작합니다.]" << endl;	

	srand(time(NULL));

	// g_Card.AllPrint();
	g_Card.AllCardShuffle();
	// g_Card.AllPrint();
	
	// g_Card.PrintCard(g_Card.GetNumberCard(), MAX_COUNT_CARD_NUMBER);	
	// g_Card.PrintCard(g_Card.GetOperatorCard(), MAX_COUNT_CARD_OPERATOR);
}

void GameFrameWork::Update()
{			

	while (true)
	{
		cout << turn << "번째 턴입니다." << endl;	

		int input_index{};
		int get_card_number{};
		char get_card_operator{};
		int input_money{};

		switch (turn)
		{
		case Turn::INIT:
			// [1턴]
			g_Card.PrintCard(g_Card.GetNumberCard(), MAX_COUNT_CARD_NUMBER);
			cout << "선택 가능한 1~10번 카드를 선택해 주세요: " << endl;
			// 플레이어가 숫자 카드 인덱스를 선택한다. (뽑은 카드 제외)			
			if (!(cin >> input_index) || input_index < MIN_COUNT_CARD_NUMBER || input_index > MAX_COUNT_CARD_NUMBER)
			{
				cout << "잘못된 입력입니다." << endl;
				cin.clear(); // 스트림 상태 초기화
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 버퍼 비우기
				continue;
			}
			// Debug -> 			
			//get_card_number = g_Card.SelectNumberCard(input_index);

			if (get_card_number)
			{
				cout << get_card_number << endl;
				g_User.SelectGetCard(turn, get_card_number);
			}
			else
			{
				cout << "이미 선택된 카드입니다. 다른 카드를 선택해 주세요." << endl;
			}
			// 다음 턴으로 넘기기
			turn++;
			break;
		case Turn::SECOND:
			// [3턴]
			g_Card.PrintCard(g_Card.GetOperatorCard(), MAX_COUNT_CARD_OPERATOR);
			// 플레이어가 숫자 카드 인덱스를 선택한다. (뽑은 카드 제외)			
			if (!(cin >> input_index) || input_index < MIN_COUNT_CARD_OPERATOR || input_index > MAX_COUNT_CARD_OPERATOR)
			{
				cout << "잘못된 입력입니다." << endl;
				cin.clear(); // 스트림 상태 초기화
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 버퍼 비우기
				continue;
			}
			// Debug -> 			
			// get_card_operator = g_Card.SelectOperatorCard(input_index);

			if (get_card_operator)
			{
				cout << get_card_operator << endl;
				g_User.SelectGetCard(turn, get_card_operator);
			}
			else
				cout << "이미 선택된 카드입니다. 다른 카드를 선택해 주세요." << endl;
			// 다음 턴으로 넘기기
			
			cout << "배팅할 금액을 입력하세요: ";			
			if (!(cin >> input_money))
			{
				cout << "잘못된 입력입니다." << endl;
				cin.clear(); // 스트림 상태 초기화
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 버퍼 비우기
				continue;
			}
			g_User.InputBettingMoney(input_money, total_betting_money); // 입력한 금액을 넘겨준다. // 소지하고 있는 금액보다 높으면 배팅 가능
				
			g_Computer.SelectGetCard(turn, (rand() % 10) + 1);
			g_Computer.InputBettingMoney(1000, total_betting_money);

			turn++;
			break;
		case Turn::THIRD:
			// [1턴]
			g_Card.PrintCard(g_Card.GetNumberCard(), MAX_COUNT_CARD_NUMBER);
			cout << "선택 가능한 1~10번 카드를 선택해 주세요: " << endl;
			// 플레이어가 숫자 카드 인덱스를 선택한다. (뽑은 카드 제외)			
			if (!(cin >> input_index) || input_index < MIN_COUNT_CARD_NUMBER || input_index > MAX_COUNT_CARD_NUMBER)
			{
				cout << "잘못된 입력입니다." << endl;
				cin.clear(); // 스트림 상태 초기화
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 버퍼 비우기
				continue;
			}
			// Debug -> 			
			// get_card_number = g_Card.SelectNumberCard(input_index);

			if (get_card_number)
			{
				cout << get_card_number << endl;
				g_User.SelectGetCard(turn, get_card_number);
			}
			else
			{
				cout << "이미 선택된 카드입니다. 다른 카드를 선택해 주세요." << endl;
			}
			// 다음 턴으로 넘기기
			turn++;
			break;
		case Turn::FINAL:

			// 최초 턴으로 이동
			turn = Turn::INIT;
			break;
		default:
			cout << "SelectCard 중 turn 값 오류 발생" << endl;
		}		
		// 플레이어가 숫자 카드를 획득한다.
		// 플레이어가 뽑은 숫자 카드의 번호를 출력한다.		
		// 플레이어가 배팅할 금액을 입력한다.

		// 컴퓨터가 숫자 카드 인덱스를 선택한다. (뽑은 카드 제외)
		// 컴퓨터가 숫자 카드를 획득한다.
		// 컴퓨터가 배팅할 금액을 입력한다. (랜덤 or 인공지능)

		// [2턴]
		// 플레이어가 연산 카드 인덱스를 선택한다. (뽑은 카드 제외)
		//g_Card.SelectOperatorCard(int index);		
		// 플레이어가 연산 카드를 획득한다.
		// 플레이어가 뽑은 연산 카드의 기호를 출력한다.
		// 플레이어가 Batting/Die를 선택한다.
		// 플레이어가 배팅할 금액을 입력한다.

		// 컴퓨터가 연산 카드 인덱스를 선택한다. (뽑은 카드 제외)
		// 컴퓨터가 연산 카드를 획득한다.
		// 컴퓨터가 Batting/Die를 선택한다.
		// 컴퓨터가 배팅할 금액을 입력한다. (랜덤 or 인공지능)

		// [3턴]
		// 플레이어가 숫자 카드 인덱스를 선택한다. (뽑은 카드 제외)
		// 플레이어가 숫자 카드를 획득한다.
		// 플레이어가 뽑은 숫자 카드의 번호를 출력한다.
		// 플레이어가 Batting/Die를 선택한다.
		// 플레이어가 배팅할 금액을 입력한다.

		// 컴퓨터가 숫자 카드 인덱스를 선택한다. (뽑은 카드 제외)
		// 컴퓨터가 숫자 카드를 획득한다.
		// 컴퓨터가 Batting/Die를 선택한다.
		// 컴퓨터가 배팅할 금액을 입력한다. (랜덤 or 인공지능)

		// [4턴]
		// 플레이어가 Batting/Die를 선택한다.
		// 플레이어가 배팅할 금액을 입력한다.
		// 컴퓨터가 Batting/Die를 선택한다.
		// 컴퓨터가 배팅할 금액을 입력한다. (랜덤 or 인공지능)

		// [결과]
		// 플레이어/컴퓨터 승패 여부를 출력한다.
		// 배팅한 총 금액을 승자에게 지급한다.
		// 플레이어/컴퓨터 중 총 소지 금액의 10%가 10원 이하일 경우 게임을 강제 종료한다.
	}
}

//void GameFrameWork::SelectCard(Player player)
//{
//
//	return;
//}