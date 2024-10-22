// Fill out your copyright notice in the Description page of Project Settings.


#include "Room/RogueRoomSubsystem.h"

void URogueRoomSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void URogueRoomSubsystem::LoadStreamingLevelAtPosition(FVector3d Position)
{
}

void URogueRoomSubsystem::LoadStreamingLevel(FName LevelName, FLevelFinishedLoading&& Callback)
{
}

void URogueRoomSubsystem::UnloadStreamingLevel(FName LevelName)
{
}

void URogueRoomSubsystem::OnLoadStreamLevelFinished(int Linkage)
{
}

void URogueRoomSubsystem::OnUnloadStreamLevelFinished(int Linkage)
{
}
