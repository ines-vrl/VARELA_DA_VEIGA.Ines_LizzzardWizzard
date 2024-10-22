// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueBoyard/Public/Characters/States/RogueCharacterStateRun.h"

#include "RogueBoyard/Public/Characters/RogueCharacter.h"


ERogueCharacterStateID URogueCharacterStateRun::GetStateID()
{
	return ERogueCharacterStateID::Run;
}

void URogueCharacterStateRun::StateEnter(ERogueCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);
	Character->PlayAnimMontage(RunMontage);
}

void URogueCharacterStateRun::StateExit(ERogueCharacterStateID NextStateID)
{
	Super::StateExit(NextStateID);
}

void URogueCharacterStateRun::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
}
