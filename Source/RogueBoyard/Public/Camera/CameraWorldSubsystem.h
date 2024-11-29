// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DynamicCameraComponent.h"
#include "Characters/RogueCharacter.h"
#include "Subsystems/WorldSubsystem.h"
#include "CameraWorldSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class ROGUEBOYARD_API UCameraWorldSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

	public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxDist = 1000.f;
	
	virtual void PostInitialize() override;
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override {return TStatId(); };

	UFUNCTION(BlueprintCallable)
	void AddFollowTarget(ARogueCharacter* FollowTarget);

	UFUNCTION(BlueprintCallable)
	void RemoveFollowTarget(ARogueCharacter* FollowTarget);

	UFUNCTION(BlueprintCallable)
	void ClearFollowTarget();
	
	UFUNCTION(BlueprintCallable)
	void SetCamera(ACameraActor* NewCamera);

	protected:
	UPROPERTY()
	TArray<ARogueCharacter*> FollowTargets;
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ACameraActor> CurrentCamera;
	
	float CameraDist;
	float DeltaRotationY, DeltaRotationZ;
	FRotator DefaultRotator;
	
	void TickUpdateCameraPosition(float DeltaTime);

	FVector CalculateAveragePositionBetweenTargets();
	
};
