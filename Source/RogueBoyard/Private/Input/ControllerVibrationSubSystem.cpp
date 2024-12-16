// Fill out your copyright notice in the Description page of Project Settings.


#include "Input/ControllerVibrationSubSystem.h"



void UControllerVibrationSubSystem::VibrationDegressive(APlayerController* PlayerController)
{

	UForceFeedbackEffect * ForceFeedbackEffect = LoadObject<UForceFeedbackEffect>(nullptr, TEXT("ForceFeedbackEffect'/Game/RogueBoyard/Inputs/JoystickVibration/FFE_Degressive.FFE_Degressive'"));
	if(ForceFeedbackEffect==nullptr)return;
	PlayerController->ClientPlayForceFeedback(ForceFeedbackEffect);
}

void UControllerVibrationSubSystem::VibrationProgressive(APlayerController* PlayerController)
{
	UForceFeedbackEffect * ForceFeedbackEffect = LoadObject<UForceFeedbackEffect>(nullptr, TEXT("ForceFeedbackEffect'/Game/RogueBoyard/Inputs/JoystickVibration/FFE_Progressive.FFE_Progressive'"));
	if(ForceFeedbackEffect==nullptr)return;
	PlayerController->ClientPlayForceFeedback(ForceFeedbackEffect);
}

void UControllerVibrationSubSystem::VibrationHeavyContinuous(APlayerController* PlayerController)
{
	UForceFeedbackEffect * ForceFeedbackEffect = LoadObject<UForceFeedbackEffect>(nullptr, TEXT("ForceFeedbackEffect'/Game/RogueBoyard/Inputs/JoystickVibration/FFE_HeavyContinuous.FFE_HeavyContinuous'"));
	if(ForceFeedbackEffect==nullptr)return;
	PlayerController->ClientPlayForceFeedback(ForceFeedbackEffect);
}

void UControllerVibrationSubSystem::VibrationHeavyQuick(APlayerController* PlayerController)
{
	UForceFeedbackEffect * ForceFeedbackEffect = LoadObject<UForceFeedbackEffect>(nullptr, TEXT("ForceFeedbackEffect'/Game/RogueBoyard/Inputs/JoystickVibration/FFE_HeavyQuick.FFE_HeavyQuick'"));
	if(ForceFeedbackEffect==nullptr)return;
	PlayerController->ClientPlayForceFeedback(ForceFeedbackEffect);
}

void UControllerVibrationSubSystem::VibrationLightQuick(APlayerController* PlayerController)
{
	UForceFeedbackEffect * ForceFeedbackEffect = LoadObject<UForceFeedbackEffect>(nullptr, TEXT("ForceFeedbackEffect'/Game/RogueBoyard/Inputs/JoystickVibration/FFE_LightQuick.FFE_LightQuick'"));
	if(ForceFeedbackEffect==nullptr)return;
	PlayerController->ClientPlayForceFeedback(ForceFeedbackEffect);
}

void UControllerVibrationSubSystem::VibrationLightContinuous(APlayerController* PlayerController)
{
	UForceFeedbackEffect * ForceFeedbackEffect = LoadObject<UForceFeedbackEffect>(nullptr, TEXT("ForceFeedbackEffect'/Game/RogueBoyard/Inputs/JoystickVibration/FFE_LightContinuous.FFE_LightContinuous'"));
	if(ForceFeedbackEffect==nullptr)return;
	PlayerController->ClientPlayForceFeedback(ForceFeedbackEffect);
}

void UControllerVibrationSubSystem::VibrationLightPulsing(APlayerController* PlayerController)
{
	UForceFeedbackEffect * ForceFeedbackEffect = LoadObject<UForceFeedbackEffect>(nullptr, TEXT("ForceFeedbackEffect'/Game/RogueBoyard/Inputs/JoystickVibration/FFE_LightPulsing.FFE_LightPulsing'"));
	if(ForceFeedbackEffect==nullptr)return;
	PlayerController->ClientPlayForceFeedback(ForceFeedbackEffect);
}

