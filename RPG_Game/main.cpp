#include "GameFrameWork.h"
using namespace std;

GameFrameWork g_GameFrameWork{};

int main()
{
	g_GameFrameWork.Start();
	
	while (g_GameFrameWork.GetGameState())
	{
		g_GameFrameWork.Update();
	}

	return 0;
}

//1. RPG���� �����
// �� 1.1. ����ü �������� ���͸� �����, ���ʹ� ���ݷ� �̸� ü���� ������ �ִ�.
//2. Player�� Class�� �����ϰ�
// �� 2-1. Player�� ���������� ���ݷ� �̸� ü��
//3. ���ʹ� �迭�� ������ �ϰ� Player�� �ϳ��� ��ü �� class�� �����մϴ�.
//3-1 ���ʹ� �迭�� �����ϴ� ��ſ� �����ϰ� �̾Ƽ� ������ �´�.
//3-2 �ѹ� ������ ���ʹ� ������ ���� �� ���� ���� ������ �ʴ´�.
//4. Player�� HP�� ��� �����ȴٸ� ������ ����ȴ�.
//5. �÷��̾�� QWER �� ����Ͽ� ��ų�� ����Ѵ�.