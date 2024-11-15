// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/States/RogueCharacterStatePushed.h"

#include "Characters/RogueCharacter.h"
#include "Characters/RogueCharacterStateMachine.h"

ERogueCharacterStateID URogueCharacterStatePushed::GetStateID()
{
	return ERogueCharacterStateID::Pushed;
}

void URogueCharacterStatePushed::StateEnter(ERogueCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);
	Character->OnCharacterPushedEvent.Broadcast();
	Character->GetMesh()->PlayAnimation(PushedMontage, false);
}

void URogueCharacterStatePushed::StateExit(ERogueCharacterStateID NextStateID)
{
	Super::StateExit(NextStateID);
}

void URogueCharacterStatePushed::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
	if(Character->GetVelocity().Length() == 0)
	{
		StateMachine->ChangeState(ERogueCharacterStateID::Idle);
	}
}
