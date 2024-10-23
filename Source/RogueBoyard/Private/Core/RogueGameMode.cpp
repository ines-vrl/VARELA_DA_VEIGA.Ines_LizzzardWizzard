// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/RogueGameMode.h"

#include "Room/RogueRoomSubsystem.h"

void ARogueGameMode::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetSubsystem<URogueRoomSubsystem>()->InitFirstRoom();
}
