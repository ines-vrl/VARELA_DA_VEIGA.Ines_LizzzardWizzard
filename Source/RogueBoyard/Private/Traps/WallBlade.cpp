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
	OriginalPosition = GetActorLocation();
	
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
	ActorRotation = GetActorRotation();
	ForwardDirection = ActorRotation.RotateVector(FVector(1, 0, 0));
	NewLocation = GetActorLocation() + ForwardDirection * DistanceToMove;
	if (FMath::Abs(NewLocation.X - OriginalPosition.X) > MaxDistance)
	{
		ClampedDistance = FMath::Sign(DistanceToMove) * MaxDistance;
		NewLocation.X = OriginalPosition.X + ClampedDistance;
	}
	SetActorLocation(NewLocation);
}

