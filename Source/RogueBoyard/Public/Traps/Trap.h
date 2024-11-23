// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RogueTrap.h"
#include "TrapsInput.h"
#include "Trap.generated.h"

UCLASS()
class ROGUEBOYARD_API ATrap : public ARogueTrap
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BLueprintNativeEvent, BlueprintCallable)
	void OpenTrap();
};
