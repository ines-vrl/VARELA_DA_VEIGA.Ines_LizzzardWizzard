#include "Room/Lobby/RogueRandomLobby.h"


ARogueRandomLobby::ARogueRandomLobby()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARogueRandomLobby::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARogueRandomLobby::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARogueRandomLobby::EndRoom()
{
	ChosenPlayer = FMath::RandRange(0,3);
	Super::EndRoom();
}

