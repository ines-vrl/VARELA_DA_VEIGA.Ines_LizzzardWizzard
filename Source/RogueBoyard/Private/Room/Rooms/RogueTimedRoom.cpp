#include "Room/Rooms/RogueTimedRoom.h"

#include "Core/RogueGameMode.h"
#include "Kismet/GameplayStatics.h"


ARogueTimedRoom::ARogueTimedRoom()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARogueTimedRoom::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARogueTimedRoom::BeginRoom()
{
	bHasBegun = true;
}

void ARogueTimedRoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(bHasBegun)
	{
		ElapsedTime += DeltaTime;
		if (ElapsedTime >= Time)
		{
			Cast<ARogueGameMode>(GetWorld()->GetAuthGameMode())->EndBattleRoom();
		}
	}
}

