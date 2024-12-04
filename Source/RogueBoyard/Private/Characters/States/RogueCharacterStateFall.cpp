// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/States/RogueCharacterStateFall.h"

#include "Characters/RogueCharacter.h"
#include "Characters/RogueCharacterStateMachine.h"

ERogueCharacterStateID URogueCharacterStateFall::GetStateID()
{
	return ERogueCharacterStateID::Fall;
}

void URogueCharacterStateFall::StateEnter(ERogueCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);
	Character->PlayAnimMontage(FallMontage, true);
	Character->GetMesh()->SetWorldRotation(FRotator(0, 0, -90));
}

void URogueCharacterStateFall::StateExit(ERogueCharacterStateID NextStateID)
{
	Super::StateExit(NextStateID);
	FRotator rotator = Character->GetMesh()->GetRelativeRotation();
	Character->GetMesh()->SetWorldRotation(FRotator(0, 0, 0));
}

