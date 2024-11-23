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

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BLueprintNativeEvent, BlueprintCallable)
	void ChargeShot();

	UFUNCTION(BLueprintNativeEvent, BlueprintCallable)
	void ReleaseShot();
};
