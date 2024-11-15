// Fill out your copyright notice in the Description page of Project Settings.


#include "Traps/WallBlade.h"


// Sets default values
AWallBlade::AWallBlade()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWallBlade::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWallBlade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveOnOneAxis(DeltaTime);
}

void AWallBlade::MoveOnOneAxis(const float& DeltaTime)
{
	DistanceToMove = JoystickInputAxis.X * MovementSpeed * DeltaTime;
	NewLocation = GetActorLocation() + FVector(DistanceToMove, 0, 0);
	if (FMath::Abs(NewLocation.X - OriginalPosition.X) > MaxDistance)
	{
		ClampedDistance = FMath::Sign(DistanceToMove) * MaxDistance;
		NewLocation.X = OriginalPosition.X + ClampedDistance;
	}
	SetActorLocation(NewLocation);
}

