#include "GameFrameWork.h"

static Card g_Card{};
static User g_User{};
static Computer g_Computer{};

void GameFrameWork::Start()
{
	cout << "[������ �����մϴ�.]" << endl;	

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
		cout << turn << "��° ���Դϴ�." << endl;
		g_Card.PrintCard(g_Card.GetNumberCard(), MAX_COUNT_CARD_NUMBER);

		switch (turn)
		{
		case Turn::INIT:
			// [1��]
			cout << "���� ������ 1~10�� ī�带 ������ �ּ���: " << endl;

			// ���� ������ �ѱ��
			turn++;
			break;
		case Turn::SECOND:

			// ���� ������ �ѱ��
			turn++;
			break;
		case Turn::THIRD:

			// ���� ������ �ѱ��
			turn++;
			break;
		case Turn::FINAL:

			// ���� ������ �̵�
			turn = Turn::INIT;
			break;
		default:
			cout << "SelectCard �� turn �� ���� �߻�" << endl;
		}
		
		// �÷��̾ ���� ī�� �ε����� �����Ѵ�. (���� ī�� ����)
		int input_index{};
		if (!(cin >> input_index) || input_index < MIN_COUNT_CARD_NUMBER || input_index < MAX_COUNT_CARD_NUMBER)
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
			cin.clear(); // ��Ʈ�� ���� �ʱ�ȭ
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���� ����
			continue;
		}
		int get_card_number = g_Card.SelectNumberCard(input_index);

		if (!get_card_number)
			SelectGetCard(turn, get_card_number);
		else
			cout << "�̹� ���õ� ī���Դϴ�. �ٸ� ī�带 ������ �ּ���." << endl;
		// �÷��̾ ���� ī�带 ȹ���Ѵ�.
		// �÷��̾ ���� ���� ī���� ��ȣ�� ����Ѵ�.		
		// �÷��̾ ������ �ݾ��� �Է��Ѵ�.

		// ��ǻ�Ͱ� ���� ī�� �ε����� �����Ѵ�. (���� ī�� ����)
		// ��ǻ�Ͱ� ���� ī�带 ȹ���Ѵ�.
		// ��ǻ�Ͱ� ������ �ݾ��� �Է��Ѵ�. (���� or �ΰ�����)

		// [2��]
		// �÷��̾ ���� ī�� �ε����� �����Ѵ�. (���� ī�� ����)
		//g_Card.SelectOperatorCard(int index);		
		// �÷��̾ ���� ī�带 ȹ���Ѵ�.
		// �÷��̾ ���� ���� ī���� ��ȣ�� ����Ѵ�.
		// �÷��̾ Batting/Die�� �����Ѵ�.
		// �÷��̾ ������ �ݾ��� �Է��Ѵ�.

		// ��ǻ�Ͱ� ���� ī�� �ε����� �����Ѵ�. (���� ī�� ����)
		// ��ǻ�Ͱ� ���� ī�带 ȹ���Ѵ�.
		// ��ǻ�Ͱ� Batting/Die�� �����Ѵ�.
		// ��ǻ�Ͱ� ������ �ݾ��� �Է��Ѵ�. (���� or �ΰ�����)

		// [3��]
		// �÷��̾ ���� ī�� �ε����� �����Ѵ�. (���� ī�� ����)
		// �÷��̾ ���� ī�带 ȹ���Ѵ�.
		// �÷��̾ ���� ���� ī���� ��ȣ�� ����Ѵ�.
		// �÷��̾ Batting/Die�� �����Ѵ�.
		// �÷��̾ ������ �ݾ��� �Է��Ѵ�.

		// ��ǻ�Ͱ� ���� ī�� �ε����� �����Ѵ�. (���� ī�� ����)
		// ��ǻ�Ͱ� ���� ī�带 ȹ���Ѵ�.
		// ��ǻ�Ͱ� Batting/Die�� �����Ѵ�.
		// ��ǻ�Ͱ� ������ �ݾ��� �Է��Ѵ�. (���� or �ΰ�����)

		// [4��]
		// �÷��̾ Batting/Die�� �����Ѵ�.
		// �÷��̾ ������ �ݾ��� �Է��Ѵ�.
		// ��ǻ�Ͱ� Batting/Die�� �����Ѵ�.
		// ��ǻ�Ͱ� ������ �ݾ��� �Է��Ѵ�. (���� or �ΰ�����)

		// [���]
		// �÷��̾�/��ǻ�� ���� ���θ� ����Ѵ�.
		// ������ �� �ݾ��� ���ڿ��� �����Ѵ�.
		// �÷��̾�/��ǻ�� �� �� ���� �ݾ��� 10%�� 10�� ������ ��� ������ ���� �����Ѵ�.
	}
}

void GameFrameWork::SelectCard(Player player)
{

	return;
}