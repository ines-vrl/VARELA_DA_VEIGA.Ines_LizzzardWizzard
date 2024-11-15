#include "Room/Rooms/RogueTimedRoom.h"

#include "Core/RogueGameMode.h"
#include "Kismet/GameplayStatics.h"


ARogueTimedRoom::ARogueTimedRoom()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARogueTimedRoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARogueTimedRoom::EndRoom()
{
	Cast<ARogueGameMode>(GetWorld()->GetAuthGameMode())->EndBattleRoom();
	Super::EndRoom();
}

void ARogueTimedRoom::BeginPlay()
{
	Super::BeginPlay();
	
}

