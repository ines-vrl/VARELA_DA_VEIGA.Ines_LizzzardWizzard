// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera/CameraWorldSubsystem.h"

#include "Camera/CameraActor.h"
#include "Characters/RogueCharacterStateID.h"
#include "Characters/RogueCharacterStateMachine.h"
#include "Kismet/GameplayStatics.h"
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

void UCameraWorldSubsystem::InitCameraZoomParameters()
{
	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Max", OutActors);
}

void UCameraWorldSubsystem::SetCamera(ACameraActor* NewCamera)
{
	CurrentCamera = NewCamera;
	DefaultRotator = CurrentCamera->GetActorRotation();
	DeltaRotationY = NewCamera->FindComponentByClass<UDynamicCameraComponent>()->DeltaRotationYZ.X;
	DeltaRotationZ = NewCamera->FindComponentByClass<UDynamicCameraComponent>()->DeltaRotationYZ.Y;
}

void UCameraWorldSubsystem::TickUpdateCameraPosition(float DeltaTime)
{
	FVector TargetViewPoint = CalculateAveragePositionBetweenTargets();
	//CameraDist = sqrt(pow(TargetViewPoint.X - CurrentCamera->GetActorLocation().X, 2.0f) + pow(TargetViewPoint.Y - CurrentCamera->GetActorLocation().Y, 2.0f));
	//float RotationLimit = FMath::Clamp(CameraDist / MaxDist, 0, 90.f);
	FRotator RotationTarget = UKismetMathLibrary::FindLookAtRotation(CurrentCamera->GetActorLocation(), TargetViewPoint);
	RotationTarget.Pitch = FMath::Clamp(RotationTarget.Pitch, -DeltaRotationY + DefaultRotator.Pitch , DeltaRotationY + DefaultRotator.Pitch );
	RotationTarget.Yaw = FMath::Clamp(RotationTarget.Yaw, -DeltaRotationZ + DefaultRotator.Yaw , DeltaRotationZ + DefaultRotator.Yaw );
	RotationTarget.Roll = CurrentCamera->GetActorRotation().Roll;
	CurrentCamera->SetActorRotation(RotationTarget);
	//DrawDebugPoint(GetWorld(),TargetViewPoint,20, FColor::Red);
}

void UCameraWorldSubsystem::TickUpdateCameraZoom(float DeltaTime)
{
	
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

float UCameraWorldSubsystem::CalculateGreatestDistanceBetweenTargets()
{
	return 0.f;
}
