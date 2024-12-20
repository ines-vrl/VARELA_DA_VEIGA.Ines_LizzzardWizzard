// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ControllerVibrationSettings.generated.h"

/**
 * 
 */
UCLASS(Config=Input, DefaultConfig, meta= (DisplayName="Controller Vibration Settings"))
	
class ROGUEBOYARD_API UControllerVibrationSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Controller Vibration Settings")
	UForceFeedbackEffect * VibrationDegressiveFeedbackEffect;
	UPROPERTY(EditAnywhere, Category="Controller Vibration Settings")
	UForceFeedbackEffect * VibrationProgressiveFeedbackEffect;
	UPROPERTY(EditAnywhere, Category="Controller Vibration Settings")
	UForceFeedbackEffect * VibrationHeavyContinuousFeedbackEffect;
	UPROPERTY(EditAnywhere, Category="Controller Vibration Settings")
	UForceFeedbackEffect * VibrationHeavyQuickFeedbackEffect;
	UPROPERTY(EditAnywhere, Category="Controller Vibration Settings")
	UForceFeedbackEffect * VibrationLightQuickFeedbackEffect;
	UPROPERTY(EditAnywhere, Category="Controller Vibration Settings")
	UForceFeedbackEffect * VibrationLightContinuousFeedbackEffect;
	UPROPERTY(EditAnywhere, Category="Controller Vibration Settings")
	UForceFeedbackEffect * VibrationPulsingFeedbackEffect;
	
};
