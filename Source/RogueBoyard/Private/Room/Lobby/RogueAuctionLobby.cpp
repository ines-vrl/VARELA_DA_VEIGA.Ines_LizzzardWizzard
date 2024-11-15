#include "Room/Lobby/RogueAuctionLobby.h"

#include "Room/Lobby/RogueAuctionUrn.h"

ARogueAuctionLobby::ARogueAuctionLobby()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARogueAuctionLobby::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARogueAuctionLobby::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARogueAuctionLobby::EndRoom()
{
	int MaxValue = -1;
	TArray<int> MaxUrns; 
	for (int i = 0; i < Urns.Num(); i++)
	{
		int Bid = Urns[i]->GetBids();
		if (Bid > MaxValue)
		{
			MaxValue = Bid;
			MaxUrns.Empty();
			MaxUrns.Add(i);
		}
		if (Bid == MaxValue)
		{
			MaxUrns.Add(i);
		}
	}
	if(MaxUrns.Num()>0)
	{
		int Rnd = FMath::RandRange(0, MaxUrns.Num()-1);
		ChosenPlayer = MaxUrns[Rnd];
	}
	else
	{
		ChosenPlayer = FMath::RandRange(0,3);
	}
	
	Super::EndRoom();
}

