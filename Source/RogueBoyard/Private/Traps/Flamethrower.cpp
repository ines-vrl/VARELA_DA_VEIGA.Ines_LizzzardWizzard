// Fill out your copyright notice in the Description page of Project Settings.


#include "Traps/Flamethrower.h"


// Sets default values
AFlamethrower::AFlamethrower()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFlamethrower::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFlamethrower::RotateFlameThrower_Implementation(float DeltaTime, const FVector& InputAxis)
{
	RotateTrap(DeltaTime, InputAxis);
}

// Called every frame
void AFlamethrower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


