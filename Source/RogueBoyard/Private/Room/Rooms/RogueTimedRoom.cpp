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
	if(MaxRoomTime <= 0) bLizardsHasWon = true;

	Super::EndRoom();
}

void ARogueTimedRoom::RoomExit() {
	if(ARogueGameMode* GameMode = Cast<ARogueGameMode>(GetWorld()->GetAuthGameMode())) {
        GameMode->EndBattleRoom();
    }
	Super::RoomExit();
}

