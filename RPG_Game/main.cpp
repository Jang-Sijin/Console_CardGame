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

//1. RPG게임 만들기
// ㄴ 1.1. 구조체 형식으로 몬스터를 만들고, 몬스터는 공격력 이름 체력을 가지고 있다.
//2. Player는 Class로 관리하고
// ㄴ 2-1. Player도 마찬가지로 공격력 이름 체력
//3. 몬스터는 배열로 관리를 하고 Player는 하나의 객체 즉 class로 관리합니다.
//3-1 몬스터는 배열로 관리하는 대신에 랜덤하게 뽑아서 가지고 온다.
//3-2 한번 생성된 몬스터는 게임이 끝날 때 까지 값이 변하지 않는다.
//4. Player의 HP가 모두 소진된다면 게임은 종료된다.
//5. 플레이어는 QWER 을 사용하여 스킬을 사용한다.