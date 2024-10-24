#include "Room/RogueRoom.h"

#include "GameFramework/Character.h"

ARogueRoom::ARogueRoom()
{
	PrimaryActorTick.bCanEverTick = true;
	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>("Root");
	SpawnPoints.Add(CreateDefaultSubobject<USceneComponent>("P1Spawnpoint"));
	SpawnPoints.Add(CreateDefaultSubobject<USceneComponent>("P2Spawnpoint"));
	SpawnPoints.Add(CreateDefaultSubobject<USceneComponent>("P3Spawnpoint"));
	SpawnPoints.Add(CreateDefaultSubobject<USceneComponent>("P4Spawnpoint"));
	for (USceneComponent* SpawnPoint : SpawnPoints)
	{
		SpawnPoint->SetupAttachment(Root);
	}
}

void ARogueRoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARogueRoom::RoomEnter()
{
	if(EnterDoor)
	{
		EnterDoor->Open();
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(1,1.0f,FColor::Red, "EnterDoor Not Set");
	}
	OnRoomEnterEvent.Broadcast();
}

void ARogueRoom::PlacePlayers(TArray<ACharacter*> Players)
{
	for (int i=0; i<Players.Num(); i++)
	{
		Players[i]->SetActorLocation(SpawnPoints[i]->GetComponentLocation());
	}
}

void ARogueRoom::BeginRoom()
{
	if(EnterDoor)
	{
		EnterDoor->Close();
	}
	OnRoomBeginEvent.Broadcast();
}

void ARogueRoom::EndRoom()
{
	if (ExitDoor)
	{
		ExitDoor->Open();
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(1,1.0f,FColor::Red, "ExitDoor Not Set");
	}
	OnRoomEndEvent.Broadcast();
}

void ARogueRoom::RoomExit()
{
	if (ExitDoor)
	{
		ExitDoor->Close();
	}
	OnRoomExitEvent.Broadcast();
}

