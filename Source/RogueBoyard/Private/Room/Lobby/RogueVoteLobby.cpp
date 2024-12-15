#include "Room/Lobby/RogueVoteLobby.h"

#include "Core/RogueGameMode.h"

ARogueVoteLobby::ARogueVoteLobby()
{
	PrimaryActorTick.bCanEverTick = true;
}


void ARogueVoteLobby::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(bIsVoteActive)
	{
		ElapsedTime += DeltaTime;
	}
	if (ElapsedTime >= VoteTimer && !bHasVoted)
	{
		bHasVoted = true;
		EndRoom();		
	}
}

void ARogueVoteLobby::EndRoom()
{
	ChosenPlayer = VoteZone->GetVoteResults(-1);
	Super::EndRoom();
}

void ARogueVoteLobby::BeginPlay()
{
	Super::BeginPlay();
	//TODO Add Guard
	VoteZone->OnPlayerEnterZoneEvent.AddUniqueDynamic(this, &ARogueVoteLobby::PlayerEnteredVoteZone);
	VoteZone->OnAllPlayersLeaveZoneEvent.AddUniqueDynamic(this, &ARogueVoteLobby::AllPlayerExitVoteZone);
}

void ARogueVoteLobby::PlayerEnteredVoteZone()
{
	bIsVoteActive = true;
}

void ARogueVoteLobby::AllPlayerExitVoteZone()
{
	bIsVoteActive = false;
	if (bShouldVoteTimerReset)
	{
		ElapsedTime = 0.0f;
	}
}

