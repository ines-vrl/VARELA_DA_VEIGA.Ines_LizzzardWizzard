// Fill out your copyright notice in the Description page of Project Settings.


#include "Traps/RotatingPlatform.h"


// Sets default values
ARotatingPlatform::ARotatingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ARotatingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RotatingPlatform_Implementation(DeltaTime,InputAxisDebug);
}

void ARotatingPlatform::RotatingPlatform_Implementation(float DeltaTime, FVector InputAxis)
{
	RotateTrap(DeltaTime, InputAxis);
}

