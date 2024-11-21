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

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxSpeed = 2000.0f;

	UPROPERTY(EditAnywhere)
	float ScaleRangeMax = 20.0f;
	UPROPERTY(EditAnywhere)
	float ScaleRangeMin = 10.0f;

	UPROPERTY(EditAnywhere)
	float ScaleFrequencyMax = 50.0f;
	UPROPERTY(EditAnywhere)
	float ScaleFrequencyMin = 4.0f;

	UPROPERTY(EditAnywhere)
	float MAXScaleBall = 5.0f;

	UPROPERTY(EditAnywhere)
	float MinSpeedToScaleBall = 1000.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float TimeFreezeMax = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float TimeFreezeMin = 0.1f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float EjectionResistance = 1.0f;

	UPROPERTY(BlueprintReadOnly)
	float PositionStartZ;
	UPROPERTY(BlueprintReadWrite)
	FVector StartScale;
	
	UPROPERTY(BlueprintReadWrite)
	FVector Velocity;

	UPROPERTY(BlueprintReadWrite)
	bool bIsPushed = false;

	UPROPERTY(EditAnywhere)
	float Friction = 0.9f;
	
	UFUNCTION(BlueprintCallable)
	void MovingOnSin();

	UFUNCTION(BlueprintCallable)
	void AddImpulse(FVector DirForce, bool wall);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float SelfTime = 0.0f;
};
