// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RogueTrap.h"
#include "Crossbow.generated.h"

UCLASS()
class ROGUEBOYARD_API ACrossbow : public ARogueTrap
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACrossbow();

protected:
	
	virtual void BeginPlay() override;

	virtual void InputJoystick(float DeltaTime,FVector InputAxis) override;

	virtual void InputButtonDown() override;

	virtual void InputButtonUp() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void RotateCrossbow(float DeltaTime, const FVector& InputAxis);

	UFUNCTION(BLueprintNativeEvent, BlueprintCallable)
	void ChargeShot();

	UFUNCTION(BLueprintNativeEvent, BlueprintCallable)
	void ReleaseShot();
};
