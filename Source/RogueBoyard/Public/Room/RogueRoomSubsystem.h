// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
	
private:
	TArray<TSoftObjectPtr<UWorld>> Rooms;
	TArray<FLevelRef> ActiveLevels;
	int NextUUID = 1;

	void LoadStreamingLevelAtPosition(FVector3d Position);

	void LoadStreamingLevel(FName LevelName, FLevelFinishedLoading &&Callback);
	void UnloadStreamingLevel(FName LevelName);

	UFUNCTION()
	void OnLoadStreamLevelFinished(int Linkage);
	UFUNCTION()
	void OnUnloadStreamLevelFinished(int Linkage);
};
