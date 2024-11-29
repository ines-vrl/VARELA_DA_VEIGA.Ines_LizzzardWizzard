#include "Room/Rooms/RogueRiddleRoom.h"

#include "Core/RogueGameMode.h"

ARogueRiddleRoom::ARogueRiddleRoom()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARogueRiddleRoom::BeginPlay()
{
	Super::BeginPlay();
}

void ARogueRiddleRoom::EndRoom()
{
	if(ARogueGameMode* GameMode = Cast<ARogueGameMode>(GetWorld()->GetAuthGameMode())) {
		GameMode->EndBattleRoom();
	}
	Super::EndRoom();
}

void ARogueRiddleRoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(ThingsToValidate <= 0)
	{
		if(ARogueGameMode* GameMode = Cast<ARogueGameMode>(GetWorld()->GetAuthGameMode())) {
			GameMode->EndBattleRoom();
		}
	}
}

