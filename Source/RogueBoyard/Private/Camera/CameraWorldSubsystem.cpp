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
	if(CurrentCamera != nullptr && !noDynamic)
	{
		if(!noZoom)		TickUpdateCameraZoom(DeltaTime);
		TickUpdateCameraPosition(DeltaTime);
	}
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

void UCameraWorldSubsystem::InitCameraZoomParameters(ACameraActor* CameraZoomMaxIn, ACameraActor* CameraZoomMinIn)
{
	CameraZoomMax = CameraZoomMaxIn;
	//CameraZoomMax->GetActorLocation() = CurrentCamera->GetActorLocation();
	CameraZoomMax->GetActorRotation() = CurrentCamera->GetActorRotation();
	CameraZoomMin = CameraZoomMinIn;
	//CameraZoomMin->GetActorLocation() = CurrentCamera->GetActorLocation();
	CameraZoomMin->GetActorRotation() = CurrentCamera->GetActorRotation();
}

void UCameraWorldSubsystem::SetCamera(ACameraActor* NewCamera,ACameraActor* CameraZoomMaxIn = nullptr, ACameraActor* CameraZoomMinIn = nullptr)
{
	if(NewCamera == nullptr) return;
	CurrentCamera = NewCamera;
	DefaultRotator = CurrentCamera->GetActorRotation();
	if(NewCamera->FindComponentByClass<UDynamicCameraComponent>() == nullptr)
	{
		noDynamic = true;
		return;
	}
	noDynamic = false;
	DeltaRotationY = NewCamera->FindComponentByClass<UDynamicCameraComponent>()->DeltaRotationYZ.X;
	DeltaRotationZ = NewCamera->FindComponentByClass<UDynamicCameraComponent>()->DeltaRotationYZ.Y;
	if(CameraZoomMaxIn == nullptr ||CameraZoomMinIn == nullptr)
	{
		noZoom = true;
		return;
	}
	noZoom = false;
	InitCameraZoomParameters(CameraZoomMaxIn, CameraZoomMinIn);
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
	if(CurrentCamera == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("PasDeCamFrero"));
		return;
	}
	float GreatestDistanceBetweenTargets = CalculateGreatestDistanceBetweenTargets();

	float ZoomPercent = FMath::Clamp(FMath::GetMappedRangeValueClamped(
		FVector2D(ZoomDistanceBetweenTargetsMin, ZoomDistanceBetweenTargetsMax),
		FVector2D(0.f, 1.f),
		GreatestDistanceBetweenTargets),
		0.f, 1.f);

	FVector NewLocation = FMath::Lerp(CameraZoomMax->GetActorLocation(),
		CameraZoomMin->GetActorLocation(),
		ZoomPercent);
	UE_LOG(LogTemp, Warning, TEXT("NewPosition is : %s"), *NewLocation.ToString());
	CurrentCamera->SetActorLocation(NewLocation);
	
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
	float GreatestDistance = 0.f;

	for(int i = 0; i < FollowTargets.Num() ; i++)
	{
		for(int j = i + 1; i < FollowTargets.Num(); i++)
		{
			if(FollowTargets[i] != nullptr && FollowTargets[j] != nullptr)
			{
				float Distance = FVector::Dist(FollowTargets[i]->GetActorLocation(), FollowTargets[j]->GetActorLocation());
				GreatestDistance += Distance;
			}
		}
	}
	//UE_LOG(LogTemp, Warning, TEXT("GreatestDistance: %f"), GreatestDistance);
	return GreatestDistance/= FollowTargets.Num();
}
