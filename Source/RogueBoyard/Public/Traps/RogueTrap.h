// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RogueTrap.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRogueTrapActivated);

UCLASS(Abstract)
class ROGUEBOYARD_API ARogueTrap : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARogueTrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Trap|Debug")
	FVector InputAxisDebug;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Trap|Debug")
	bool bInputDownDebug;
	
	UPROPERTY(EditAnywhere, Category = "Trap|Rotation")
	bool bCanRotate;

	UPROPERTY(EditAnywhere, Category = "Trap|Rotation")
	float MaxRotationSpeed;

	UPROPERTY(EditAnywhere, Category = "Trap|Rotation")
	float ValueMinimalRotationJoystick;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Trap|Rotation")
	float Acceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Trap|Rotation")
	float Deceleration = 500.0f;

	UPROPERTY()
	float MaxDistance;
	
	UPROPERTY()
	float MovementSpeed;

	void RotateTrap(const float DeltaTime,const FVector& InputRotation);

	void MoveOnXAxis(const float DeltaTime,float InputAxisX);
	
public:
	virtual void Tick(float DeltaTime) override;


private:
	UPROPERTY()
	FRotator CurrentRotation;

	UPROPERTY()
	float RotationToApply;

	UPROPERTY()
	float RotationInput;

	UPROPERTY()
	float CurrentRotationSpeed;

	UPROPERTY()
	float DistanceToMove;

	UPROPERTY()
	float CurrentDistance;

	UPROPERTY()
	FVector NewLocation;

	UPROPERTY()
	FVector OriginalPosition;
};
