// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelStreamingDynamic.h"
#include "Subsystems/WorldSubsystem.h"
#include "RogueRoomSubsystem.generated.h"

DECLARE_DELEGATE_OneParam(FLevelFinishedLoading, FName);
DECLARE_DELEGATE_OneParam(FLevelFinishedUnloading, FName);

struct FLevelRef
{
	FName LevelName;
	int Linkage;
	int RefCount = 0;
	bool bIsActive;
	bool bWaitingForLevel;
	bool bVisible;
	FLevelFinishedLoading LoadEvent;
	FLevelFinishedUnloading UnloadEvent;
};

/**
 * 
 */
UCLASS()
class ROGUEBOYARD_API URogueRoomSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	void NextRoom();
	void InitFirstRoom();
	
private:
	TArray<TSoftObjectPtr<UWorld>> Rooms;
	UPROPERTY()
	TArray<ULevelStreamingDynamic*> LoadedRooms;
	int ActiveRoomId = 0;
	int LastLoadedRoomId = -1;
	FVector NextRoomPosition = FVector(0,0,0);
	
	void LoadRoomAtPosition(const TSoftObjectPtr<UWorld>& Room, const FVector& Position);
	void UnloadRoom(ULevelStreamingDynamic* Room);
	void LoadNextRoom();
	void UnloadPreviousRoom();
};
