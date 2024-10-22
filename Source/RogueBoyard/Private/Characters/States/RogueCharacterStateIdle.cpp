// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueBoyard/Public/Characters/States/RogueCharacterStateIdle.h"

#include "Characters/RogueCharacterStateMachine.h"
#include "GameFramework/CharacterMovementComponent.h"
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
	GEngine->AddOnScreenDebugMessage(
	-1,
	0.1f,
	FColor::Red,
	TEXT("Exit idle")
	);
}

void URogueCharacterStateIdle::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
	if(FMath::Abs(Character->GetCharacterMovement()->Velocity.Length()) > 0.f)
	{
		GEngine->AddOnScreenDebugMessage(
		-1,
		0.1f,
		FColor::Cyan,
		TEXT("Moving")
		);
		StateMachine->ChangeState(ERogueCharacterStateID::Run);
	}
}


