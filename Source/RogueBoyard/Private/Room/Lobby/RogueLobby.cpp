#include "Room/Lobby/RogueLobby.h"

#include "Core/RogueGameMode.h"

ARogueLobby::ARogueLobby()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARogueLobby::BeginPlay()
{
	Super::BeginPlay();
}

void ARogueLobby::EndRoom()
{
	Cast<ARogueGameMode>(GetWorld()->GetAuthGameMode())->EndLobbyRoom();
}

void ARogueLobby::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

