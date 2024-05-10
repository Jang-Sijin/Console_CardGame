#include "Define.h"

static GameFrameWork g_GameFrameWoke{};

int main()
{	
	g_GameFrameWoke.Start();
	g_GameFrameWoke.Update();

	return 0;
}