// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueBoyard/Public/Characters/States/RogueCharacterStateDash.h"

#include "RogueBoyard/Public/Characters/RogueCharacter.h"


ERogueCharacterStateID URogueCharacterStateDash::GetStateID()
{
	return ERogueCharacterStateID::Dash;
}

void URogueCharacterStateDash::StateEnter(ERogueCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);
	Character->PlayAnimMontage(DashMontage);
}

void URogueCharacterStateDash::StateExit(ERogueCharacterStateID NextStateID)
{
	Super::StateExit(NextStateID);
}

void URogueCharacterStateDash::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
}
