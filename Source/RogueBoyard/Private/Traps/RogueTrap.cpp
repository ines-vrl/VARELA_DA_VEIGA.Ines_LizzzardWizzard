// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueBoyard/Public/Traps/RogueTrap.h"
#include "Math/UnrealMathUtility.h"
#include <cmath>

ARogueTrap::ARogueTrap()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ARogueTrap::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARogueTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}


void ARogueTrap::RotateTrap(const float DeltaTime, const FVector& InputAxis)
{
	if (bCanRotate && FMath::Abs(InputAxis.X) > ValueMinimalRotationJoystick && FMath::Abs(InputAxis.X) < -ValueMinimalRotationJoystick)
	{
		CurrentRotation = GetActorRotation();
		RotationInput = InputAxis.X;
		CurrentRotationSpeed += RotationInput * Acceleration * DeltaTime;
		CurrentRotationSpeed = FMath::Clamp(CurrentRotationSpeed, -MaxRotationSpeed, MaxRotationSpeed);
		CurrentRotation.Yaw += CurrentRotationSpeed * DeltaTime;
		SetActorRotation(CurrentRotation);
	}
	else
	{
		CurrentRotationSpeed = FMath::FInterpTo(CurrentRotationSpeed, 0.0f, DeltaTime, Deceleration);
		CurrentRotation = GetActorRotation();
		CurrentRotation.Yaw += CurrentRotationSpeed * DeltaTime;
		SetActorRotation(CurrentRotation); 
	}
}

void ARogueTrap::MoveOnXAxis(const float DeltaTime, float InputAxisX,float Speed)
{
	if (FMath::Abs(InputAxisX) > KINDA_SMALL_NUMBER)
	{
		DistanceToMove = InputAxisX * Speed * DeltaTime;
		NewLocation = GetActorLocation() + FVector(DistanceToMove, 0, 0);
		SetActorLocation(NewLocation);
		CurrentDistance += FMath::Abs(DistanceToMove);
		if (CurrentDistance > MaxDistance)
		{
			CurrentDistance = MaxDistance;
			NewLocation = OriginalPosition + FVector(MaxDistance, 0, 0);
			SetActorLocation(NewLocation);
		}
		else if (CurrentDistance < 0.0f)
		{
			CurrentDistance = 0.0f;
			NewLocation = OriginalPosition;
			SetActorLocation(NewLocation);
		}
	}
}