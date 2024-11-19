// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ballon.generated.h"

UCLASS()
class ROGUEBOYARD_API ABallon : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABallon();

	UPROPERTY(EditAnywhere)
	float FloatingFrequency;
	UPROPERTY(EditAnywhere)
	float FloatingRange;

	UFUNCTION(BlueprintCallable)
	void Floating();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
