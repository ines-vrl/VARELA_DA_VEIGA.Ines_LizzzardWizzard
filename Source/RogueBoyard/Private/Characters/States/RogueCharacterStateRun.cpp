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
	GEngine->AddOnScreenDebugMessage(
	-1,
	2.f,
	FColor::Red,
	TEXT("enter run"));
	Character->GetMesh()->PlayAnimation(RunMontage, true);
}

void URogueCharacterStateRun::StateExit(ERogueCharacterStateID NextStateID)
{
	Super::StateExit(NextStateID);
	GEngine->AddOnScreenDebugMessage(
	-1,
	2.f,
	FColor::Red,
	TEXT("Exit run")
);
}

void URogueCharacterStateRun::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
	if(StateMachine->Sticks.X == 0 && StateMachine->Sticks.Y == 0)
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

void URogueCharacterStateRun::Movement(float X, float Y)
{
	Super::Movement(X, Y);
	Character->AddMovementInput(Character->GetActorRightVector(), X);
	Character->AddMovementInput(Character->GetActorForwardVector(), Y);
}

void URogueCharacterStateRun::Dash(float X, float Y)
{
	Super::Dash(X, Y);
}

TArray<AActor*> URogueCharacterStateRun::Interact()
{
	return Super::Interact();
}

void URogueCharacterStateRun::Push(TArray<AActor*> Actors)
{
	Super::Push(Actors);
	StateMachine->ChangeState(ERogueCharacterStateID::Pushing);
}
