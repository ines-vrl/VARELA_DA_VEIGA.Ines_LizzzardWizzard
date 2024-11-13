#include "Core/RogueSingleRoomGameMode.h"

void ARogueSingleRoomGameMode::BeginPlay()
{
	Super::BeginPlay();
	StartBattleRoom();
}

void ARogueSingleRoomGameMode::InitFirstRoom()
{
	int i = 1+1;
}
