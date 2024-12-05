#include "Room/Lobby/RogueGrimoireLobby.h"

#include "Characters/RogueCharacter.h"
#include "Room/Lobby/RogueGrimoire.h"

ARogueGrimoireLobby::ARogueGrimoireLobby()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARogueGrimoireLobby::BeginPlay()
{
	Super::BeginPlay();
}

void ARogueGrimoireLobby::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARogueGrimoireLobby::BeginRoom()
{
	Super::BeginRoom();
}

void ARogueGrimoireLobby::EndRoom()
{
	ChosenPlayer = 	Grimoire->GetCurrentOwner()->PlayerIndex;

	Super::EndRoom();
}

