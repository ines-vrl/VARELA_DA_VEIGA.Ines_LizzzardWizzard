#include "Room/Lobby/RogueVoteZone.h"

#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"


ARogueVoteZone::ARogueVoteZone()
{
	PrimaryActorTick.bCanEverTick = false;
	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>("Root");
	VoteZones.Add(CreateDefaultSubobject<UBoxComponent>("VoteZoneP1"));
	VoteZones.Add(CreateDefaultSubobject<UBoxComponent>("VoteZoneP2"));
	VoteZones.Add(CreateDefaultSubobject<UBoxComponent>("VoteZoneP3"));
	VoteZones.Add(CreateDefaultSubobject<UBoxComponent>("VoteZoneP4"));
	for (UBoxComponent* Zone : VoteZones)
	{
		Zone->SetupAttachment(Root);
	}
	VoteZones[0]->ShapeColor = FColor::Red;
	VoteZones[1]->ShapeColor = FColor::Blue;
	VoteZones[2]->ShapeColor = FColor::Green;
	VoteZones[3]->ShapeColor = FColor::Yellow;
}

void ARogueVoteZone::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	VoteZones[0]->SetRelativeLocation(FVector(ZoneSize/2, ZoneSize/2, ZoneHeight/2));
	VoteZones[1]->SetRelativeLocation(FVector(ZoneSize/2, -ZoneSize/2, ZoneHeight/2));
	VoteZones[2]->SetRelativeLocation(FVector(-ZoneSize/2, ZoneSize/2, ZoneHeight/2));
	VoteZones[3]->SetRelativeLocation(FVector(-ZoneSize/2, -ZoneSize/2, ZoneHeight/2));

	VoteZones[0]->SetBoxExtent(FVector(ZoneSize/2, ZoneSize/2, ZoneHeight/2));
	VoteZones[1]->SetBoxExtent(FVector(ZoneSize/2, ZoneSize/2, ZoneHeight/2));
	VoteZones[2]->SetBoxExtent(FVector(ZoneSize/2, ZoneSize/2, ZoneHeight/2));
	VoteZones[3]->SetBoxExtent(FVector(ZoneSize/2, ZoneSize/2, ZoneHeight/2));
}

int ARogueVoteZone::GetVoteResults(const int LastMjIndex)
{
	// Depouillement aka comptage des zones
	TArray<int> Votes;
	for (int i=0; i<VoteZones.Num(); i++)
	{
		if(i == LastMjIndex) // La Zone du Mj ne compte pas
		{
			Votes.Add(-1);
		}
		else
		{
			TArray<AActor*> Actors;
			VoteZones[i]->GetOverlappingActors(Actors, ACharacter::StaticClass());
			Votes.Add(Actors.Num());
		}
		
	}

	// Qui a remporté l'election
	TArray<int> MaxIndex;
	int MaxVote = -1;
	for (int i=0; i<Votes.Num(); i++)
	{
		if(MaxVote<Votes[i])
		{
			MaxVote = Votes[i];
			MaxIndex.Empty();
			MaxIndex.Add(i);
		}
		else if (MaxVote == Votes[i])
		{
			MaxIndex.Add(i);
		}
	}

	if(MaxIndex.Num() == 1)
	{
		return MaxIndex[0];
	}

	//Gestion des egalités
	int RndIndex = FMath::RandRange(0, MaxIndex.Num()-1);
	return MaxIndex[RndIndex];
}




