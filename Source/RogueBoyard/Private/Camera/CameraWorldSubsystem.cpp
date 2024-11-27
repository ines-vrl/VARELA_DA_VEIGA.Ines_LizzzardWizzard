// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera/CameraWorldSubsystem.h"

#include "Camera/CameraActor.h"
#include "Characters/RogueCharacterStateID.h"
#include "Characters/RogueCharacterStateMachine.h"
#include "Kismet/KismetMathLibrary.h"

void UCameraWorldSubsystem::PostInitialize()
{
	Super::PostInitialize();
}

void UCameraWorldSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(CurrentCamera != nullptr) TickUpdateCameraPosition(DeltaTime);
}

void UCameraWorldSubsystem::AddFollowTarget(ARogueCharacter* FollowTarget)
{
	FollowTargets.Add(FollowTarget);
}

void UCameraWorldSubsystem::RemoveFollowTarget(ARogueCharacter* FollowTarget)
{
	FollowTargets.Remove(FollowTarget);
}

void UCameraWorldSubsystem::ClearFollowTarget()
{
	FollowTargets.Empty();
}

void UCameraWorldSubsystem::TickUpdateCameraPosition(float DeltaTime)
{
	FVector TargetViewPoint = CalculateAveragePositionBetweenTargets();
	FRotator RotationTarget = UKismetMathLibrary::FindLookAtRotation(CurrentCamera->GetActorLocation(), TargetViewPoint);
	RotationTarget.Roll = CurrentCamera->GetActorRotation().Roll;
	CurrentCamera->SetActorRotation(RotationTarget);
}

FVector UCameraWorldSubsystem::CalculateAveragePositionBetweenTargets()
{
	FVector AveragePos = FVector::Zero();
	for (auto Object : FollowTargets)
	{
		if(Object->StateMachine->CurrentStateID != ERogueCharacterStateID::Dead)
			AveragePos += Object->GetActorLocation();
	}
	return 	AveragePos /= FollowTargets.Num();;
}
