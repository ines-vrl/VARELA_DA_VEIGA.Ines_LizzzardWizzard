// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RogueTrap.h"
#include "FlameThrower.generated.h"

UCLASS()
class ROGUEBOYARD_API AFlameThrower : public ARogueTrap
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFlameThrower();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void InputJoystick(float DeltaTime, FVector InputAxis) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BLueprintNativeEvent, BlueprintCallable)
	void RotateFlameThrower(float DeltaTime, const FVector& InputAxis);
};
