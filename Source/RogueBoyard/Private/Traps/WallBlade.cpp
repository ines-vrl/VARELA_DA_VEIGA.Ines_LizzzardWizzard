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
	MoveOnXAxis(DeltaTime);
}

void AWallBlade::MoveOnXAxis(const float& DeltaTime)
{
	DistanceToMove = JoystickInputAxis.X * MovementSpeed * DeltaTime;
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

