#include "GameFrameWork.h"

static Monster g_Monster[MONSTER_MAX_COUNT]{};
static Player g_Player{};

void GameFrameWork::Start()
{
	// Monster Data Init Settings
	for (int index = 0; index < MONSTER_MAX_COUNT; ++index)
	{
		g_Monster[index] = Monster(10, 20, "몬스터" + std::to_string(index));
	}

	// Generate Random Number
	srand(time(NULL));

	// Shuffle Monster Array Index
	ShuffleMonsterArray(g_Monster, MONSTER_MAX_COUNT);
}

void GameFrameWork::Update()
{	
	system("cls");

	// 1. 플레이어 Hp, Name, Skills 정보 출력 / 몬스터 Hp, Name 출력
	PrintBattleInfomation();
	AttackSystemMessage();

	// 2. 플레이어가 몬스터를 공격    
	AttackPlayerToMonster();

	// 3. 몬스터 공격
	AttackMonsterToPlayer();
}

void GameFrameWork::GotoScreenXY(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

	return;
}

// 배열을 랜덤하게 섞는 함수
void GameFrameWork::ShuffleMonsterArray(Monster monster[], int size)
{
	// 랜덤 시드를 설정합니다.
	srand(static_cast<unsigned int>(time(nullptr)));

	// 배열을 끝에서부터 시작하여 처음까지 반복합니다.
	for (int i = size - 1; i > 0; --i)
	{
		// 0부터 i까지의 랜덤한 인덱스를 선택합니다.
		int j = rand() % (i + 1);

		// arr[i]와 arr[j]를 교환합니다.
		Monster temp = monster[i];
		monster[i] = monster[j];
		monster[j] = temp;
	}

	return;
}

void GameFrameWork::PrintBattleInfomation()
{
	GotoScreenXY(0, 0);
	std::cout << "[전투 시작]" << std::endl;
	g_Player.PrintMonsterInfo();
	g_Monster[battle_monster_index].PrintMonsterInfo();
}

void GameFrameWork::AttackPlayerToMonster()
{
	char input{};
	int player_damage{};
	
	GotoScreenXY(0, 12);
	std::cout << std::endl << "[플레이어 공격 턴]" << std::endl;
	GotoScreenXY(0, 14);
	std::cout << "사용 스킬 입력: ";
	while (true)
	{
		std::cin >> input;

		if (!(input == 'q' || input == 'w' || input == 'e' || input == 'r'))
		{
			GotoScreenXY(0, 9);
			std::cout << "잘못된 입력입니다." << std::endl;
			std::cin.clear(); // 스트림 상태 초기화
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 버퍼 비우기	
			GotoScreenXY(16, 14);
			continue;
		}
		else
			break;
	}

	switch (input)
	{
	case 'q':	
	case 'w':	
	case 'e':	
	case 'r':
		player_damage = g_Player.GetSkill(input).GetDamage();
		break;
	}	

	//std::cout << "Player가 " << g_Monster[battle_monster_index].base_actor.GetName() << "에게 " << player_damage << "피해를 입힘." << std::endl;
	battle_massage[e_Battle_Message::ePlayer] = "Player가 " + g_Monster[battle_monster_index].base_actor.GetName() + "에게 " + std::to_string(player_damage) + "피해를 입힘.\n";
	g_Monster[battle_monster_index].base_actor.SetHp(player_damage);
	
	if (g_Monster[battle_monster_index].base_actor.CheckDie())
	{
		GotoScreenXY(0, 8);
		std::cout << g_Monster[battle_monster_index].base_actor.GetName() << "(이)가 사망했습니다... 남은 몬스터 수 " << MONSTER_MAX_COUNT - battle_monster_index - 1 << std::endl;
		Sleep(1500);		
		battle_monster_index++;		
	}

	if (battle_monster_index == MONSTER_MAX_COUNT)
	{
		system("cls");
		std::cout << "모든 몬스터를 처치했습니다... END" << std::endl;
		is_play = false; // 게임 상태: 종료
		exit(1);
	}
}

void GameFrameWork::AttackMonsterToPlayer()
{	
	std::cout << std::endl << "[몬스터 공격 턴]" << std::endl;

	int monster_damage{g_Monster[battle_monster_index].base_actor.GetDamage()};
			
	// std::cout << g_Monster[battle_monster_index].base_actor.GetName() << "이(가) Player에게 " << monster_damage << "피해를 입힘." << std::endl;
	battle_massage[e_Battle_Message::eMonster] = g_Monster[battle_monster_index].base_actor.GetName() + "이(가) Player에게 " + std::to_string(monster_damage) + "피해를 입힘.\n";
	g_Player.base_actor.SetHp(monster_damage);
	
	if (g_Player.base_actor.CheckDie())
	{
		system("cls");
		std::cout << "Player가 사망했습니다... END" << std::endl;
		is_play = false; // 게임 상태: 종료	
		exit(1);
	}
}

void GameFrameWork::AttackSystemMessage()
{
	GotoScreenXY(0, 10);
	for (int index = 0; index < e_Battle_Message::MaxValue; ++index)
	{		
		if(battle_massage[index].size() != 0)
			std::cout << "[" << index << "]. " << battle_massage[index];
	}
}