// Fill out your copyright notice in the Description page of Project Settings.


#include "Room/RogueRoomPawn.h"

#include "Characters/RogueCharacter.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ARogueRoomPawn::ARogueRoomPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ARogueRoomPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARogueRoomPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ARogueRoomPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ARogueRoomPawn::UnPossesRoom(int PlayerControllerIndex, ARogueCharacter* Character)
{
	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), PlayerControllerIndex);
	PC->UnPossess();
	PC->Possess(Character);
}

