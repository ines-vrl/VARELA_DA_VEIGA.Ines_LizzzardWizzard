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

	UPROPERTY(BlueprintReadWrite)
	float ZoomMin = 0.f;
	UPROPERTY(BlueprintReadWrite)
	float ZoomMax = 0.f;

	UPROPERTY(BlueprintReadWrite)
	float ZoomDistanceBetweenTargetsMin = 300.f;

	UPROPERTY(BlueprintReadWrite)
	float ZoomDistanceBetweenTargetsMax = 300.f;
	
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
	void InitCameraZoomParameters();
	
	UFUNCTION(BlueprintCallable)
	void SetCamera(ACameraActor* NewCamera);

	protected:
	UPROPERTY()
	TArray<ARogueCharacter*> FollowTargets;
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ACameraActor> CurrentCamera;
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ACameraActor> CameraZoomMax;
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ACameraActor> CameraZoomMin;
	
	float CameraDist;
	float DeltaRotationY, DeltaRotationZ;
	FRotator DefaultRotator;
	
	void TickUpdateCameraPosition(float DeltaTime);
	void TickUpdateCameraZoom(float DeltaTime);

	FVector CalculateAveragePositionBetweenTargets();

	float CalculateGreatestDistanceBetweenTargets();
	
};
