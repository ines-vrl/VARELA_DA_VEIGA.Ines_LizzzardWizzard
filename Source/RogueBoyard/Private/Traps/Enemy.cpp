// Fill out your copyright notice in the Description page of Project Settings.


#include "Traps/Enemy.h"
#include "Characters/RogueCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
AEnemy::AEnemy()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	InitialPosition = GetActorLocation();
	SetLifeSpan(LifeSpanDUEUHSPECTRE);
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemy::Push(TArray<AActor*> Players)
{
	for (AActor* Player : Players)
	{
		FVector Dir = Player->GetActorLocation() - GetActorLocation();
		Dir.Normalize();
		UPushableComponent* pushComp = Cast<UPushableComponent>(Player->GetComponentByClass(UPushableComponent::StaticClass()));
		if(pushComp != nullptr) pushComp->Push(Dir, PushForce);
	}
}

void AEnemy::Kill(ARogueCharacter* Character)
{
	Character->TakeDamage(1000);
}

void AEnemy::SearchMovement(float DeltaTime)
{
	CurrentTime += DeltaTime * SearchMoveSpeed;
	FVector NewPosition = InitialPosition;
	NewPosition.X += MoveAmplitudeX * FMath::Sin(CurrentTime);
	NewPosition.Y += MoveAmplitudeY * FMath::Sin(2 * CurrentTime);
	SetActorRotation(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), NewPosition));
	SetActorLocation(NewPosition);
}

void AEnemy::MoveToPlayer(AActor* Player,float DeltaTime)
{
	CurrentTime += DeltaTime;
	FVector CurrentLocation = GetActorLocation();
	FVector TargetLocation = Player->GetActorLocation();
	FVector Direction = TargetLocation - CurrentLocation;
	Direction.Normalize();
	FVector NewLocation = CurrentLocation + Direction * MoveSpeed * CurrentTime;
	SetActorRotation(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), FVector(NewLocation.X,NewLocation.Y,GetActorLocation().Z)));
	SetActorLocation(FVector(NewLocation.X,NewLocation.Y,GetActorLocation().Z));
}

