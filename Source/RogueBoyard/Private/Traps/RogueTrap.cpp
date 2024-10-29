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
	if(bCanRotate)
	{
		VectorStandard = FMath::Sqrt(InputAxis.X*InputAxis.X + InputAxis.Y*InputAxis.Y);
		if(VectorStandard > ValueMinimalRotationJoystick)
		{
			CurrentRotation = GetActorRotation();
			AngleInRadians = FMath::Atan2(InputAxis.Y, InputAxis.X);
			TargetAngle = FMath::RadiansToDegrees(AngleInRadians);
			CurrentAngle = CurrentRotation.Yaw;
			AngleDifference = TargetAngle - CurrentAngle;
			AngleDifference = FMath::Fmod(AngleDifference + 180.0f, 360.0f) - 180.0f;
			RotationToApply = FMath::Clamp(AngleDifference, -MaxRotationSpeed * DeltaTime, MaxRotationSpeed * DeltaTime);
			NewRotation = CurrentRotation;
			NewRotation.Yaw += RotationToApply;
			SetActorRotation(NewRotation);
		}
	}
}