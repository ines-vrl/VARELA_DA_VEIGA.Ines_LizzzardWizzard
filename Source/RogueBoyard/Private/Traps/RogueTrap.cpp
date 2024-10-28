// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueBoyard/Public/Traps/RogueTrap.h"
#include "Math/UnrealMathUtility.h"

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


void ARogueTrap::RotateTrap(const float DeltaTime,const FVector& InputAxis)
{
	if(bCanRotate)
	{
		CurrentRotation = GetActorRotation();
		AngleInRadians = FMath::Atan2(InputAxis.Y, InputAxis.X);
		TargetAngle = FMath::RadiansToDegrees(AngleInRadians);
		CurrentAngle = NewRotation.Yaw;
		AngleDifference = TargetAngle - CurrentAngle;
		AngleDifference = FMath::Fmod(AngleDifference + 180.0f, 360.0f) - 180.0f;
		RotationToApply = FMath::Clamp(AngleDifference, -MaxRotationSpeed * DeltaTime, MaxRotationSpeed * 10 * DeltaTime);
		NewRotation = CurrentRotation;
		NewRotation.Yaw += RotationToApply;
		SetActorRotation(NewRotation);
	}
}
