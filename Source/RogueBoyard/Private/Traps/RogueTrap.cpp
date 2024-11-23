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
	RotateTrap(DeltaTime);
}

void ARogueTrap::RotateTrap(float DeltaTime)
{
	if (bCanRotate)
	{
		if(FMath::Abs(JoystickInputAxis.X) > ValueMinimalRotationJoystick)
		{
			CurrentRotationSpeed += JoystickInputAxis.X * Acceleration * DeltaTime;
			CurrentRotationSpeed = FMath::Clamp(CurrentRotationSpeed, -MaxRotationSpeed, MaxRotationSpeed);
		}
		CurrentRotationSpeed -= CurrentRotationSpeed * Friction * DeltaTime;
		NewRotation = GetActorRotation();
		NewRotation.Yaw += CurrentRotationSpeed * DeltaTime;
		SetActorRotation(NewRotation);
	}
}

void ARogueTrap::Trigger_Implementation(const FVector& InputAxis)
{
	JoystickInputAxis = InputAxis;
}

