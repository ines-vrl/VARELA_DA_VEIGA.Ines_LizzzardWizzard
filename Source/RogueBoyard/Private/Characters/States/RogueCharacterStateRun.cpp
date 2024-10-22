// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueBoyard/Public/Characters/States/RogueCharacterStateRun.h"

#include "Characters/RogueCharacterStateMachine.h"
#include "GameFramework/CharacterMovementComponent.h"
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
	GEngine->AddOnScreenDebugMessage(
	-1,
	0.1f,
	FColor::Red,
	TEXT("Exit run")
);
}

void URogueCharacterStateRun::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
	if(FMath::Abs(Character->GetCharacterMovement()->Velocity.Length()) <= 0.f)
	{
		GEngine->AddOnScreenDebugMessage(
		-1,
		0.1f,
		FColor::Cyan,
		TEXT("Not Moving")
		);
		StateMachine->ChangeState(ERogueCharacterStateID::Idle);
	}
}
