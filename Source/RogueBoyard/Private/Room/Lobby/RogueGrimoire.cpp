#include "Room/Lobby/RogueGrimoire.h"

ARogueGrimoire::ARogueGrimoire()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARogueGrimoire::BeginPlay()
{
	Super::BeginPlay();
}

void ARogueGrimoire::SwitchOwner(ARogueCharacter* NewOwner)
{
	CurrentOwner = NewOwner;
	OnGrimoireChangedOwnerEvent.Broadcast();
}

void ARogueGrimoire::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

