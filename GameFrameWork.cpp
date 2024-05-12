#include "GameFrameWork.h"
using namespace std;

static Card g_Card{};
static User g_User{};
static Computer g_Computer{};

void GameFrameWork::Start()
{
	cout << "[게임을 시작합니다.]" << endl;

	//srand(time(NULL));

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

		cout << "Player 소지 금액: " << g_User.GetMoney() << "\t\t\t" << "Computer 소지 금액: " << g_Computer.GetMoney() << endl;

		switch (turn)
		{
		case Turn::INIT:
			// [1턴]
			g_Card.PrintCard(g_Card.GetNumberCard(), MAX_COUNT_CARD_NUMBER);
			cout << "선택 가능한 1~10번 카드를 선택해 주세요: ";
			// 플레이어가 숫자 카드 인덱스를 선택한다. (뽑은 카드 제외)
			if (!(cin >> input_index) || input_index < MIN_COUNT_CARD_NUMBER || input_index > MAX_COUNT_CARD_NUMBER)
			{
				cout << "잘못된 입력입니다." << endl;
				cin.clear(); // 스트림 상태 초기화
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 버퍼 비우기
				continue;
			}

			get_card_number = g_Card.SelectNumberCard(input_index);

			if (g_User.SelectGetCard(turn, get_card_number))
			{
				g_Card.PrintCard(g_Card.GetNumberCard(), MAX_COUNT_CARD_NUMBER);
			}
			else
			{
				cout << "이미 선택된 카드입니다. 다른 카드를 선택해 주세요." << endl;
			}
			cout << endl;
			
			// 배팅
			cout << "배팅할 금액을 입력하세요(-1 입력 시, Die): ";
			if (!(cin >> input_money))
			{
				cout << "잘못된 입력입니다." << endl;
				cin.clear(); // 스트림 상태 초기화
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 버퍼 비우기
				continue;
			}
			if (input_money == -1)
			{
				cout << "Die를 선택하여 게임을 다시 시작합니다." << endl << endl;
				cin.clear(); // 스트림 상태 초기화
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 버퍼 비우기
				turn = Turn::INIT;
				g_Card.ReStart();

				continue;
			}
			g_User.InputBettingMoney(input_money, total_betting_money); // 입력한 금액을 넘겨준다. // 소지하고 있는 금액보다 높으면 배팅 가능
			cout << endl;

			// 다음 턴으로 넘기기
			turn++;
			break;
		case Turn::SECOND:
			// [2턴]
			g_Card.PrintCard(g_Card.GetOperatorCard(), MAX_COUNT_CARD_OPERATOR);
			cout << "선택 가능한 1~4번 카드를 선택해 주세요: ";
			// 플레이어가 숫자 카드 인덱스를 선택한다. (뽑은 카드 제외)			
			if (!(cin >> input_index) || input_index < MIN_COUNT_CARD_OPERATOR || input_index > MAX_COUNT_CARD_OPERATOR)
			{
				cout << "잘못된 입력입니다." << endl;
				cin.clear(); // 스트림 상태 초기화
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 버퍼 비우기
				continue;
			}
			
			get_card_operator = g_Card.SelectOperatorCard(input_index);

			if (g_User.SelectGetCard(turn, get_card_operator))
			{
				g_Card.PrintCard(g_Card.GetOperatorCard(), MAX_COUNT_CARD_OPERATOR);
			}
			else
			{
				cout << "이미 선택된 카드입니다. 다른 카드를 선택해 주세요." << endl;
			}
			cout << endl;			
			
			// 배팅
			cout << "배팅할 금액을 입력하세요(-1 입력 시, Die): ";
			if (!(cin >> input_money))
			{
				cout << "잘못된 입력입니다." << endl;
				cin.clear(); // 스트림 상태 초기화
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 버퍼 비우기
				continue;
			}
			if (input_money == -1)
			{
				cout << "Die를 선택하여 게임을 다시 시작합니다." << endl << endl;
				cin.clear(); // 스트림 상태 초기화
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 버퍼 비우기
				
				turn = Turn::INIT;
				g_Card.ReStart();
				continue;
			}
			g_User.InputBettingMoney(input_money, total_betting_money); // 입력한 금액을 넘겨준다. // 소지하고 있는 금액보다 높으면 배팅 가능
			cout << endl;
			
			//g_Computer.SelectGetCard(turn, (rand() % 10) + 1);
			//g_Computer.InputBettingMoney(1000, total_betting_money);

			turn++;
			break;
		case Turn::THIRD:
			// [3턴]
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

			get_card_number = g_Card.SelectNumberCard(input_index);

			if (g_User.SelectGetCard(turn, get_card_number))
			{
				g_Card.PrintCard(g_Card.GetNumberCard(), MAX_COUNT_CARD_NUMBER);
			}
			else
			{
				cout << "이미 선택된 카드입니다. 다른 카드를 선택해 주세요." << endl;
			}
			cout << endl;
			
			// 배팅
			cout << "배팅할 금액을 입력하세요(-1 입력 시, Die): ";
			if (!(cin >> input_money))
			{
				cout << "잘못된 입력입니다." << endl;
				cin.clear(); // 스트림 상태 초기화
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 버퍼 비우기
				continue;
			}
			if (input_money == -1)
			{
				cout << "Die를 선택하여 게임을 다시 시작합니다." << endl << endl;
				cin.clear(); // 스트림 상태 초기화
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 버퍼 비우기
				
				turn = Turn::INIT;
				g_Card.ReStart();
				continue;
			}
			g_User.InputBettingMoney(input_money, total_betting_money); // 입력한 금액을 넘겨준다. // 소지하고 있는 금액보다 높으면 배팅 가능
			cout << endl;

			// 다음 턴으로 넘기기
			turn++;
			break;
		case Turn::FINAL:
			// [4턴]
			// 배팅
			cout << "배팅할 금액을 입력하세요(-1 입력 시, Die): ";
			if (!(cin >> input_money))
			{
				cout << "잘못된 입력입니다." << endl;
				cin.clear(); // 스트림 상태 초기화
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 버퍼 비우기
				continue;
			}
			if (input_money == -1)
			{
				cout << "Die를 선택하여 게임을 다시 시작합니다." << endl << endl;
				cin.clear(); // 스트림 상태 초기화
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 버퍼 비우기
				turn = Turn::INIT;
				g_Card.ReStart();
				continue;
			}
			g_User.InputBettingMoney(input_money, total_betting_money); // 입력한 금액을 넘겨준다. // 소지하고 있는 금액보다 높으면 배팅 가능

			cout << "총 획득 금액: " << total_betting_money << endl;
			cout << endl;
			// 최초 턴으로 이동
			turn = Turn::INIT;
			g_Card.ReStart();
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