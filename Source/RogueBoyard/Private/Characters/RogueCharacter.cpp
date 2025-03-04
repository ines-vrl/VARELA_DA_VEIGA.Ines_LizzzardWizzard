﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueBoyard/Public/Characters/RogueCharacter.h"

#include "Characters/RogueCharacterStateID.h"
#include "Core/RogueGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "RogueBoyard/Public/Characters/RogueCharacterStateMachine.h"
#include "Room/RogueRoomPawn.h"
#include "Components/BoxComponent.h"
#include "Engine/ContentEncryptionConfig.h"

// Sets default values
ARogueCharacter::ARogueCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Box->SetupAttachment(GetMesh());
}

// Called when the game starts or when spawned
void ARogueCharacter::BeginPlay()
{
	Super::BeginPlay();
	CreateStateMachine();
	InitStateMachine();
	CurrentLives = LivesMAX;
	Cast<ARogueGameMode>(GetWorld()->GetAuthGameMode())->Characters.Add(this);
}

// Called every frame
void ARogueCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TickStateMachine(DeltaTime);
}

// Called to bind functionality to input
void ARogueCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ARogueCharacter::CreateStateMachine()
{
	StateMachine = NewObject<URogueCharacterStateMachine>();
}

void ARogueCharacter::InitStateMachine()
{
	if(StateMachine == nullptr) return;
	StateMachine->Init(this);
}

void ARogueCharacter::TickStateMachine(float DeltaTime) const
{
	if(StateMachine == nullptr) return;
	StateMachine->Tick(DeltaTime);
}

void ARogueCharacter::TakeDamage(int Damage)
{
	CurrentLives -= Damage;
	if(CurrentLives <= 0) Die();
}

void ARogueCharacter::Resurrect() {
	if(StateMachine->CurrentStateID == ERogueCharacterStateID::Dead) {
		StateMachine->ChangeState(ERogueCharacterStateID::Idle);
	}
}

void ARogueCharacter::Die()
{
	if(StateMachine == nullptr) return;
	StateMachine->ChangeState(ERogueCharacterStateID::Dead);
}

void ARogueCharacter::UnPossessCharacter(ARogueRoomPawn* Room)
{
	APlayerController* PC = Cast<APlayerController>(GetController());
	if(PC)
	{
		PC->UnPossess();
		PC->Possess(Room);
	}
}



