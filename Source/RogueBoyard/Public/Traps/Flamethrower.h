// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Traps/RogueTrap.h"
#include "Flamethrower.generated.h"

UCLASS()
class ROGUEBOYARD_API AFlamethrower : public ARogueTrap
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFlamethrower();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BLueprintNativeEvent, BlueprintCallable)
	void RotateFlameThrower(float DeltaTime,const FVector &InputAxis);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
