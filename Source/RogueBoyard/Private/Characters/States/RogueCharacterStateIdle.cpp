// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueBoyard/Public/Characters/States/RogueCharacterStateIdle.h"

#include "RogueBoyard/Public/Characters/RogueCharacter.h"


ERogueCharacterStateID URogueCharacterStateIdle::GetStateID()
{
	return ERogueCharacterStateID::Idle;
}

void URogueCharacterStateIdle::StateEnter(ERogueCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);
	Character->PlayAnimMontage(IdleMontage);
}

void URogueCharacterStateIdle::StateExit(ERogueCharacterStateID NextStateID)
{
	Super::StateExit(NextStateID);
}

void URogueCharacterStateIdle::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
}


