// Fill out your copyright notice in the Description page of Project Settings.


#include "Traps/Crossbow.h"


// Sets default values
ACrossbow::ACrossbow()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACrossbow::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACrossbow::InputJoystick(float DeltaTime,FVector InputAxis)
{
	Super::InputJoystick(DeltaTime,InputAxis);
	RotateTrap(DeltaTime,InputAxis);
}

void ACrossbow::InputButtonDown()
{
	Super::InputButtonDown();
}

void ACrossbow::InputButtonUp()
{
	Super::InputButtonUp();
}

// Called every frame
void ACrossbow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RotateCrossbow(DeltaTime,InputAxisDebug);
	
}

void ACrossbow::RotateCrossbow_Implementation(float DeltaTime, const FVector& InputAxis)
{
	InputJoystick(DeltaTime,InputAxis);
}

void ACrossbow::ChargeShot_Implementation()
{
	InputButtonDown();
}

void ACrossbow::ReleaseShot_Implementation()
{
	InputButtonUp();
}

