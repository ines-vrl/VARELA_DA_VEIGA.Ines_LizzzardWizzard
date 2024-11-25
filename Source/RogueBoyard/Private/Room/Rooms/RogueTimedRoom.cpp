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


void ARogueTimedRoom::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARogueTimedRoom::EndRoom()
{
	if(ARogueGameMode* GameMode = Cast<ARogueGameMode>(GetWorld()->GetAuthGameMode())) {
		GameMode->EndBattleRoom();
	}
	Super::EndRoom();
}

