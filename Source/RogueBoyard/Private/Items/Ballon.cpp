// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Ballon.h"


// Sets default values
ABallon::ABallon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ABallon::MovingOnSin()
{
	FVector Floating = GetActorLocation();
	float DeltaTime = GetWorld()->DeltaTimeSeconds;
	
	SelfTime += DeltaTime;
	Velocity = Velocity - Velocity * Friction * DeltaTime;

	Floating += Velocity * DeltaTime;
	
	float ScaleFrequency = FMath::Lerp(ScaleFrequencyMin, ScaleFrequencyMax, Velocity.Length() * Friction / MaxSpeed);
	float ScaleRange = FMath::Lerp(ScaleRangeMax,ScaleRangeMin , Velocity.Length() / MaxSpeed);
	
	Floating.Z = ScaleRange * FMath::Sin(ScaleFrequency * SelfTime) + PositionStartZ;
	FVector Scale = StartScale;
	Scale.X = FMath::Lerp(StartScale.X, StartScale.X + MAXScaleBall, Velocity.Length() * Friction / MaxSpeed );
	if(Velocity.Length() < MinSpeedToScaleBall)
	{
		Scale.X = FMath::Lerp(StartScale.X, StartScale.X + MAXScaleBall, (Velocity.Length() * Friction / MaxSpeed)/2 );
	}

	SetActorRelativeScale3D(Scale);
	if(!Velocity.IsNearlyZero())
	{
		FRotator Rotator = Velocity.Rotation();
		Rotator.Pitch = 0.0f;
		Rotator.Roll = 0.0f;
		UStaticMeshComponent* StaticMesh = Cast<UStaticMeshComponent>(GetComponentByClass(UStaticMeshComponent::StaticClass()));
		if(StaticMesh != nullptr) StaticMesh->SetRelativeRotation(Rotator);
	}
	
	SetActorLocation(Floating, true); 
}

void ABallon::AddImpulse(FVector DirForce, bool wall)
{
	if(wall)
	{
		Velocity = DirForce;
		SelfTime = 0;
		if(Velocity.Length() > MaxSpeed) Velocity = Velocity.GetSafeNormal() * MaxSpeed;
		return;
	}
	Velocity += DirForce;
	SelfTime = 0;
	if(Velocity.Length() > MaxSpeed) Velocity = Velocity.GetSafeNormal() * MaxSpeed;
	
}

// Called when the game starts or when spawned
void ABallon::BeginPlay()
{
	Super::BeginPlay();
	PositionStartZ = GetActorLocation().Z;
}

