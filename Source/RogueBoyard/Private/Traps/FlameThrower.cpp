// Fill out your copyright notice in the Description page of Project Settings.


#include "Traps/FlameThrower.h"


// Sets default values
AFlameThrower::AFlameThrower()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFlameThrower::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFlameThrower::InputJoystick(float DeltaTime, FVector InputAxis)
{
	Super::InputJoystick(DeltaTime, InputAxis);
	RotateTrap(DeltaTime, InputAxis);
}

// Called every frame
void AFlameThrower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	InputJoystick(DeltaTime,InputAxisDebug);
}

void AFlameThrower::RotateFlameThrower_Implementation(float DeltaTime, const FVector& InputAxis)
{
	InputJoystick(DeltaTime, InputAxis);
}

