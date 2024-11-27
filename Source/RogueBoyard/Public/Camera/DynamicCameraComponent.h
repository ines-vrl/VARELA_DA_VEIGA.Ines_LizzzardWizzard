// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "DynamicCameraComponent.generated.h"

/**
 * 
 */
UCLASS()
class ROGUEBOYARD_API UDynamicCameraComponent : public UCameraComponent
{
	GENERATED_BODY()

public:
	void UpdateCameraPosition();
};
