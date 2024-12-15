// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/DeveloperSettings.h"
#include "LocalMultiplayerSettings.generated.h"

class UInputMappingContext;

UENUM(Blueprintable)
enum class ELocalMultiplayerInputMappingType : uint8
{
	InGame,
	Menu
};

USTRUCT()
struct FLocalMultiplayerProfileData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FName ProfileName;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputMappingContext> IMCInGame;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputMappingContext> IMCMenu;

	bool ContainsKey(const FKey& Key, ELocalMultiplayerInputMappingType MappingType) const;

	UInputMappingContext* GetIMCFromType(ELocalMultiplayerInputMappingType MappingType) const;
};

UCLASS(Config=Game, DefaultConfig, meta= (DisplayName="Local Multiplayer Settings"))
class LOCALMULTIPLAYER_API ULocalMultiplayerSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Config, EditAnywhere, Category="Local Multiplayer Settings")
	TArray<FLocalMultiplayerProfileData> KeyBoardProfilesData;

	int GetNbKeyboardProfiles() const;

	int FindKeyboardProfileFromKey(const FKey& Key, ELocalMultiplayerInputMappingType MappingType) const;

	UPROPERTY(Config, EditAnywhere, Category="Local Multiplaye")
	FLocalMultiplayerProfileData GamepadProfilData;

	UPROPERTY(Config, EditAnywhere, Category="Local Multiplayer")
	int NbMaxGamepads = 4;
};
