// Fill out your copyright notice in the Description page of Project Settings.


#include "LocalMultiplayerGameViewportClient.h"
#include "LocalMultiplayerSettings.h"
#include "LocalMultiplayerSubSystem.h"
#include "GameFramework/PlayerInput.h"
#include "Kismet/GameplayStatics.h"

void ULocalMultiplayerGameViewportClient::PostInitProperties()
{
	Super::PostInitProperties();
	MaxSplitscreenPlayers = 8;
}

bool ULocalMultiplayerGameViewportClient::InputKey(const FInputKeyEventArgs& EventArgs)
{
	const ULocalMultiplayerSettings* settings = GetDefault<ULocalMultiplayerSettings>();
	ULocalMultiplayerSubSystem* LMS = GetGameInstance()->GetSubsystem<ULocalMultiplayerSubSystem>();
	GEngine->AddOnScreenDebugMessage(
				-1,
				15.0f,
				FColor::Yellow,
				FString::Printf(TEXT("GAMEPAD")));
	if(EventArgs.IsGamepad())
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.0f,
			FColor::Yellow,
			FString::Printf(TEXT("GAMEPAD")));
		if(LMS->GetAssignedPlayerIndexFromGamepadDeviceID(EventArgs.InputDevice.GetId()) <= -1)
		{
			LMS->AssignGamepadInputMapping(
			LMS->AssignNewPlayerToGamepadDeviceID(EventArgs.InputDevice.GetId()),
			ELocalMultiplayerInputMappingType::InGame);
		}
		return Super::InputKey(EventArgs);
	}

	
	int KeyboardProfilIndex = settings->FindKeyboardProfileFromKey(EventArgs.Key, ELocalMultiplayerInputMappingType::InGame);
	if(KeyboardProfilIndex >= 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(
			TEXT("KeyboardProfile: %i"),
			KeyboardProfilIndex));
		int PlayerIndex = LMS->GetAssignedPlayerIndexFromKeyboardProfileIndex(KeyboardProfilIndex);
		if(PlayerIndex <= -1)
		{
			PlayerIndex = LMS->AssignNewPlayerToKeyboardProfile(KeyboardProfilIndex);
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(
			TEXT("NewPlayerIndex: %i"),
			PlayerIndex));
			LMS->AssignKeyboardMapping(
				PlayerIndex,
				KeyboardProfilIndex,
				ELocalMultiplayerInputMappingType::InGame);
		
		}
		PlayerIndex = LMS->GetAssignedPlayerIndexFromKeyboardProfileIndex(KeyboardProfilIndex);
		if (PlayerIndex != -1)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(
			TEXT("MovePlayerIndex: %i"),PlayerIndex));
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(
			TEXT("With¨Profile: %i"),KeyboardProfilIndex));
			FInputKeyParams Params(EventArgs.Key, EventArgs.Event, static_cast<double>(EventArgs.AmountDepressed), EventArgs.IsGamepad());
			return  UGameplayStatics::GetPlayerController(GetGameInstance()->GetWorld(), PlayerIndex)->InputKey(Params);
		}
	}
	//FLocalMultiplayerProfileData KeyBoardProfileData = settings->KeyBoardProfilesData[KeyboardProfilIndex];
	
	
	return Super::InputKey(EventArgs);
}

bool ULocalMultiplayerGameViewportClient::InputAxis(FViewport* InViewPort, FInputDeviceId InputDevice, FKey Key,
	float Delta, float Deltatime, int32 NumSamples, bool bGamepad)
{
	const ULocalMultiplayerSettings* settings = GetDefault<ULocalMultiplayerSettings>();
	ULocalMultiplayerSubSystem* LMS = GetGameInstance()->GetSubsystem<ULocalMultiplayerSubSystem>();
	int PlayerIndex = 0;
	if(LMS->GetAssignedPlayerIndexFromGamepadDeviceID(InputDevice.GetId()) <= -1)
	{
		PlayerIndex = LMS->AssignNewPlayerToGamepadDeviceID(InputDevice.GetId());
		LMS->AssignGamepadInputMapping(PlayerIndex,
		ELocalMultiplayerInputMappingType::InGame);
	}
	if (PlayerIndex != -1)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(
		TEXT("%i"), PlayerIndex));
		return UGameplayStatics::GetPlayerController(GetGameInstance()->GetWorld(), PlayerIndex)->InputAxis(Key, Delta, Deltatime,
			NumSamples, bGamepad);
	}
	return Super::InputAxis(InViewPort, InputDevice, Key, Delta, Deltatime, NumSamples, bGamepad);
}
