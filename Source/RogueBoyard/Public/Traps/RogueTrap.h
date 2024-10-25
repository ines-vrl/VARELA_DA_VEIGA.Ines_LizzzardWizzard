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
	
	virtual void InputJoystick(float DeltaTime, FVector InputAxis);
	
	virtual void InputButtonDown();
	
	virtual void InputButtonUp();

	void RotateTrap(const float DeltaTime,const FVector& InputRotation);
	
public:
	virtual void Tick(float DeltaTime) override;

	



private:
	UPROPERTY()
	FRotator CurrentRotation;

	UPROPERTY()
	FRotator NewRotation;

	UPROPERTY()
	float RotationToApply;

	UPROPERTY()
	float AngleDifference;

	UPROPERTY()
	float TargetAngle;

	UPROPERTY()
	float AngleInRadians;

	UPROPERTY()
	float CurrentAngle;
};
