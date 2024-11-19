// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Ballon.h"


// Sets default values
ABallon::ABallon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ABallon::Floating()
{
	FVector Floating = GetActorLocation();
	Floating.Z = (FloatingRange * FMath::Sin(FloatingFrequency * GetWorld()->GetTimeSeconds())) + Floating.Z;
	SetActorLocation(Floating);
}

// Called when the game starts or when spawned
void ABallon::BeginPlay()
{
	Super::BeginPlay();
	
}

