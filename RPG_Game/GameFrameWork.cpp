#include "GameFrameWork.h"

static Monster g_Monster[MONSTER_MAX_COUNT]{};
static Player g_Player{};

void GameFrameWork::Start()
{
	// Monster Data Init Settings
	for (int index = 0; index < MONSTER_MAX_COUNT; ++index)
	{
		g_Monster[index] = Monster(10, 20, "����" + std::to_string(index));
	}

	// Generate Random Number
	srand(time(NULL));

	// Shuffle Monster Array Index
	ShuffleMonsterArray(g_Monster, MONSTER_MAX_COUNT);
}

void GameFrameWork::Update()
{	
	system("cls");

	// 1. �÷��̾� Hp, Name, Skills ���� ��� / ���� Hp, Name ���
	PrintBattleInfomation();
	AttackSystemMessage();

	// 2. �÷��̾ ���͸� ����    
	AttackPlayerToMonster();

	// 3. ���� ����
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

// �迭�� �����ϰ� ���� �Լ�
void GameFrameWork::ShuffleMonsterArray(Monster monster[], int size)
{
	// ���� �õ带 �����մϴ�.
	srand(static_cast<unsigned int>(time(nullptr)));

	// �迭�� ���������� �����Ͽ� ó������ �ݺ��մϴ�.
	for (int i = size - 1; i > 0; --i)
	{
		// 0���� i������ ������ �ε����� �����մϴ�.
		int j = rand() % (i + 1);

		// arr[i]�� arr[j]�� ��ȯ�մϴ�.
		Monster temp = monster[i];
		monster[i] = monster[j];
		monster[j] = temp;
	}

	return;
}

void GameFrameWork::PrintBattleInfomation()
{
	GotoScreenXY(0, 0);
	std::cout << "[���� ����]" << std::endl;
	g_Player.PrintMonsterInfo();
	g_Monster[battle_monster_index].PrintMonsterInfo();
}

void GameFrameWork::AttackPlayerToMonster()
{
	char input{};
	int player_damage{};
	
	GotoScreenXY(0, 12);
	std::cout << std::endl << "[�÷��̾� ���� ��]" << std::endl;
	GotoScreenXY(0, 14);
	std::cout << "��� ��ų �Է�: ";
	while (true)
	{
		std::cin >> input;

		if (!(input == 'q' || input == 'w' || input == 'e' || input == 'r'))
		{
			GotoScreenXY(0, 9);
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
			std::cin.clear(); // ��Ʈ�� ���� �ʱ�ȭ
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���� ����	
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

	//std::cout << "Player�� " << g_Monster[battle_monster_index].base_actor.GetName() << "���� " << player_damage << "���ظ� ����." << std::endl;
	battle_massage[e_Battle_Message::ePlayer] = "Player�� " + g_Monster[battle_monster_index].base_actor.GetName() + "���� " + std::to_string(player_damage) + "���ظ� ����.\n";
	g_Monster[battle_monster_index].base_actor.SetHp(player_damage);
	
	if (g_Monster[battle_monster_index].base_actor.CheckDie())
	{
		GotoScreenXY(0, 8);
		std::cout << g_Monster[battle_monster_index].base_actor.GetName() << "(��)�� ����߽��ϴ�... ���� ���� �� " << MONSTER_MAX_COUNT - battle_monster_index - 1 << std::endl;
		Sleep(1500);		
		battle_monster_index++;		
	}

	if (battle_monster_index == MONSTER_MAX_COUNT)
	{
		system("cls");
		std::cout << "��� ���͸� óġ�߽��ϴ�... END" << std::endl;
		is_play = false; // ���� ����: ����
		exit(1);
	}
}

void GameFrameWork::AttackMonsterToPlayer()
{	
	std::cout << std::endl << "[���� ���� ��]" << std::endl;

	int monster_damage{g_Monster[battle_monster_index].base_actor.GetDamage()};
			
	// std::cout << g_Monster[battle_monster_index].base_actor.GetName() << "��(��) Player���� " << monster_damage << "���ظ� ����." << std::endl;
	battle_massage[e_Battle_Message::eMonster] = g_Monster[battle_monster_index].base_actor.GetName() + "��(��) Player���� " + std::to_string(monster_damage) + "���ظ� ����.\n";
	g_Player.base_actor.SetHp(monster_damage);
	
	if (g_Player.base_actor.CheckDie())
	{
		system("cls");
		std::cout << "Player�� ����߽��ϴ�... END" << std::endl;
		is_play = false; // ���� ����: ����	
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