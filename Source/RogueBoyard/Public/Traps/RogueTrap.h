// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TrapsInput.h"
#include "GameFramework/Actor.h"
#include "RogueTrap.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRogueTrapActivated);

UCLASS()
class ROGUEBOYARD_API ARogueTrap : public AActor, public ITrapsInput
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
	float ValueMinimalRotationJoystick;

	/**
	 * In degrees per second
	 */
	UPROPERTY(EditAnywhere, Category = "Trap|Rotation")
	float MaxRotationSpeed;
	
	UPROPERTY(EditAnywhere, Category = "Trap|Rotation")
	float Friction;

	UPROPERTY(EditAnywhere, Category = "Trap|Rotation")
	float Acceleration;
	
	UFUNCTION()
	void RotateTrap(float DeltaTime);

	virtual void Trigger_Implementation(const FVector& InputAxis) override;

	UFUNCTION()
	void MoveOnXAxis(const float DeltaTime,float InputAxisX);

	
public:
	virtual void Tick(float DeltaTime) override;

private:
	//Rotation
	UPROPERTY()
	float CurrentRotationSpeed;

	UPROPERTY()
	FRotator NewRotation;

	UPROPERTY()
	FVector JoystickInputAxis;

	//Movement
	UPROPERTY()
	float MovementSpeed;
	
	UPROPERTY()
	float MaxDistance;
	
	UPROPERTY()
	float DistanceToMove;

	UPROPERTY()
	float CurrentDistance;

	UPROPERTY()
	FVector NewLocation;

	UPROPERTY()
	FVector OriginalPosition;
};
