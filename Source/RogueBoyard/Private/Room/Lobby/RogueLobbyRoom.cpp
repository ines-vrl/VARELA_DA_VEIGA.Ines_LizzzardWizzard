#include "Room/Lobby/RogueLobbyRoom.h"

#include "Core/RogueGameMode.h"

ARogueLobbyRoom::ARogueLobbyRoom()
{
	PrimaryActorTick.bCanEverTick = true;
}


void ARogueLobbyRoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MaxLobbyTime -= DeltaTime;
	if (MaxLobbyTime <= 0)
	{
		Cast<ARogueGameMode>(GetWorld()->GetAuthGameMode())->EndLobbyRoom();
	}

	if(bIsVoteActive)
	{
		ElapsedTime += DeltaTime;
	}
	
	if (ElapsedTime >= VoteTimer)
	{
		Cast<ARogueGameMode>(GetWorld()->GetAuthGameMode())->EndLobbyRoom();		
	}
}

void ARogueLobbyRoom::BeginPlay()
{
	Super::BeginPlay();
	VoteZone->OnPlayerEnterZoneEvent.AddUniqueDynamic(this, &ARogueLobbyRoom::PlayerEnteredVoteZone);
	VoteZone->OnAllPlayersLeaveZoneEvent.AddUniqueDynamic(this, &ARogueLobbyRoom::AllPlayerExitVoteZone);
}

void ARogueLobbyRoom::PlayerEnteredVoteZone()
{
	bIsVoteActive = true;
}

void ARogueLobbyRoom::AllPlayerExitVoteZone()
{
	bIsVoteActive = false;
	if (bShouldVoteTimerReset)
	{
		ElapsedTime = 0.0f;
	}
}

