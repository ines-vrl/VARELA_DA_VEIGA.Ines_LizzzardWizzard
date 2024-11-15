#include "Room/Lobby/RogueGrimoireLobby.h"
#include "Room/Lobby/RogueGrimoire.h"

ARogueGrimoireLobby::ARogueGrimoireLobby()
{
	PrimaryActorTick.bCanEverTick = true;
	GrimoireSpawnPoint = CreateDefaultSubobject<USceneComponent>("GrimoireSpawnPoint");
}

void ARogueGrimoireLobby::BeginPlay()
{
	Super::BeginPlay();
	Grimoire->SetActorLocation(GrimoireSpawnPoint->GetComponentLocation());
}

void ARogueGrimoireLobby::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARogueGrimoireLobby::EndRoom()
{
	ChosenPlayer = 	Grimoire->GetCurrentOwner()->PlayerIndex;

	Super::EndRoom();
}

