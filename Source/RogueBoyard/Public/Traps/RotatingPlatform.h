// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RogueTrap.h"
#include "RotatingPlatform.generated.h"

UCLASS()
class ROGUEBOYARD_API ARotatingPlatform : public ARogueTrap
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARotatingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
