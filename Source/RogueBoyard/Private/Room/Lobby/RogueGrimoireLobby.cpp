#include "Room/Lobby/RogueGrimoireLobby.h"

#include "Characters/RogueCharacter.h"
#include "Core/RogueGameMode.h"
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
	Grimoire->LastInputPos = Grimoire->GetActorLocation();
	Grimoire->DefaultPos = Grimoire->GetActorLocation();
}

void ARogueGrimoireLobby::EndRoom()
{
	if(!Grimoire->GetCurrentOwner())
	{
		ChosenPlayer = Cast<ARogueGameMode>(GetWorld()->GetAuthGameMode())->GetRandomCharacter()->PlayerIndex;
	}
	else
	{
		ChosenPlayer = 	Grimoire->GetCurrentOwner()->PlayerIndex;
	}
	Super::EndRoom();
}

