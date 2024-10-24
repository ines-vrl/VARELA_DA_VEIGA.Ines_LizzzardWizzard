// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/RogueGameMode.h"

#include "LocalMultiplayerSettings.h"
#include "LocalMultiplayerSubSystem.h"
#include "Room/RogueRoomSubsystem.h"

void ARogueGameMode::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetSubsystem<URogueRoomSubsystem>()->InitFirstRoom();
	InitPlayers();
}

void ARogueGameMode::InitPlayers()
{
	UGameInstance* GameInstance = GetGameInstance();
	if(GameInstance == nullptr) return;
	
	ULocalMultiplayerSubSystem* LocalMultiplayerSubSystem = GameInstance->GetSubsystem<ULocalMultiplayerSubSystem>();
	if(LocalMultiplayerSubSystem == nullptr) return;

	//TODO MODIFIER LE PARAMETRE EN DESSOUS
	LocalMultiplayerSubSystem->CreateAndInitPlayers(ELocalMultiplayerInputMappingType::InGame);
}
