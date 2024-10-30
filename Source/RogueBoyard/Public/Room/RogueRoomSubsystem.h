// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RogueRoom.h"
#include "Engine/LevelStreamingDynamic.h"
#include "Subsystems/WorldSubsystem.h"
#include "RogueRoomSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class ROGUEBOYARD_API URogueRoomSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
public:
	UFUNCTION(BlueprintCallable)
	void NextRoom();
	void InitFirstRoom();
	UPROPERTY(BlueprintReadOnly)
	int ActiveRoomId = 0;

private:
	TArray<TSoftObjectPtr<UWorld>> Rooms;
	UPROPERTY()
	TArray<ULevelStreamingDynamic*> LoadedRooms;
	int LastLoadedRoomId = -1;
	FVector NextRoomPosition = FVector(0,0,0);
	
	void LoadRoomAtPosition(const TSoftObjectPtr<UWorld>& Room, const FVector& Position);
	void UnloadRoom(ULevelStreamingDynamic* Room);
	void LoadNextRoom();
	void UnloadPreviousRoom();
};
