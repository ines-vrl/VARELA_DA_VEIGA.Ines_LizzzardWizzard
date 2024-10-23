// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueBoyard/Public/Characters/States/RogueCharacterStateDash.h"

#include "Characters/RogueCharacterStateMachine.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "RogueBoyard/Public/Characters/RogueCharacter.h"


ERogueCharacterStateID URogueCharacterStateDash::GetStateID()
{
	return ERogueCharacterStateID::Dash;
}

void URogueCharacterStateDash::StateEnter(ERogueCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);
	Sticks = StateMachine->Sticks;
	Character->GetCharacterMovement()->AddImpulse(StateMachine->Sticks * ForceImpulse);
	Character->GetMesh()->PlayAnimation(DashMontage, false);
	if(DashMontage) DashAnimTimeRemaining = DashMontage->GetPlayLength();
}

void URogueCharacterStateDash::StateExit(ERogueCharacterStateID NextStateID)
{
	Super::StateExit(NextStateID);
	GEngine->AddOnScreenDebugMessage(
	-1,
	2.f,
	FColor::Red,
	TEXT("Exit dash")
);
}

void URogueCharacterStateDash::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
	DashAnimTimeRemaining -= DeltaTime;
	GEngine->AddOnScreenDebugMessage(
	-1,
	2.f,
	FColor::Green,
	TEXT("tick dash")
	);
	Sticks = StateMachine->Sticks;
	if(DashAnimTimeRemaining <= 0)
	{
		if(Sticks.Length() != 0)
		{
			StateMachine->ChangeState(ERogueCharacterStateID::Run);
		}
		else
		{
			StateMachine->ChangeState(ERogueCharacterStateID::Idle);
		}
	}
}
