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

