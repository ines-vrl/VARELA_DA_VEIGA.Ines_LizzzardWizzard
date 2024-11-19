// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RogueTrap.h"
#include "PushableComponent.h"
#include "Millstone.generated.h"

UCLASS(HideCategories=("Rotation"))
class ROGUEBOYARD_API AMillstone : public ARogueTrap
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMillstone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,Blueprintable, Category="Trap|Millstone")
	float PushForce = 1;

	UFUNCTION(BlueprintCallable)
	void Push(TArray<AActor*> Actors);


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
