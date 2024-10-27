// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueCharacterState.h"

#include "RogueBoyard/Public/Characters/RogueCharacter.h"
#include "RogueBoyard/Public/Characters/RogueCharacterStateID.h"
#include "RogueBoyard/Public/Characters/RogueCharacterStateMachine.h"

// Sets default values for this component's properties
URogueCharacterState::URogueCharacterState()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

ERogueCharacterStateID URogueCharacterState::GetStateID()
{
	return ERogueCharacterStateID::None;
}

void URogueCharacterState::StateInit(URogueCharacterStateMachine* InStateMachine)
{
	StateMachine = InStateMachine;
	Character = InStateMachine->GetCharacter();
	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Magenta,
		FString::Printf(TEXT("Init State %d"), GetStateID())
		);
}

void URogueCharacterState::StateEnter(ERogueCharacterStateID PreviousStateID)
{
}

void URogueCharacterState::StateExit(ERogueCharacterStateID NextStateID)
{
}

void URogueCharacterState::StateTick(float DeltaTime)
{
}

void URogueCharacterState::Movement(float X, float Y)
{
}

bool URogueCharacterState::Dash(float X, float Y)
{
	return false;
}

TArray<AActor*> URogueCharacterState::Interact()
{
	return TArray<AActor*>();
}

bool URogueCharacterState::Push(TArray<AActor*> Actors)
{
	return false;
}

void URogueCharacterState::Resurrect()
{
}

