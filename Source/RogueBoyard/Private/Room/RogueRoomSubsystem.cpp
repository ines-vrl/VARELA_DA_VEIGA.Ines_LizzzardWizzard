// Fill out your copyright notice in the Description page of Project Settings.



#include "Room/RogueRoomSubsystem.h"

#include "EngineUtils.h"
#include "Engine/LevelStreamingDynamic.h"
#include "Room/RogueRoomSettings.h"

void URogueRoomSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	const URogueRoomSettings* Settings = GetDefault<URogueRoomSettings>();
	TArray<TSoftObjectPtr<UWorld>> RealRooms;

	if(Settings->Rooms.Num()<=0 || Settings->Lobbies.Num()<=0)
	{
		return;
	}
	
	for(int i=0; i<Settings->NumberOfRooms; i++) {
		const int RndIndex = FMath::RandRange(0, Settings->Rooms.Num()-1);
		RealRooms.Add(Settings->Rooms[RndIndex]);
	}

	for(TSoftObjectPtr<UWorld> RealRoom : RealRooms) {
		const int RndIndex = FMath::RandRange(0, Settings->Lobbies.Num()-1);
		Rooms.Add(Settings->Lobbies[RndIndex]);
		Rooms.Add(RealRoom);
	}
}

void URogueRoomSubsystem::NextRoom() {
	ActiveRoomId++;
	LoadNextRoom();
	UnloadPreviousRoom();
	GEngine->AddOnScreenDebugMessage(1,1.0f,FColor::Red, "ActiveRoom :" + FString::SanitizeFloat(ActiveRoomId));
}

void URogueRoomSubsystem::InitFirstRoom() {
	const URogueRoomSettings* Settings = GetDefault<URogueRoomSettings>();
	LoadRoomAtPosition(Rooms[0], NextRoomPosition);
	NextRoomPosition += FVector(Settings->MaxRoomSize, 0, 0);
	LoadNextRoom();
}


void URogueRoomSubsystem::LoadRoomAtPosition(const TSoftObjectPtr<UWorld>& Room, const FVector& Position) {
	LastLoadedRoomId++;
	bool bSuccess;
	const FString RoomName = "Room " + FString::SanitizeFloat(LastLoadedRoomId);
	
	ULevelStreamingDynamic* NewRoom = ULevelStreamingDynamic::LoadLevelInstanceBySoftObjectPtr(
		GetWorld(),
		Room,
		Position,
		FRotator::ZeroRotator,
		bSuccess,
		RoomName);

	if(!bSuccess || !NewRoom) {
		GEngine->AddOnScreenDebugMessage(1,1.0f,FColor::Red, "Failed to load" + RoomName);
		return;
	}
	
	/*for(FActorIterator<ARogueRoom> RoomItr(NewRoom->GetLoadedLevel()->Actors); RoomItr; RoomItr++)
	{
		RoomManagers.Add(RoomItr);
	}*/
	
	NewRoom->SetShouldBeLoaded(true);
	LoadedRooms.Add(NewRoom);
	GEngine->AddOnScreenDebugMessage(1,1.0f,FColor::Red, "LastLoadedRoom :" + FString::SanitizeFloat(LastLoadedRoomId));
}

void URogueRoomSubsystem::UnloadRoom(ULevelStreamingDynamic* Room) {
	LoadedRooms.Remove(Room);
	Room->SetShouldBeLoaded(false);
}

void URogueRoomSubsystem::LoadNextRoom() {
	const URogueRoomSettings* Settings = GetDefault<URogueRoomSettings>();
	if(ActiveRoomId >= Rooms.Num()) {
		return;
	}
	LoadRoomAtPosition(Rooms[ActiveRoomId+1], NextRoomPosition);
	NextRoomPosition += FVector(Settings->MaxRoomSize, 0, 0);
}

void URogueRoomSubsystem::UnloadPreviousRoom() {
	UnloadRoom(LoadedRooms[0]);
}
